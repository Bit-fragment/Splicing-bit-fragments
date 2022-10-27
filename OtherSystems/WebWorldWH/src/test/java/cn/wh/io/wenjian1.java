package cn.wh.io;

import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.HashMap;
import java.util.Map;

public class wenjian1 {
    public static void main(String[] args) {
        try {
            wenbenhq();

//            BufferedReader stdin =new BufferedReader(new InputStreamReader(System.in));
//            System.out.print("Enter a line:");
//            System.out.println(stdin.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void wenbenhq() throws IOException {
        BufferedReader bufferedReader = new BufferedReader(
                new InputStreamReader(
                        new FileInputStream("D:\\ds.txt"), StandardCharsets.UTF_8));
        String line;
        Map<String,Object> map = new HashMap<String,Object>();
        while ((line = bufferedReader.readLine()) != null) {
            if (line.length()>0){
                System.out.println(line);
                String [ ] s = line.split("=");
                map.put(s[0],s[1]);
            }
        }
        System.out.println(map);
        bufferedReader.close();
    }


}
