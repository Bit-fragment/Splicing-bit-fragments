package cn.wh.webmode.Conterler.demo1;


import org.junit.jupiter.api.Test;

import java.io.*;

/**
 * @description: java读取拆分大文件
 * @author: w*****
 * @date: 2021/4/8 18:51
 */
public class FileSplit {
    private static String fileName = "D://test//这个杀手不太冷.mp4";
    private static String outFile = "D://test//testout//这个杀手不太冷1.mp4";

    private static String outDir = "D://test//testout//";


    /**
     * 2G以上大文件读取
     *
     * @param inputFile, outputFile
     * @return void
     * @author wangguangle
     * @date: 2021/4/7 16:16
     */
    void largeFileIO(String inputFile, String outputFile) {
        try {
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(new File(inputFile)));
            // 10M缓存
            BufferedReader in = new BufferedReader(new InputStreamReader(bis, "utf-8"), 10 * 1024 * 1024);
            FileWriter fw = new FileWriter(outputFile);
            while (in.ready()) {
                String line = in.readLine();
                if (line.startsWith("INSERT")) {
                    fw.append(line + "\r");
                }
            }
            in.close();
            fw.flush();
            fw.close();
        } catch (IOException ex) {
            ex.printStackTrace();
        }
    }


    /**
     * 大文件拆分
     *
     * @param inputFile, outputFile
     * @return void
     * @author wangguangle
     * @date: 2021/4/8 16:19
     */
    void largeFileSplit(String inputFile, String outputDir) {
        int j = 0;
        try {
            File out = new File(outputDir);
            if (!out.exists()) {
                out.mkdirs();
            }
            BufferedInputStream bis = new BufferedInputStream(new FileInputStream(new File(inputFile)));
            // 20M缓存
            BufferedReader in = new BufferedReader(new InputStreamReader(bis, "utf-8"), 20 * 1024 * 1024);
            int i = 0;
            while (in.ready()) {
                long startTime = System.currentTimeMillis();
                ++i;
                FileWriter fw = new FileWriter(outputDir + i + ".mp4");
                String line = null;
                //50万行一个文件拆分
                for (long lineCounter = 0; lineCounter < 500000 && (line = in.readLine()) != null; ++lineCounter) {
                    if (line.startsWith("INSERT INTO `cur_rec` VALUES")) {
                        fw.append(line + "\r");
                        ++j;
                    }
                }
                fw.flush();
                fw.close();
                long endTime = System.currentTimeMillis();
                System.out.println("第" + i + "个文件拆分成功，耗时：" + (float) (endTime - startTime) / 1000 + "秒");
            }
            in.close();
        } catch (IOException ex) {
            System.out.println("第" + j + "行数据拆分异常\r" + ex);
            ex.printStackTrace();
        }
    }

    /**
     * 读取测试
     */
    @Test
    public void test1() {
        long startTime = System.currentTimeMillis();
        largeFileIO(fileName, outFile);
        long endTime = System.currentTimeMillis();
        System.out.println("读取文件成功，共耗时：" + (float) (endTime - startTime) / 1000 + "秒");
    }

    /**
     * 大文件拆分
     */
    @Test
    public void test2() {
        long startTime = System.currentTimeMillis();
        largeFileSplit(fileName, outDir);
        long endTime = System.currentTimeMillis();
        System.out.println("拆文件成功，共耗时：" + (float) (endTime - startTime) / 1000 + "秒");
    }

    /*
    实现非文本文件的复制
     */
    @Test
    public void BufferedStreamTest() throws FileNotFoundException {
        long start = System.currentTimeMillis();

        BufferedInputStream bis = null;
        BufferedOutputStream bos = null;

        try {
            //1.造文件
//            File srcFile = new File("D://test//JAVA编程思想第4版.pdf");
//            File destFile = new File("D://test//testout//JAVA编程思想第4版.pdf");
            File srcFile = new File("D://test//这个杀手不太冷.mp4");
            File destFile = new File("D://test//testout//这个杀手不太冷.mp4");
            //2.造流
            //2.1 造节点流
            FileInputStream fis = new FileInputStream((srcFile));
            FileOutputStream fos = new FileOutputStream(destFile);
            //2.2 造缓冲流
            bis = new BufferedInputStream(fis);
            bos = new BufferedOutputStream(fos);

            //3.复制的细节：读取、写入
            byte[] buffer = new byte[1024 * 200];
            int len;
            while ((len = bis.read(buffer)) != -1) {
                bos.write(buffer, 0, len);
                //bos.flush();//刷新缓冲区
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            //4.资源关闭
            //要求：先关闭外层的流，再关闭内层的流
            if (bos != null) {
                try {
                    bos.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
            if (bis != null) {
                try {
                    bis.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }

            }
            //说明：关闭外层流的同时，内层流也会自动的进行关闭。关于内层流的关闭，我们可以省略.
//        fos.close();
//        fis.close();
        }
        long end = System.currentTimeMillis();


        System.out.println("耗时:" + (end - start) + "毫秒");

    }


}
