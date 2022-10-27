package cn.wh.webmode.Listener;

import java.util.logging.Logger;
import org.springframework.context.ApplicationListener;
import org.springframework.stereotype.Component;

@Component
public class MyListener implements ApplicationListener<MyEvent> {
    //    @Override
//    public void onApplicationEvent(ApplicationEvent event) {
//
//    }
    Logger logger = Logger.getLogger(String.valueOf(MyListener.class));

    @Override
    public void onApplicationEvent(MyEvent event) {
        logger.info(String.format("%s监听到事件源：%s.", MyListener.class.getName(), event.getSource()));
    }

}
