package cn.wh.webmode.config;

import cn.hutool.core.io.FileUtil;
import cn.wh.webmode.Conterler.ThreadPoolConterlerTest.ThreadPackge.CustomThreadPool;
import cn.wh.webmode.Conterler.ThreadPoolConterlerTest.ThreadPackge.ThreadFactorys;
import cn.wh.webmode.Filter.UserFilter;
import cn.wh.webmode.interceptor.UserInterceptor;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.web.servlet.FilterRegistrationBean;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import org.springframework.context.annotation.Scope;
import org.springframework.web.servlet.config.annotation.CorsRegistry;
import org.springframework.web.servlet.config.annotation.InterceptorRegistry;
import org.springframework.web.servlet.config.annotation.ResourceHandlerRegistry;
import org.springframework.web.servlet.config.annotation.WebMvcConfigurer;

import javax.servlet.http.HttpSession;
import java.io.File;
import java.util.ArrayList;
import java.util.concurrent.ArrayBlockingQueue;
import java.util.concurrent.ThreadPoolExecutor;
import java.util.concurrent.TimeUnit;

import static cn.wh.webmode.config.UsualConfig.ImgResources;
import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;

@Configuration
public class MyMvcConfig implements WebMvcConfigurer {

    @Autowired
    UserInterceptor userInterceptor;

    //存放session的集合
    @Bean(value = "sessionlist")
    @Scope("singleton")
    public ArrayList<HttpSession> SessionList() {
        ArrayList<HttpSession> SessionList = new ArrayList<>();
        return SessionList;
    }

    @Override
    public void addResourceHandlers(ResourceHandlerRegistry registry) {
        registry.addResourceHandler("/imgs/**").addResourceLocations("file:///" + StringResourceDirectory + ImgResources);
    }

    //自定义线程池
    @Bean()
    public CustomThreadPool getCustomThreadPool() {
        CustomThreadPool bean = new CustomThreadPool(
                5, 5, 10, TimeUnit.SECONDS,
                new ArrayBlockingQueue<>(100),
                new ThreadFactorys(),
                new ThreadPoolExecutor.DiscardPolicy()//饱和策略
        );
        return bean;
    }

    //自定义过滤器
    @Bean
    public FilterRegistrationBean getFilterRegistrationBean() {
        FilterRegistrationBean bean = new FilterRegistrationBean(new UserFilter());
        //bean.addUrlPatterns(new String[] {"*.do","*.jsp"});
        bean.addUrlPatterns("/user/he");
        return bean;
    }

    //自定义拦截器
    @Override
    public void addInterceptors(InterceptorRegistry registry) {
        registry.addInterceptor(userInterceptor)//注册自定义拦截器
                .addPathPatterns("/user/he")//设置拦截路径
                .excludePathPatterns("/user/singinuser")//设置不拦截路劲
                .excludePathPatterns("/user/singinuserx")
                .excludePathPatterns("/file/*")
                .excludePathPatterns("/user/singin").excludePathPatterns("/user/login");
    }

    //springboot内置解决跨域
    @Override
    public void addCorsMappings(CorsRegistry registry) {
        registry.addMapping("/**")
                //是否发送Cookie
                .allowCredentials(true)
                //设置放行哪些原始域   SpringBoot2.4.4下低版本使用.allowedOrigins("*")
                .allowedOriginPatterns("*")
                //放行哪些请求方式
                .allowedMethods("GET", "POST", "PUT", "DELETE")
                //.allowedMethods("*") //或者放行全部
                //放行哪些原始请求头部信息
                .allowedHeaders("*")
                //暴露哪些原始请求头部信息
                .exposedHeaders("*")
                .maxAge(3600);
    }

}
