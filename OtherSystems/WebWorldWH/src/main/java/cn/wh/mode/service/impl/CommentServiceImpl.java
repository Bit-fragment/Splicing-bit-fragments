package cn.wh.mode.service.impl;

import cn.hutool.core.date.DateTime;
import cn.wh.mode.mapper.ArticleMapper;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.Article;
import cn.wh.mode.pojo.User;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.Comment;
import cn.wh.mode.service.CommentService;
import cn.wh.mode.mapper.CommentMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.util.Map;

/**
 * @author XMZR
 * @description 针对表【comment】的数据库操作Service实现
 * @createDate 2022-06-04 18:27:13
 */
@Service
public class CommentServiceImpl extends ServiceImpl<CommentMapper, Comment>
        implements CommentService {
    @Resource
    ArticleMapper articleMapper;
    @Resource
    CommentMapper commentMapper;
    @Resource
    UserMapper userMapper;

    /**
     * 发表评论
     */
    public Boolean addComment(Map<String, String> data, User user) {
        Long ArticleId = Long.valueOf(data.get("id"));//回复的文章id
        String body = data.get("body");//回复的内容
        articleMapper.selectID(ArticleId);//判断文章是否存在
        Article article = articleMapper.selectById(ArticleId);
        User user1 = userMapper.selectById(user);
        if (null == article) return false;
        Comment comment = new Comment();
        comment.setUserId(user1.getId());//确定评论发表者
        comment.setArticleId(article.getId());//设置所属文章id
        comment.setComments(body);//设置评论内容
        comment.setIssuingTime(DateTime.now());//设置发表的时间
        if (commentMapper.insert(comment) == 1) {
            articleMapper.updateCommentsNumber(ArticleId);
            return true;
        }
        return false;
    }
}




