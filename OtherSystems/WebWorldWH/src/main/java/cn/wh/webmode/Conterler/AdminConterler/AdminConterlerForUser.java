package cn.wh.webmode.Conterler.AdminConterler;

import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;


@Controller
@RequestMapping(value = "/admin/user")
public class AdminConterlerForUser {

    @RequestMapping("/qwe")
    @ResponseBody
    public String getReviews() {

        return "AdminConterlerForUser";
    }


}
