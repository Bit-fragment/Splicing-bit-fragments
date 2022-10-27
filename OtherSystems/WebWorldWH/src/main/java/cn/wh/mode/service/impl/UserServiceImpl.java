package cn.wh.mode.service.impl;

import com.baomidou.mybatisplus.extension.service.impl.ServiceImpl;
import cn.wh.mode.pojo.User;
import cn.wh.mode.service.UserService;
import cn.wh.mode.mapper.UserMapper;
import org.springframework.stereotype.Service;

import javax.annotation.Resource;
import javax.servlet.http.HttpServletRequest;
import java.util.List;

/**
 * @author XMZR
 * @description 针对表【user】的数据库操作Service实现
 * @createDate 2022-06-04 18:31:06
 */
@Service
public class UserServiceImpl extends ServiceImpl<UserMapper, User>
        implements UserService {
    @Resource
    UserMapper userMapper;

    /**查询指定账号是否存在*/
    public Boolean UserQuery(String account) {
        if (null == account) return false;
        return userMapper.searchAccountInteger(account) == 1;
    }

    /**查询指定账号的用户数据*/
    public User UserSingin(String account) {
        if (null == account) return null;
        return userMapper.selectAllByAccountUser(account);
    }

    /**登录方法*/
    public Boolean singin(String account, String password, HttpServletRequest req) {
        User user = userMapper.singin(account, password);
        if (null != user) {
            req.getSession().setAttribute("user", user);
            return true;
        } else return false;
    }

    /**注册方法*/
    public Boolean login(User user) {
        return userMapper.insert(user) == 1;
    }

    /**查询所有用户方法*/
    public List<User> selectUser() {
        return userMapper.selectAllUser();
    }

    /**查询第i到j的数据*/
    public List<User> selectUserIJ(int i, int j) {

        return null;
    }
}




