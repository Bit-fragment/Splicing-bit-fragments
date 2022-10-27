package cn.wh.webmode.Conterler.ThreadPoolConterlerTest;

import cn.wh.webmode.Conterler.ThreadPoolConterlerTest.ThreadPackge.CustomThreadPool;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.ArrayList;

@Controller
@RequestMapping(value = "/threadpool")
public class Conterler {

    //@Resource（java注解）默认按名称方式进行bean匹配。
    @Resource
    CustomThreadPool threadPool;

    //@Autowired（spring注解）默认按类型方式进行bean匹配。
    @Autowired()
    @Qualifier("sessionlist")
    ArrayList<HttpSession> sessionlist;

    //使用构造函数注入(@Autowired的推荐用法)
    private UserServicePool userService;
    @Autowired
    public void userService1(UserServicePool userService) {
        this.userService = userService;
    }

    @RequestMapping("/run")
    @ResponseBody
    public void run(HttpServletRequest req) {
        Thread thread = new Thread() {
            @Override
            public void run() {
                userService.run("请求 " + req.getRequestURL() + " 执行 Conterler run");
            }
        };
        thread.setName(req.getRequestURI() + "任务");
        threadPool.execute(thread);
    }

    @RequestMapping("/run1")
    @ResponseBody
    public void run1(HttpServletRequest req) {
        Thread thread = new Thread() {
            @Override
            public void run() {
                userService.run1(new String[]{"任务1", "任务2", "任务3", "任务4", "任务5", "任务6", "任务7"});
            }
        };
        thread.setName(req.getRequestURI() + "任务");
        threadPool.execute(thread);
    }

    @RequestMapping("/run2")
    @ResponseBody
    public void run2(HttpServletRequest req, @RequestParam("name") Object obj) {
        req.getSession().setAttribute("name", obj.toString());
    }

    @RequestMapping("/run3")
    @ResponseBody
    public void run3() {
        System.out.println("当前的session数量: " + sessionlist.size());
        if (sessionlist.size() > 0) {
            for (Object o : sessionlist) {
                HttpSession ho = (HttpSession) o;
                System.out.println(ho.toString() + " " + ho.getAttributeNames() + " = " + ho.getAttribute("name"));
            }
        }

    }

}
