package cn.wh.webmode.Conterler;

import cn.hutool.core.io.FileUtil;
import cn.hutool.json.JSONUtil;
import cn.wh.mode.pojo.User;
import cn.wh.mode.service.UserService;
import cn.wh.mode.service.impl.ArticleServiceImpl;
import cn.wh.mode.service.impl.UserServiceImpl;
import cn.wh.webmode.Utils.Encrypt;
import com.alibaba.fastjson.JSON;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.boot.configurationprocessor.json.JSONObject;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.*;
import org.springframework.web.servlet.ModelAndView;

import javax.servlet.http.Cookie;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import java.io.*;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import static cn.wh.webmode.config.UsualConfig.StringResourceDirectory;
import static cn.wh.webmode.config.UsualConfig.VideoResources;

@Controller
@RequestMapping(value = "/user")
public class TeseConterler {
    @Autowired
    UserServiceImpl userService;

    @Autowired
    Encrypt encrypt;

    @Autowired
    ArticleServiceImpl articleService;

    @RequestMapping(value = "/hi")
    public ModelAndView hi(ModelAndView md) {
        System.out.println("/user/hi");
        md.setViewName("AxiosVue");
        md.addObject("list", userService.selectUser());
        return md;
    }

    @RequestMapping(value = "/xiazai")
    public ModelAndView xiazai(ModelAndView md) {
        md.setViewName("AxiosVue");

        md.addObject("list", userService.selectUser());
        return md;
    }

    @RequestMapping(value = "/movie")
    public ModelAndView tev(ModelAndView md, @RequestParam("videoPath") String videoPath) {
//        String url = StringResourceDirectory + VideoResources + videoPath;
        md.getModelMap().put("v", videoPath);
        md.setViewName("movie");
        return md;
    }

    @RequestMapping(value = "/he")
    @ResponseBody
    public List he() {
        System.out.println("/user/he");
        String list = JSON.toJSONString(userService.selectUser());
        System.out.println(list);
        return userService.selectUser();
    }

    @RequestMapping(value = "/singin")//登陆页面
    public ModelAndView singin(ModelAndView md) {
        System.out.println("/user/singin");
        md.setViewName("singin");
        return md;
    }

    @RequestMapping(value = "/singinuser")//登陆方法
    @ResponseBody
    public void singinuser(
//            @RequestParam(value = "params") String value,
//            @RequestParam(value = "input") JSONObject user
            @RequestBody User user,
            HttpServletRequest req, HttpServletResponse resp
    ) {
        System.out.println(user);
        String username = user.getAccount();
        String password = user.getPassword();

        System.out.println("/user/singinuser");
        System.out.println("账号:" + username + "  密码:" + password);

        resp.setCharacterEncoding("UTF-8");
        final HashMap<String, String> map = new HashMap<>();


        if (userService.singin(username, password, req)) {
            HttpSession session = req.getSession();
            String session_id = session.getId();
            Cookie cookie = new Cookie("JSESSIONID", session_id);//session_id默认是存放在一个name为JSESSIOINID里面的
            //cookie.setPath("上次路径");
            cookie.setMaxAge(30 * 60);// 30 分钟
            resp.addCookie(cookie);

            try {
                map.put("code", "0");
                map.put("key", encrypt.AESencrypt(username));
                final String s = JSONUtil.toJsonStr(map);
                resp.getWriter().println(s);
            } catch (Exception e) {
                e.printStackTrace();
            }
        } else {
            try {
                map.put("code", "1");
                map.put("key", "null");
                final String s = JSONUtil.toJsonStr(map);
                resp.getWriter().println(s);
            } catch (Exception e) {
                e.printStackTrace();
            }
        }

    }

    @RequestMapping(value = "/singinuserx")//直接登录
    @ResponseBody
    public boolean singinuserx(
            @RequestBody Map<String, String> value,
            HttpServletRequest req, HttpServletResponse resp) {
        String account = "";
        try {
            account = encrypt.AESdecrypt(value.get("account"));
        } catch (Exception e) {
            e.printStackTrace();
        }
        if (userService.UserQuery(account)) {
            HttpSession session = req.getSession();
            session.setAttribute("user", userService.UserSingin(account));
            String session_id = session.getId();
            Cookie cookie = new Cookie("JSESSIONID", session_id);//session_id默认是存放在一个name为JSESSIOINID里面的
            //cookie.setPath("上次路径");
            cookie.setMaxAge(30 * 60);// 30 分钟
            resp.addCookie(cookie);
            return true;
        }
        return false;
    }

