package cn.wh.webmode.Conterler.AdminConterler;

import cn.hutool.core.io.FileUtil;
import cn.hutool.core.io.file.FileWriter;
import net.coobird.thumbnailator.Thumbnails;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.multipart.MultipartFile;

import java.io.File;
import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import static cn.wh.webmode.config.UsualConfig.ImgResources;
import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;

@Controller
@RequestMapping(value = "/admin/resour")
public class AdminConterlerForResources {
    @RequestMapping("/uploadInmgs")
    @ResponseBody
    public void uploadInmgs(
            @RequestPart(value = "file", required = false) MultipartFile multipartFile,
            @RequestPart(value = "type", required = false) String type,
            @RequestPart(value = "date", required = false) String date
    ) {
        try {
            //System.out.println(multipartFile.getOriginalFilename());//文件名 包括后缀名
            File file = new File(StringResourceDirectory + ImgResources + System.nanoTime() + multipartFile.getOriginalFilename());
            //FileUtil.writeFromStream(multipartFile.getInputStream(),file);
            multipartFile.transferTo(file);//将数据写入
            /**
             * 根据文件流的头部信息获得文件类型
             *       1、无法识别类型默认按照扩展名识别
             *       2、xls、doc、msi头信息无法区分，按照扩展名区分
             *       3、zip可能为docx、xlsx、pptx、jar、war头信息无法区分，按照扩展名区分
             * */
            //System.out.println(FileUtil.getType(file));
            File file1 = new File(StringResourceDirectory + ImgResources + "Thumbnail\\" + file.getName());
            Thumbnails.of(file)//压缩图片文件
                    .scale(1f) //图片大小（长宽）压缩比例 从0-1，1表示原图
                    .outputQuality(0.5f) //图片质量压缩比例 从0-1，越接近1质量越好
                    .toOutputStream(FileUtil.getOutputStream(file1));
        } catch (IOException e) {
            e.printStackTrace();
        }
        // System.out.println(type + date);
    }

    @RequestMapping("/uploadFile")
    @ResponseBody
    public void uploadFile(@RequestPart(value = "file", required = false) MultipartFile multipartFile) {
        try {
            File file = new File(StringResourceDirectory + System.nanoTime() + multipartFile.getOriginalFilename());
            multipartFile.transferTo(file);
            System.out.println(FileUtil.getType(file));
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    @RequestMapping("/getImgFileUrlList")
    @ResponseBody
    public Map<String, Object> getImgFileUrlList() {
        Map<String, Object> map = new HashMap<>();
        File[] files = FileUtil.ls(StringResourceDirectory + ImgResources + "Thumbnail\\");
        if (files.length == 0) {
            map.put("code", "1");
            return map;
        }
        String[] urlList = new String[files.length];
        for (int i = 0; i < files.length; i++) {
            urlList[i] = "Thumbnail\\" + files[i].getName();
        }
        map.put("code", "0");
        map.put("data", urlList);
        return map;
    }
}
