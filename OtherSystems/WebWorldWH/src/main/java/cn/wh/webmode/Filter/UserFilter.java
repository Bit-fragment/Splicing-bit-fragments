package cn.wh.webmode.Filter;

import cn.wh.mode.pojo.User;
import javax.servlet.*;
import javax.servlet.http.HttpServletRequest;
import java.io.IOException;

public class UserFilter implements Filter {
    @Override
    public void init(FilterConfig filterConfig) throws ServletException {
        System.out.println("UserFilter init -->run");
        Filter.super.init(filterConfig);
    }

    @Override
    public void doFilter(ServletRequest request, ServletResponse response, FilterChain chain) throws IOException, ServletException {
        System.out.println("UserFilter doFilter -->run");
        HttpServletRequest request1 = (HttpServletRequest) request;
        User user = (User) request1.getSession().getAttribute("user");
        System.out.println("UserFilter -->" + user);
//        if (null != user) {
//            chain.doFilter(request, response);
//        }
        chain.doFilter(request, response);

    }

    @Override
    public void destroy() {
        System.out.println("UserFilter destroy -->run");
        Filter.super.destroy();
    }
}
