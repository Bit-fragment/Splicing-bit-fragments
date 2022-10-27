package cn.wh.mode.service.impl;

import cn.hutool.core.io.FileUtil;
import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.Fileil;
import cn.wh.mode.service.FileilService;
import cn.wh.mode.mapper.FileilMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.File;
import java.text.DateFormat;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.List;

/**
 * @author XMZR
 * @description 针对表【fileil(文件表)】的数据库操作Service实现
 * @createDate 2022-05-30 10:15:52
 */
@Service
public class FileilServiceImpl extends ServiceImpl<FileilMapper, Fileil> implements FileilService {

    @Resource
    FileilMapper fileilMapper;

    /**
     * 添加Fileil
     */
    @Override
    public void addFileil(File[] files) {
        if (files.length<=0)return;
        for (File file : files) {
            Fileil fileil = new Fileil();
            fileil.setFileUrl(String.valueOf(FileUtil.getParent(file, 0)));//获取指定层级的父路径
            fileil.setFileName(FileUtil.mainName(file));//获取文件名,不带扩展名
            fileil.setFileSuffix(FileUtil.extName(file));//获取文件扩展名（后缀名）,扩展名不带“.”
            fileil.setFileSize(FileUtil.size(file, false));//计算目录或文件的总大小 当给定对象为文件时，直接调用 File.length() 当给定对象为目录时，遍历目录下的所有文件和目录，递归计算其大小，求和返回
            System.out.print(fileilMapper.insert(fileil) == 1);
        }
    }

    /**
     * 删除File
     */
    @Override
    public Boolean deleteFileil(Fileil fileil) {
        if (null == fileil.getId()) return false;
        return fileilMapper.deleteById(fileil.getId()) == 1;
    }

    /**
     * 更新Fileil信息
     */
    @Override
    public Boolean updateFileil(Fileil fileil) {
        if (null == fileil.getId()) return false;
        return fileilMapper.updateById(fileil) == 1;
    }

    /**
     * 根据id获取Fileil对象
     */
    @Override
    public Fileil selectFileil(Integer fileilId) {
        if (null == fileilId) return null;
        return fileilMapper.getAllByIdFileil(fileilId);
    }

    /**
     * 获取所有未删除的Fileil
     */
    @Override
    public List<Fileil> getAllFileil() {
        return fileilMapper.getAllFile();
    }

}




