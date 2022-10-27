package cn.wh.mode.service.impl;

import cn.hutool.core.date.DateTime;
import cn.hutool.core.io.FileUtil;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.User;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.Article;
import cn.wh.mode.service.ArticleService;
import cn.wh.mode.mapper.ArticleMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.File;
import java.nio.charset.StandardCharsets;
import java.util.Map;

import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;
import static cn.wh.webmode.config.UsualConfig.TxtResources;

/**
 * @author wenhaoWork
 * @description 针对表【article】的数据库操作Service实现
 * @createDate 2022-06-30 13:45:49
 */
@Service
public class ArticleServiceImpl extends ServiceImpl<ArticleMapper, Article>
        implements ArticleService {
    @Resource
    ArticleMapper articleMapper;
    @Resource
    UserMapper userMapper;

    /**
     * 添加一篇文章
     */
    @Override
    public Boolean addArticle(Map<String, String> map, User user) {
        String body = map.get("body");//文章内容
        String title = map.get("title");//文章标题
        String synopsis = map.get("synopsis");//文章简介
        String visibility = map.get("visibility");//设置的权限(谁可看)

        File file = FileUtil.file(StringResourceDirectory + TxtResources + user.getId() + "_" + user.getAccount() + "\\" + System.currentTimeMillis() + "_" + title + ".txt");
        FileUtil.writeString(body, file, StandardCharsets.UTF_8);

        Article article = new Article();
        article.setArticleTitle(title);//设置文章标题
        article.setArticleSynopsis(synopsis);//设置文章简介
        article.setTxtUrl(file.getPath());//设置文章文件路径
        article.setUserId(user.getId());//设置作者id
        article.setIssuingTime(DateTime.now());//设置保存时间
        article.setUpdateTime(DateTime.now());//设置最后更新时间

        //可浏览此文章的用户类型(0全可/1会员/2登录可见/3仅自己可见)
        switch (visibility) {
            case "所有人可见":
                article.setUserType(0);
            case "仅VIP可见":
                article.setUserType(1);
            case "仅登录可见":
                article.setUserType(2);
            case "仅自己可见":
                article.setUserType(3);
            default:
                article.setUserType(3);
        }

        return articleMapper.insert(article) == 1;
    }
}




