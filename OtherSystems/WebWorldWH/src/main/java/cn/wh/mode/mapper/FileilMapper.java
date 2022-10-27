package cn.wh.mode.mapper;

import cn.wh.mode.pojo.Fileil;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
* @author XMZR
* @description 针对表【fileil(文件表)】的数据库操作Mapper
* @createDate 2022-05-30 10:15:52
* @Entity cn.wh.mode.pojo.Fileil
*/
public interface FileilMapper extends BaseMapper<Fileil> {

    /**获取所有未删除的Fileil*/
   List<Fileil> getAllFile();

   /**根据id获取Fileil对象*/
   Fileil getAllByIdFileil(@Param("id") Integer id);

}




