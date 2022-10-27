package cn.wh.mode.mapper;

import cn.wh.mode.pojo.ConfigTable;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Param;

/**
* @author 20106
* @description 针对表【config_table(配置信息表)】的数据库操作Mapper
* @createDate 2022-10-27 15:27:43
* @Entity cn.wh.mode.pojo.ConfigTable
*/
public interface ConfigTableMapper extends BaseMapper<ConfigTable> {
    int addConfig(@Param("key") String key,@Param("value") String value);
}




