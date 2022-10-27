package cn.wh.mode.mapper;

import cn.wh.mode.pojo.Article;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * @author wenhaoWork
 * @description 针对表【article】的数据库操作Mapper
 * @createDate 2022-06-30 13:45:49
 * @Entity cn.wh.mode.pojo.Article
 */
public interface ArticleMapper extends BaseMapper<Article> {
    /**
     * 根据id获取文章对象
     */
    Article getArticleById(@Param("id") Long id);

    /**
     * 获取第m到n个文章对象
     */
    List<Article> getArticleListById(@Param("m") Integer m, @Param("n") Integer n);

    /**
     * 判断指定id的文章是否存在
     */
    Integer selectID(@Param("id") Long id);

    /**
     * 文章评论数+1
     */
    Integer updateCommentsNumber(@Param("id") Long id);
}




