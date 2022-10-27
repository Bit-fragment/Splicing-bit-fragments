package cn.wh.webmode.Conterler.AdminConterler;

import cn.wh.webmode.Utils.RedisUtils;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.ResponseBody;

import java.util.*;

@Controller
@RequestMapping(value = "/serverdata")
public class AdminConterlerForData {
    @Autowired
    RedisUtils redisUtils;

    @RequestMapping("/addRedisData")
    @ResponseBody
    boolean addRedisData(@RequestBody Map<String, Map<String, String>> data) {
        System.out.println(data.get("body"));
        Map<String, String> mapData = data.get("body");
        return redisUtils.set(mapData.get("key"), mapData.get("value"));
    }

    @RequestMapping("/remRedisData")
    @ResponseBody
    boolean remRedisData(@RequestBody Map<String, Map<String, String>> data) {
        System.out.println(data.get("body"));
        Map<String, String> mapData = data.get("body");
        return redisUtils.delete(mapData.get("key"));
    }

    @RequestMapping("/setRedisData")
    @ResponseBody
    boolean setRedisData(@RequestBody Map<String, Map<String, String>> data) {
        System.out.println(data.get("body"));
        Map<String, String> mapData = data.get("body");
        return redisUtils.getAndSet(mapData.get("key"), mapData.get("value"));
    }

    @RequestMapping("/getRedisData")
    @ResponseBody
    String getRedisData(@RequestBody Map<String, Map<String, String>> data) {
        System.out.println(data.get("body"));
        Map<String, String> mapData = data.get("body");
        return redisUtils.get(mapData.get("key"));
    }

    @RequestMapping("/getRedisDataAll")
    @ResponseBody
    Map<Object, Object> getRedisDataAll() {
        Map<Object, Object> keys = redisUtils.getAll();
        System.out.println("getRedisDataAll: " + keys);
        return keys;
    }


}
