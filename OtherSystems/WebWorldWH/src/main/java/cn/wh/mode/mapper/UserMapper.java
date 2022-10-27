package cn.wh.mode.mapper;

import cn.wh.mode.pojo.User;
import com.baomidou.mybatisplus.core.mapper.BaseMapper;
import org.apache.ibatis.annotations.Param;

import java.util.List;

/**
* @author XMZR
* @description 针对表【user】的数据库操作Mapper
* @createDate 2022-06-04 18:31:06
* @Entity cn.wh.mode.pojo.User
*/
public interface UserMapper extends BaseMapper<User> {
    /**查询指定账号密码的用户对象*/
    User singin(@Param("account") String account, @Param("password") String password);
    /**查询指定账号是否存在*/
    Integer searchAccountInteger(@Param("account") String account);
    /**查询指定账号用户数据*/
    User selectAllByAccountUser(@Param("account") String account);
    /**查询所有用户*/
    List<User> selectAllUser();
}




