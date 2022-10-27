package cn.wh.webmode.interceptor;

import cn.hutool.json.JSONUtil;
import cn.wh.mode.pojo.User;
import org.springframework.stereotype.Component;
import org.springframework.web.servlet.HandlerInterceptor;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.util.HashMap;

@Component
public class UserInterceptor implements HandlerInterceptor {
    @Override
    public boolean preHandle(HttpServletRequest request, HttpServletResponse response, Object handler) throws Exception {
        System.out.println("前置拦截器1 preHandle:(是否登录验证)请求的uri为：" + request.getRequestURL());
        User user = (User) request.getSession().getAttribute("user");
        System.out.println("UserInterceptor -->" + user);
        if (null != user) {
            return true;
        } else {
            response.setCharacterEncoding("UTF-8");
            final HashMap<String, String> map = new HashMap<>();
            map.put("code","0");
            final String s = JSONUtil.toJsonStr(map);
            response.getWriter().println(s);
            return false;
        }

    }

    @Override
    public void postHandle(HttpServletRequest request, HttpServletResponse response, Object handler, ModelAndView modelAndView) throws Exception {
        System.out.println("------postHandle------" + request.getRequestURI());
        HandlerInterceptor.super.postHandle(request, response, handler, modelAndView);
    }

    @Override
    public void afterCompletion(HttpServletRequest request, HttpServletResponse response, Object handler, Exception ex) throws Exception {
        System.out.println("------afterCompletion------" + request.getRequestURI());
        HandlerInterceptor.super.afterCompletion(request, response, handler, ex);
    }
}
