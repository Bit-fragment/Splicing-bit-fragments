package cn.wh.webmode.Conterler;

import cn.wh.mode.mapper.ArticleMapper;
import cn.wh.mode.mapper.UserMapper;
import cn.wh.mode.pojo.User;
import cn.wh.mode.service.impl.CommentServiceImpl;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.Map;

@Controller
@RequestMapping(value = "/comment")
public class CommentConterler {
    @Resource
    UserMapper userMapper;
    @Resource
    ArticleMapper articleMapper;

    @Resource
    CommentServiceImpl commentService;

    @RequestMapping(value = "/addComment")
    @ResponseBody
    public String addComment(@RequestBody Map<String, String> data, HttpServletRequest req) {
        User user = (User) req.getSession().getAttribute("user");//获得发表评论的user对象
        if (commentService.addComment(data, user)) {
            return "评论发表成功";
        }
        return "评论发表失败";
    }
}
