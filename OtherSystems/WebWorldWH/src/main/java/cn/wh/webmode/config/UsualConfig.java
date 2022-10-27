package cn.wh.webmode.config;

import cn.hutool.core.io.FileUtil;
import org.springframework.context.annotation.Configuration;

@Configuration
public class UsualConfig {

    public static final String StringResourceDirectory;//资源主目录
    public static final String VideoResources;//视频目录
    public static final String ImgResources;//图片目录
    public static final String TxtResources;//文章目录
    public static final String FileResources;//可下载下载文件目录

    public static final String configcnf;//配置文件目录

    static {
        String HomeUrl = FileUtil.getUserHomePath();
        StringResourceDirectory = HomeUrl + "\\resource\\";//资源主目录
        VideoResources = "\\VideoResources\\";//视频目录
        ImgResources = "\\ImgResources\\";//图片目录
        TxtResources = "\\TxtResources\\";//文章目录
        FileResources = "\\FileResources\\";//可下载下载文件目录
        configcnf = StringResourceDirectory + "\\config.cnf";
    }
}
