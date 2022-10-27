package cn.wh.webmode.config;

import cn.hutool.core.io.FileUtil;
import cn.wh.mode.mapper.ArticleMapper;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.Article;
import cn.wh.webmode.Utils.RedisUtils;
import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.ApplicationArguments;
import org.springframework.boot.ApplicationRunner;
import org.springframework.core.annotation.Order;
import org.springframework.stereotype.Component;

import javax.annotation.Resource;
import java.io.File;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static cn.wh.webmode.config.UsualConfig.*;

/*容器启动后的各项初始化*/
@Order(1)//可以有多个初始化类，这个代表执行顺序
@Component
public class Initialization implements ApplicationRunner {
    @Resource
    ArticleMapper articleMapper;

    @Resource
    UserMapper userMapper;

    @Resource
    RedisUtils redisUtils;

    private static final Logger logger = LoggerFactory.getLogger(Initialization.class);

    static void fileInitialization(String fileUrl, String fileType) {
        File file = FileUtil.file(fileUrl);
        if (!FileUtil.exist(file)) {    //如果文件不存在
            if ("mkdir".equals(fileType)) {
                //创建文件夹
                FileUtil.mkdir(file);
            }
            if ("touch".equals(fileType)) {
                //创建文件
                FileUtil.touch(file);
            }
        }

    }

    @Override
    public void run(ApplicationArguments args) throws Exception {
        logger.info("开始初始化数据。。。。。");

        fileInitialization(StringResourceDirectory,"mkdir");
        fileInitialization(StringResourceDirectory+VideoResources,"mkdir");
        fileInitialization(StringResourceDirectory+ImgResources,"mkdir");
        fileInitialization(StringResourceDirectory+TxtResources,"mkdir");
        fileInitialization(StringResourceDirectory+FileResources,"mkdir");
        fileInitialization(configcnf,"touch");

        Integer p = 1;
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
        redisUtils.set("InitializedData", String.valueOf(list));
        logger.info("初始化数据完成。。。。。");

    }
}
