package cn.wh.webmode.Conterler;

import cn.hutool.core.io.FileUtil;
import cn.wh.mode.mapper.ArticleMapper;
import cn.wh.mode.mapper.CommentMapper;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.Article;
import cn.wh.mode.pojo.Comment;
import cn.wh.mode.pojo.User;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.Resource;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

@Controller
@RequestMapping(value = "/article")
public class ArticlePageConterler {
    @Resource
    ArticleMapper articleMapper;
    @Resource
    CommentMapper commentMapper;
    @Resource
    UserMapper userMapper;

    /**
     * 模拟评论数据
     */
    static List<Map<String, Object>> getCommentMode(int p) {
        List<Map<String, Object>> list = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            Map<String, Object> map = new HashMap<>();
            Map<String, String> map1 = new HashMap<String, String>();
            Map<String, String> map2 = new HashMap<String, String>();
            map.put("Id", i);

            map1.put("name", "发布者昵称" + i);
            map1.put("email", "发布者email" + i);
            map1.put("imgUrl", "发布者头像路径" + i);
            map.put("CommentBy", map1);

            map2.put("name", "被@者昵称" + i);
            map2.put("email", "被@者email" + i);
            map2.put("imgUrl", "被@者头像路径" + i);
            map.put("Reviewed", map2);

            map.put("ArticleId", "评论所属的文章id");
            map.put("CommentId", "回复的评论id");
            map.put("Comments", "评论内容" + i);
            map.put("likeNumber", "646542");
            map.put("CommentTime", "评论时间");

            list.add(map);
        }
        return list;
    }

    /**
     * 模拟文章数据
     */
    static List<Map<String, Object>> getArticleMode(int p) {
        List<Map<String, Object>> list = new ArrayList<>();
        for (int i = 0; i < p; i++) {
            Map<String, Object> map = new HashMap<>();
            map.put("id", i);
            map.put("title", "文章标题" + i);
            map.put("perhaps", "大概内容" + i);
            map.put("username", "作者昵称" + i);
            map.put("issuingTime", "文章发表时间");
            map.put("imgUrl", "文章中的图片路径");
            map.put("likeNumber", "646542");//点赞数
            map.put("favoritesNumber", "1313");//收藏数
            map.put("commentsNumber", "32132");//评论数
            list.add(map);
        }
        return list;
    }

    @RequestMapping("/getArticleList")
    @ResponseBody//获取指定数量的文章集合
    public List<Map<String, Object>> getArticleList(@RequestBody Map<String, String> data) {
        Integer p = Integer.valueOf(data.get("CurrentPage"));//第几页
        System.out.println(p);
        Integer n = p * 10;// = p*10
        Integer m = n - 10; // = n-10
        List<Article> list1 = new ArrayList<>();
        for (int i = m; i < n; i++) {
            list1 = articleMapper.getArticleListById(m, n);
        }
        List<Map<String, Object>> list = new ArrayList<>();
        for (int i = list1.size() - 1; i >= 0; i--) {
            Article article = list1.get(i);
            Map<String, Object> map = new HashMap<>();
            map.put("id", article.getId());
            map.put("title", article.getArticleTitle());
            map.put("synopsis", article.getArticleSynopsis());
            map.put("username", userMapper.selectById(article.getUserId()).getUsername());
            map.put("issuingTime", article.getIssuingTime());
            map.put("imgUrl", "文章中的图片路径");
            map.put("likeNumber", article.getLikeNumber());//点赞数
            map.put("favoritesNumber", article.getFavoritesNumber());//收藏数
            map.put("commentsNumber", article.getCommentsNumber());//评论数
            list.add(map);
        }
        return list;
    }

    @RequestMapping("/getReviews")
    @ResponseBody//获取指定文章的评论集合
    public Map<String, Object> getReviews(@RequestBody Map<String, String> data) {
        Integer p = Integer.valueOf(data.get("CurrentPage"));//第几页
        Long id = Long.valueOf(data.get("ArticleId"));//文章id
        System.out.println("CurrentPage:" + p + "   ArticleId:" + id);
        Integer n = p * 10;// = p*10
        Integer m = n - 10; // = n-10
        List<Comment> list1 = new ArrayList<>();
        for (int i = m; i < n; i++) {
            list1 = commentMapper.getCommentListById(id, m, n);
        }
        List<Map<String, Object>> list = new ArrayList<>();

        for (int i = list1.size() - 1; i >= 0; i--) {
            Comment comment = list1.get(i);
            Map<String, Object> map = new HashMap<>();
            Map<String, String> map1 = new HashMap<String, String>();
            Map<String, String> map2 = new HashMap<String, String>();
            map.put("Id", comment.getId());

            User user = userMapper.selectById(comment.getUserId());
            map1.put("name", user.getUsername());
            map1.put("email", user.getAccount());
            map1.put("imgUrl", "http://127.0.0.1:8080/imgs/tu1.png");
            map.put("CommentBy", map1);

            map.put("ArticleId", comment.getArticleId());
            map.put("CommentId", comment.getCommentId());
            map.put("Comments", comment.getComments());
            map.put("likeNumber", comment.getLikeNumber());
            map.put("CommentTime", comment.getIssuingTime());

            User user1 = userMapper.selectById(comment.getObjectId());
            if (null != user1) {
                map2.put("name", user1.getUsername());
                map2.put("email", user1.getAccount());
                map2.put("imgUrl", "https://cube.elemecdn.com/0/88/03b0d39583f48206768a7534e55bcpng.png");
                map.put("Reviewed", map2);
            }
            map2.put("name", " ");
            map2.put("email", "");
            map2.put("imgUrl", "https://cube.elemecdn.com/0/88/03b0d39583f48206768a7534e55bcpng.png");
            map.put("Reviewed", map2);
            list.add(map);
        }
        Map<String, Object> response = new HashMap<>();
        response.put("datas", list);
        if (list.size() == 0) {
            response.put("code", false);
        } else {
            response.put("code", true);
        }
        //List<Map<String, Object>>
        return response;
    }

    @RequestMapping("/getArticle")
    @ResponseBody//获取指定id的文章
    public Map<String, Object> getArticle(@RequestBody Map<String, String> data) {
        String id = data.get("ArticleId");
        Article article = articleMapper.getArticleById(Long.valueOf(id));
        Map<String, Object> map = new HashMap<>();
        if (null == article) {
            map.put("title", "文章不存在");
        }
        assert article != null;
        String articlePath = article.getTxtUrl();
        map.put("id", article.getId());
        map.put("title", article.getArticleTitle());
        map.put("synopsis", article.getArticleSynopsis());
        map.put("body", FileUtil.readUtf8String(articlePath));
        map.put("username", userMapper.selectById(article.getUserId()).getUsername());
        map.put("issuingTime", article.getIssuingTime());
        map.put("imgUrl", "文章中的图片路径");
        map.put("likeNumber", article.getLikeNumber());//点赞数
        map.put("favoritesNumber", article.getFavoritesNumber());//收藏数
        map.put("commentsNumber", article.getCommentsNumber());//评论数
        return map;
    }


}
