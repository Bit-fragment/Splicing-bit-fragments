package cn.wh.webmode.Listener;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.beans.factory.annotation.Qualifier;
import org.springframework.stereotype.Component;

import javax.servlet.http.HttpSession;
import javax.servlet.http.HttpSessionEvent;
import javax.servlet.http.HttpSessionListener;
import java.util.ArrayList;

@Component//监听session域
public class HttpListener implements HttpSessionListener {

    @Autowired
    @Qualifier("sessionlist")
    ArrayList<HttpSession> sessionlist;

    @Override
    public void sessionCreated(HttpSessionEvent se) {
        sessionlist.add(se.getSession());

        System.out.println("有一个seesion创建,当前session的数量为"+sessionlist.size()+"个");
        HttpSessionListener.super.sessionCreated(se);
    }

    @Override
    public void sessionDestroyed(HttpSessionEvent se) {
        sessionlist.removeIf(session -> session.getId().equals(se.getSession().getId()));
        /*这是作者本来的写法(session设为无效后 无法.getxxx、会出现报错)，上面是idea建议的写法(可以解决作者写法出现的问题20220328)
        for (HttpSession session : sessionlist) {
            if (session.getId().equals(se.getSession().getId()))sessionlist.remove(session);
        }*/
        System.out.println("有一个seesion销毁,当前session的数量为"+sessionlist.size()+"个");
        HttpSessionListener.super.sessionDestroyed(se);
    }
}
