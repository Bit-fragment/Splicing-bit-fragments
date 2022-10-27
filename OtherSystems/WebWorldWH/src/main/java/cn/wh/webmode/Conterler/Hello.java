package cn.wh.webmode.Conterler;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.boot.configurationprocessor.json.JSONObject;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.bind.annotation.RestController;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.util.ArrayList;


@RestController
public class Hello {

    private static final Logger logger = LoggerFactory.getLogger(Hello.class);
    @Autowired
    @Qualifier("sessionlist")
    ArrayList<HttpSession> sessionlist;
    @Autowired
    private AsyncService asyncService;

    @RequestMapping("/test1")
    @ResponseBody
    public String test1() {
        logger.info("进入Controller 开始执行Service层任务");
        //调用service层的任务
        asyncService.executeAsync();
        logger.info("退出Controller 执行完成Service层任务");
        return "成功";
    }

    @RequestMapping("/test2")
    @ResponseBody
    public String test2(
//            @RequestParam(value = "input") JSONObject value,
            HttpServletRequest req, HttpServletResponse resp) {

        if (null != req.getCookies()) {
            for (Cookie cookie : req.getCookies()) {
                System.out.println("name: " + cookie.getName() + " value: " + cookie.getValue());
            }
        } else {
            System.out.println("无cookie，放cookie");
            Cookie cookie = new Cookie("CookieName", "CookieValue");
            cookie.setMaxAge(-1);
            resp.addCookie(cookie);
        }

//        System.out.println("接收到的参数为:" + value);
        return "value.toString()";
    }

    @RequestMapping("/session")
    @ResponseBody
    public void sesssiontest(HttpServletRequest req) {

        System.out.println("当前请求:" + req.getRequestURL());
        if (null == req.getCookies()) {
            System.out.println("无Cookie");
        } else {
            for (Cookie cookie : req.getCookies()) {
                System.out.println("CookieName: " + cookie.getName() + " 最大存活时间: " + cookie.getMaxAge() + " CookieValue: " + cookie.getValue());
                //System.out.println("path: " + cookie.getPath()+" domain: "+cookie.getDomain());
            }
        }
        for (HttpSession o : sessionlist) {
            System.out.println("当前seesion的数量为: " + sessionlist.size() + "个: " + o.toString());
            System.out.println("创建时间: " + o.getCreationTime() + " 上次访问时间: " + o.getLastAccessedTime() + " 最大存活时间: " + o.getMaxInactiveInterval());
            System.out.println("SessionID: " + o.getId());
        }

    }
}