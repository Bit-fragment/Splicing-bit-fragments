package cn.wh.mode.service;

import cn.wh.mode.pojo.ConfigTable;
import com.baomidou.mybatisplus.extension.service.IService;

/**
* @author 20106
* @description 针对表【config_table(配置信息表)】的数据库操作Service
* @createDate 2022-10-27 15:27:43
*/
public interface ConfigTableService extends IService<ConfigTable> {
    public boolean addConfig(String key,String value);
}
