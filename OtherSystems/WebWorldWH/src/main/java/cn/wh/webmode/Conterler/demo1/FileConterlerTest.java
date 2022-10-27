package cn.wh.webmode.Conterler.demo1;

import cn.hutool.core.io.FileUtil;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

import static cn.wh.webmode.config.UsualConfig.*;


@Controller
@RequestMapping(value = "/file")
public class FileConterlerTest {
    @Autowired
    FileService fileService;

    //path为本地文件路劲
    @RequestMapping(value = "/play")
    @ResponseBody
    public void play(HttpServletRequest req, HttpServletResponse resp) {
        System.out.println("/file/play");
        fileService.play("C://Users//XMZR//Desktop//vuefile//vueworld//src//pdf//test.mp4", req, resp);
//        fileService.play("M://movie//这个杀手不太冷.mp4",req,resp);
    }

    @RequestMapping("/getVideo")
    public void getVideo(
            HttpServletRequest request, HttpServletResponse response,
            @RequestParam(value = "name") String fileName) {
        fileName = StringResourceDirectory + VideoResources + fileName;
        System.out.println(fileName);
        //视频资源存储信息
        response.reset();
        //获取从那个字节开始读取文件
        String rangeString = request.getHeader("Range");
//        log.info("getVideo获取视频资源:{},读取文件字节:{}",fileName,rangeString);
        System.out.println("getVideo获取视频资源:{" + fileName + "},读取文件字节:{" + rangeString + "}");
        try {
            //获取响应的输出流
            OutputStream outputStream = response.getOutputStream();
            File file = new File(fileName);
            if (file.exists()) {
                RandomAccessFile targetFile = new RandomAccessFile(file, "r");
                long fileLength = targetFile.length();
                //播放
                if (rangeString != null) {

                    long range = Long.parseLong(rangeString.substring(rangeString.indexOf("=") + 1, rangeString.indexOf("-")));
                    //设置内容类型
                    response.setHeader("Content-Type", "video/mov");
                    //设置此次相应返回的数据长度
                    response.setHeader("Content-Length", String.valueOf(fileLength - range));
                    //设置此次相应返回的数据范围
                    response.setHeader("Content-Range", "bytes " + range + "-" + (fileLength - 1) + "/" + fileLength);
                    //返回码需要为206，而不是200
                    response.setStatus(HttpServletResponse.SC_PARTIAL_CONTENT);
                    //设定文件读取开始位置（以字节为单位）
                    targetFile.seek(range);
                } else {//下载

                    //设置响应头，把文件名字设置好
                    response.setHeader("Content-Disposition", "attachment; filename=" + fileName);
                    //设置文件长度
                    response.setHeader("Content-Length", String.valueOf(fileLength));
                    //解决编码问题
                    response.setHeader("Content-Type", "application/octet-stream");
                }

                byte[] cache = new byte[1024 * 300];
                int flag;
                while ((flag = targetFile.read(cache)) != -1) {
                    outputStream.write(cache, 0, flag);
                }
            } else {
                String message = "file:" + fileName + " not exists";
                //解决编码问题
                response.setHeader("Content-Type", "application/json");
                outputStream.write(message.getBytes(StandardCharsets.UTF_8));
            }

            outputStream.flush();
            outputStream.close();

        } catch (FileNotFoundException e) {

        } catch (IOException e) {

        }
    }

    @RequestMapping(value = "/mp4src")
    @ResponseBody
    public List<String> filelist() {
        List<String> list = new ArrayList<String>();
        File file = new File(StringResourceDirectory + VideoResources);
        File[] files = file.listFiles();
        for (File file1 : files) {
            list.add("user/movie?videoPath=");
            list.add("http://127.0.0.1:8080/file/getVideo?name=" + file1.getName());
        }
        return list;
    }


    @GetMapping(value = "/xiazai/{fileName}")//文件下载
    public void logDownload(@PathVariable String fileName, HttpServletResponse response) throws Exception {
        File file = new File("M:\\MyResourceDirectory\\FileData\\" + fileName);
        if (!file.exists()) {
            throw new Exception(fileName + "文件不存在");
        }
        response.setContentType("application/force-download");
        response.addHeader("Content-Disposition", "attachment;fileName=" + fileName);
        byte[] buffer = new byte[1024];
        try (FileInputStream fis = new FileInputStream(file);
             BufferedInputStream bis = new BufferedInputStream(fis)) {
            OutputStream os = response.getOutputStream();
            int i = bis.read(buffer);
            while (i != -1) {
                os.write(buffer, 0, i);
                i = bis.read(buffer);
            }
        }
    }

    @PostMapping(value = "/getFileNameList")//文件下载
    @ResponseBody
    public List<String> getFileNameList() {
        File[] files = FileUtil.ls(StringResourceDirectory + FileResources);
        List<String> list = new ArrayList<>();
        for (File file : files) {
            list.add(file.getName());
        }
        return list;
    }

}
