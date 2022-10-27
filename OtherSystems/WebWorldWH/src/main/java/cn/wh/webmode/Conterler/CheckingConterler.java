package cn.wh.webmode.Conterler;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestParam;
import org.springframework.web.bind.annotation.ResponseBody;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.HttpServletRequest;
import java.util.Map;

@Controller
@RequestMapping(value = "/shuju")
public class CheckingConterler {
    @RequestMapping(value = "/fan")
    @ResponseBody
    public String fan(HttpServletRequest req) {
        req.getSession().setAttribute("shuju","abc123");
        return "往session中放数据成功";
    }

    @RequestMapping(value = "/na")
    @ResponseBody
    public String na(HttpServletRequest req) {
        String shuju = (String) req.getSession().getAttribute("shuju");
        if (null!=shuju){
            return shuju;
        }
        return "未登录！";
    }


    @RequestMapping(value = "hello")
    public ModelAndView hello(ModelAndView md) {
        md.setViewName("hello");
        return md;
    }

    @RequestMapping(value = "amptest")
    @ResponseBody
    public void testjc(@RequestParam Map<String, Object> map) {
        System.out.println(map);
    }
}
