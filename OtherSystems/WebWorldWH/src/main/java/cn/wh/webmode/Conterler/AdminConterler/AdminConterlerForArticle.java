package cn.wh.webmode.Conterler.AdminConterler;

import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.User;
import cn.wh.mode.service.impl.ArticleServiceImpl;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.Map;


@Controller
@RequestMapping(value = "/admin/article")
public class AdminConterlerForArticle {
    @Resource
    ArticleServiceImpl articleService;
    @Resource
    UserMapper userMapper;

    @RequestMapping("/publishArticle")
    @ResponseBody
    public String PublishArticle(@RequestBody Map<String, String> map) {
        System.out.println(map.get("value"));

        return "AdminConterlerForArticle";
    }


    ///admin/article/addArticle
    @RequestMapping(value = "/addArticle")
    @ResponseBody
    public String addArticle(@RequestBody Map<String, String> data, HttpServletRequest req) {
        User user = userMapper.selectById((User) req.getSession().getAttribute("user"));
        if (articleService.addArticle(data, user)) return "文章发表成功";
        return "文章发表失败";
    }

}
