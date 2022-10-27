package cn.wh;

import org.mybatis.spring.annotation.MapperScan;
import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;

@SpringBootApplication
@MapperScan("cn.wh.mode.mapper")
public class WebWorldWhApplication {
    public static void main(String[] args) {
        SpringApplication.run(WebWorldWhApplication.class, args);
    }
}
