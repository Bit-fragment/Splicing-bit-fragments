package cn.wh.webmode.Conterler;

import org.slf4j.Logger;
import org.slf4j.LoggerFactory;
import org.springframework.stereotype.Service;

@Service
public class AsyncService {
    private static final Logger logger = LoggerFactory.getLogger(AsyncService.class);

    public void executeAsync() {
        logger.info("开始执行Service层任务");
        try{
            System.out.println(Thread.currentThread().getName());
            Thread.sleep(2000);
        }catch(Exception e){
            e.printStackTrace();
        }
        logger.info("Service层任务执行完毕");
    }

}
