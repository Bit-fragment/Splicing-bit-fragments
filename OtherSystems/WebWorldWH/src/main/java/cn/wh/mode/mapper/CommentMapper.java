package cn.wh.mode.mapper;

import cn.wh.mode.pojo.Article;
import cn.wh.mode.pojo.Comment;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
 * @author XMZR
 * @description 针对表【comment】的数据库操作Mapper
 * @createDate 2022-06-04 18:27:13
 * @Entity cn.wh.mode.pojo.Comment
 */
public interface CommentMapper extends BaseMapper<Comment> {
    /**
     * 获取指定id的文章第m到n个评论对象
     */
    List<Comment> getCommentListById(@Param("id") Long id, @Param("m") Integer m, @Param("n") Integer n);
}




