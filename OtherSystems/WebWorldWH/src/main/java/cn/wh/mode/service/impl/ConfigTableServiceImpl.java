package cn.wh.mode.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.ConfigTable;
import cn.wh.mode.service.ConfigTableService;
import cn.wh.mode.mapper.ConfigTableMapper;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;

/**
* @author 20106
* @description 针对表【config_table(配置信息表)】的数据库操作Service实现
* @createDate 2022-10-27 15:27:43
*/
@Service
public class ConfigTableServiceImpl extends ServiceImpl<ConfigTableMapper, ConfigTable>
    implements ConfigTableService{

    @Resource
    ConfigTableMapper configTableMapper;

    @Override
    public boolean addConfig(String key, String value) {
        ConfigTable config = new ConfigTable();
        config.setKey(key);
        config.setValue(value);
        return configTableMapper.insert(config) == 1;
    }
}




