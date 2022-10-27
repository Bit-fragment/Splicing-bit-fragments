package cn.wh.webmode.Conterler.ThreadPoolConterlerTest;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;

@Service
public class UserServicePool {
    @Autowired
    Dao dao;

    public void run(String name) {
        dao.run(name + "->UserService");
    }

    public void run1(String[] name) {
        dao.run1(name);
    }

}
