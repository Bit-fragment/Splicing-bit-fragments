package cn.wh.webmode.service.impl;

import cn.hutool.core.io.FileUtil;
import cn.wh.mode.mapper.MovieMapper;
import cn.wh.mode.pojo.Movie;
import cn.wh.webmode.service.FileOperationCurrency;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import java.io.File;

@Service
public class FileOperationCurrencyImpl implements FileOperationCurrency {
    @Resource
    MovieMapper movieMapper;




}