    @RequestMapping(value = "/singout")//清楚session中的用户数据
    @ResponseBody
    public void singout(HttpServletRequest req, HttpServletResponse resp) {
        HttpSession hs = req.getSession();
        hs.setAttribute("user", null);
        hs.invalidate();
        if (null != req.getCookies()) for (Cookie cookie : req.getCookies()) {
            if (cookie.getName().equals("JSESSIONID")) {
                cookie.setValue("");
                cookie.setMaxAge(0);
                // 重点是这里1,必须设置domain属性的值
                //cookie.setDomain("/");
                // 重点是这里2,必须设置path属性的值
                cookie.setPath("/");
                resp.addCookie(cookie);
            }
        }
    }

    @RequestMapping(value = "/login")//注册页面
    public ModelAndView login(ModelAndView md) {
        System.out.println("/user/login");
        md.setViewName("login");
        return md;
    }

    @RequestMapping(value = "/loginuser")//注册方法
    @ResponseBody
    public boolean loginuser(
            @RequestParam(value = "name") String name,
            @RequestParam(value = "account") String account,
            @RequestParam(value = "password1") String password1,
            @RequestParam(value = "password2") String password2,
            HttpServletRequest req) {
        System.out.println("/user/loginuser");
        Boolean b = false;
        if (password1.length() >= 4 && password1.equals(password2)) {
            User user = new User();
            user.setUsername(name);
            user.setAccount(account);
            user.setPassword(password1);
            b = userService.login(user);
            return b;
        } else return b;
    }

    @RequestMapping(value = "/wenben")
    @ResponseBody
    public String addArticle(@RequestBody Map<String, String> data, HttpServletRequest req) {
        System.out.println(data);
        if (articleService.addArticle(data, (User) req.getSession().getAttribute("user"))) return "文章发表成功";
        return "文章发表失败";
    }

    @RequestMapping(value = "/wenbenhq")
    @ResponseBody
    public String getArticle() throws IOException {
        /* BufferedReader由Reader类扩展而来，提供通用的缓冲方式文本读取，而且提供了很实用的readLine，读取一个文本行，
         * 从字符输入流中读取文本，缓冲各个字符，从而提供字符、数组和行的高效读取。
         * BufferedReader和BufferedWriter为默认带有缓冲的字符输出输入流，因为有缓冲区所以效率比没有缓冲区的高。
         * */
        BufferedReader bufferedReader = new BufferedReader(
                /* InputStreamReader类是字节流通向字符流的桥梁，封装在InputStream里，
                 * 它以较高级的方式，一次读取一个字符，以文本格式输入/输出，可以指定编码格式。
                 * 如果不指定字符集编码，该解码过程将使用平台默认的字符编码，如：GBK。
                 * */
                new InputStreamReader(
                        /* JAVA中针对文件的读写操作设置了一系列的流，
                         * 其中主要有 FileInputStream,FileOutputStream,FileReader,FileWriter 四种最为常用的流
                         * FileInputStream 流被称为文件字节输入流，意思指对文件数据以字节的形式进行读取操作如读取图片视频等
                         * */
                        new FileInputStream("C:\\Users\\50838\\Desktop\\resource\\TxtResources\\4_admin123\\1656922489707_天青色等烟雨.txt"), StandardCharsets.UTF_8));

        String line;
        StringBuilder fh = new StringBuilder();
        while ((line = bufferedReader.readLine()) != null) {//readLine,一次读取一个文本行

            if (line.length() > 0) {
                fh.append(line);//idea建议将fh+=line 变为这样
            }

        }
        bufferedReader.close();
        return fh.toString();
    }

    @RequestMapping(value = "/getLoginStatus")
    @ResponseBody
    public String getLoginStatus(HttpServletRequest req) {
        if (null == req.getSession().getAttribute("user")) {
            return "false";
        }
        return "true";
    }

}
