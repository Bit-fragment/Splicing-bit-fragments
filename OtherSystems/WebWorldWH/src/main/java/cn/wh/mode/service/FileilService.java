package cn.wh.mode.service;

import cn.wh.mode.pojo.Fileil;
import com.baomidou.mybatisplus.extension.service.IService;

import java.io.File;
import java.util.List;

/**
* @author XMZR
* @description 针对表【fileil(文件表)】的数据库操作Service
* @createDate 2022-05-30 10:15:52
*/
public interface FileilService extends IService<Fileil> {
    public void addFileil(File[] files);

    public Boolean deleteFileil(Fileil fileil);

    public Boolean updateFileil(Fileil fileil);

    public Fileil selectFileil(Integer fileilId);

    public List<Fileil> getAllFileil();
}
