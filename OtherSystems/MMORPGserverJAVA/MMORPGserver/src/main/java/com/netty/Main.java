package com.netty;

import com.netty.configClass.ConfigBean;
import com.netty.gameObject.GameWorldObject;
import org.springframework.context.annotation.AnnotationConfigApplicationContext;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello world!");
        AnnotationConfigApplicationContext context = new AnnotationConfigApplicationContext(ConfigBean.class);
        for (String beanName : context.getBeanDefinitionNames()) {
            //别名
            String[] aliases = context.getAliases(beanName);
            System.out.println(aliases);
        }
        GameWorldObject gwo = (GameWorldObject) context.getBean("GameWorldObject");
        gwo.run();
        GameWorldObject gwo1 = (GameWorldObject) context.getBean("GameWorldObject");
        gwo1.run();




    }
}