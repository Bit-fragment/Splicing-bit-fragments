package cn.wh.webmode.Conterler.ThreadPoolConterlerTest;

import cn.wh.webmode.Conterler.ThreadPoolConterlerTest.ThreadPackge.CustomThreadPool;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;

import java.util.concurrent.TimeUnit;

@Component
public class Dao {
    @Autowired
    CustomThreadPool threadPool;

    public void run(String name) {
        System.out.println(name + "->Dao");
    }

    public void run1(String[] name) {
        for (int i = 0; i < name.length; i++) {
            Thread thread = new Thread() {
                @Override
                public void run() {
                    try {
                        //  System.out.println(this.getName()+"-执行");
                        TimeUnit.SECONDS.sleep(1);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            };
            thread.setName("任务名称[" + name[i] + "]");
            threadPool.execute(thread);
        }

    }

}
