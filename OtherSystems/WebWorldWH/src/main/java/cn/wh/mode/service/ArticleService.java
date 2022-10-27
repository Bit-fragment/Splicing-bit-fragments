package cn.wh.mode.service;

import cn.wh.mode.pojo.Article;
import cn.wh.mode.pojo.User;
import com.baomidou.mybatisplus.extension.service.IService;

import java.util.Map;

/**
* @author wenhaoWork
* @description 针对表【article】的数据库操作Service
* @createDate 2022-06-30 13:45:49
*/
public interface ArticleService extends IService<Article> {
    /**添加一篇文章*/
    Boolean addArticle(Map<String,String> map, User user);
}
