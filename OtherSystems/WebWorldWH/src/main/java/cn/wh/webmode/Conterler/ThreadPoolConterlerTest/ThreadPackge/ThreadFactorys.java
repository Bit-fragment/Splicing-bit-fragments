package cn.wh.webmode.Conterler.ThreadPoolConterlerTest.ThreadPackge;

import org.springframework.stereotype.Component;

import java.util.concurrent.ThreadFactory;
import java.util.concurrent.atomic.AtomicInteger;

@Component
public class ThreadFactorys implements ThreadFactory {
    static AtomicInteger threadNum = new AtomicInteger(1);

    public ThreadFactorys() {
        super();
    }

    @Override
    public Thread newThread(Runnable r) {
        Thread thread = new Thread(r);
        thread.setName("自定义线程-"+threadNum.getAndIncrement());
        return thread;
    }

}
