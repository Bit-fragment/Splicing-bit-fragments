/*
package cn.wh;

import cn.hutool.core.date.DateTime;
import cn.hutool.core.date.DateUtil;
import cn.hutool.core.io.FileUtil;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.Fileil;
import cn.wh.mode.pojo.Movie;
import cn.wh.mode.service.impl.FileilServiceImpl;

import cn.wh.mode.service.UserService;
import cn.wh.mode.service.impl.MovieServiceImpl;
import cn.other.modeSE.cglibAgent.CostTimeProxy;
import cn.other.modeSE.cglibAgent.ServiceTest;
import cn.other.modeSE.cglibAgent.UserServiceAgent;
import cn.other.modeSE.springEvent.UserRegisterEvent;
import cn.wh.webmode.Listener.MyEvent;
import org.junit.jupiter.api.Test;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.test.context.SpringBootTest;
import org.springframework.context.ApplicationContext;
import org.springframework.context.event.ApplicationEventMulticaster;

import javax.annotation.Resource;
import java.io.File;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;
import static cn.wh.webmode.config.UsualConfig.TxtResources;

@SpringBootTest
class WebWorldWhApplicationTests {
    @Autowired
    ApplicationContext applicationContext;
    @Autowired
    UserService userService;

    @Resource
    MovieServiceImpl movieService;
    @Resource
    FileilServiceImpl fileilService;

    @Resource
    UserMapper userMapper;


    @Test
    void contextLoads() {
*/
/*        LOGGER.warn("WARN");
        LOGGER.error("error");
        LOGGER.info("info");//默认日志等级
        LOGGER.debug("debug");
        LOGGER.trace("trace");
        try {
            int sum = 5/0;
            System.out.println(sum);
        } catch (Exception e) {
            LOGGER.debug("报错",e);
        }
        String[] str = applicationContext.getBeanDefinitionNames();
        for (String string : str) {
            System.out.println("..." + string);
        }
        int balance = userService.ObUser("admin123");
        System.out.println(balance);*//*

//        DateTime dateTime = new DateTime();
//        System.out.println(DateTime.now());

        userMapper.selectById(null);
        System.out.println(userMapper.selectById(null));

    }

    @Test
    void test1() {
        */
/*UserRegisterService userRegisterService = applicationContext.getBean(UserRegisterService.class);
        //模拟用户注册
        userRegisterService.registerUser("路人甲Java");*//*

        ApplicationEventMulticaster app = applicationContext.getBean(ApplicationEventMulticaster.class);
        app.multicastEvent(new UserRegisterEvent(this, "wenhao"));
        */
/*userRegisterService.registerUser("wenhao");*//*


    }

    @Test
    void test2() {
        UserServiceAgent userServiceAgent = new UserServiceAgent();
        userServiceAgent.agent1();

        ServiceTest serviceTest = CostTimeProxy.createProxy(new ServiceTest());
        serviceTest.test1();
    }

    @Test
    void test3() {
        //springboot 监听器测试
        //发布事件
        applicationContext.publishEvent(new MyEvent("==测试事件=="));
    }

    @Test
    void test4() {
        Movie movie = new Movie();
        movie.setMovieName("测试name");
        movie.setMovieUrl("车市url");
        movie.setMovieSort("车时分类");
        System.out.println(movieService.addMovie(movie));
    }

    @Test
    void test5() {
        Date date = DateUtil.date();//当前时间
        Date date2 = DateUtil.date(Calendar.getInstance());//当前时间
        Date date3 = DateUtil.date(System.currentTimeMillis());//当前时间
        String now = DateUtil.now();//当前时间字符串，格式：yyyy-MM-dd HH:mm:ss
        String today = DateUtil.today();//当前日期字符串，格式：yyyy-MM-dd

        System.out.println(date);
        System.out.println(date2);
        System.out.println(date3);
        System.out.println(now);
        System.out.println(today);
    }

    @Test
    void test6() {
*/
/*        File file = new File(StringResourceDirectory + VideoResources + "\\test.txt");
        File file1 = new File(StringResourceDirectory + VideoResources + "\\jiami");
        System.out.println(file1.getName());
        System.out.println(file1.exists());
        System.out.println(file.getPath());*//*

        System.out.println("nihao1");
        System.out.println(movieService.setMovieFileOfData(new File("M:\\movie")));
        System.out.println();
    }

    @Test
    void test7() {
//        File file = new File("M:\\movie\\这个杀手不太冷.mp4");
//        System.out.println(file.getPath());
//        System.out.println(FileUtil.mainName(file));
//        System.out.println(FileUtil.getParent(file,1));
//        DateFormat dateFormat1 = new SimpleDateFormat("yyyy-MM-dd");
//        Date date = null;
//        try {
//            date = dateFormat1.parse("2022-05-01");
//        } catch (ParseException e) {
//            e.printStackTrace();
//        }
//        System.out.println(date);
//        fileilService.addFileil(FileUtil.ls("M:\\movie"));

        for (Fileil fileil : fileilService.getAllFileil()) {
            System.out.println(fileil);
        }

    }

    @Test
    void test8() {
        File urlFile = FileUtil.touch(StringResourceDirectory + TxtResources);

        System.out.println(urlFile.getPath());
        String email = "50838.80.68@qq.com";

        String[] strlist = email.split("\\.");//不包含后缀名

        for (String s : strlist) {
            System.out.println(s);
        }


    }
    static boolean MailboxFormatCheck(String owner) {//邮箱格式判断
        if (null == owner) System.out.println("owner为null");
        String check = "\\w+([-+.]\\w+)* @ \\w+([-.]\\w+)* \\. \\w+([-.]\\w+)* ";

        String check1 = "\\w+([-+.]\\w+)* @ \\w+([-.]\\w+)* \\. \\w+([-.]\\w+)* ";
        Pattern regex = Pattern.compile(check);
        //是否匹配
        Matcher matcher = regex.matcher(owner);
        return matcher.matches();
    }

    @Test
    void shuru(){
        System.out.println(wenhao("1.2"));
    }

    static Boolean wenhao(String str){
        Pattern pattern = Pattern.compile("[0-9]*\\.?[0-9]+");
        Matcher isNum = pattern.matcher(str);
        return isNum.matches();
    }
}


*/
