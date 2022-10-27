package cn.wh.webmode.Conterler.demo1;

import org.junit.jupiter.api.Test;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.nio.ByteBuffer;
import java.nio.channels.FileChannel;
import java.nio.charset.StandardCharsets;

public class demo01 {
    @Test
    public void test1() throws Exception {
        //1.创建输出流
        FileOutputStream fos = new FileOutputStream("D://test//hello.txt");
        //2.通过流获取通道对象
        FileChannel fileChannel = fos.getChannel();
        //3.通过静态方法获取缓冲区
        ByteBuffer buffer = ByteBuffer.allocate(1024);
        //4.往缓冲区写数据
        buffer.put("hello,nio,world!".getBytes(StandardCharsets.UTF_8));
        //5.翻转缓冲区
        buffer.flip();
        //6.把缓冲区中的数据写入通道
        fileChannel.write(buffer);
        //7.关闭流，通道也会关闭
        fos.close();
    }

    @Test
    public void test2() throws Exception{
        File file = new File("D://test//hello.txt");
        //1.创建输入流
        //FileInputStream fis = new FileInputStream("D://test//hello.txt");
        FileInputStream fis = new FileInputStream(file);
        //2.获取通道
        FileChannel fileChannel = fis.getChannel();
        //3.创建缓冲区
        ByteBuffer buffer = ByteBuffer.allocate((int)file.length());
        //4.通道将读取数据并放入缓冲区
        fileChannel.read(buffer);
        //5.将缓冲区的数据输出在控制台
        System.out.println(new String(buffer.array()));
        //6.关闭流
        fis.close();
    }

    @Test
    public void test3() throws Exception{
        long ster = System.currentTimeMillis();
        //1.创建两个流
        FileInputStream fis = new FileInputStream("D://test//这个杀手不太冷.mp4");//输入流
        FileOutputStream fos = new FileOutputStream("D://test//testout//这个杀手不太冷1.mp4");//输出流

        //2.获取通道
        FileChannel fisFC = fis.getChannel();
        FileChannel fosFC = fos.getChannel();

        //3.一个通道从另一个通道复制文件
        fosFC.transferFrom(fisFC,0,fisFC.size());
        //3.1将本通道内的数据复制给另一个通道
        //fisFC.transferTo(0,fisFC.size(),fosFC);

        //4.关闭流
        fos.close();
        fis.close();
        long end = System.currentTimeMillis();
        System.out.println("耗时:"+(end-ster)+"毫秒");
    }
}
