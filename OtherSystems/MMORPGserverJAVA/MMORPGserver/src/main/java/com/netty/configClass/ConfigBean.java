package com.netty.configClass;

import com.netty.gameObject.GameWorldObject;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;

@Configuration
public class ConfigBean {
    @Bean("GameWorldObject")
    public GameWorldObject getGameWorldObject(){
        return new GameWorldObject();
    }

}
