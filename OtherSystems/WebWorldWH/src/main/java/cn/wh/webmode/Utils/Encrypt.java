package cn.wh.webmode.Utils;

//引入相关包

import javax.crypto.Cipher;
import javax.crypto.spec.IvParameterSpec;
import javax.crypto.spec.SecretKeySpec;

//引入第三方包
import org.apache.commons.codec.binary.Base64;
import org.apache.commons.codec.digest.DigestUtils;
import org.springframework.stereotype.Component;

@Component
public class Encrypt {
    //--------------AES---------------
    private final String KEY = "a4k9f5wbf8g7ur26";  // 密匙，必须16位
    private final String OFFSET = "5e8u7we5op8w9jq8"; // 偏移量
    private final String ENCODING = "UTF-8"; // 编码
    private final String ALGORITHM = "AES"; //算法
    private final String CIPHER_ALGORITHM = "AES/CBC/PKCS5Padding"; // 默认的加密算法，CBC模式
    //---------------MD5-------------------
    private final String MD5KEY = "f4k9f5w7f8g4er26";  // 密匙
    /*public  void main(String[] args) {
        try {

            String key = AESencrypt("wenhao");
            System.out.println("加密后:"+key);
            System.out.println("解密后:"+AESdecrypt(key));

            String key1 = MD5encrypt("wenhao");
            System.out.println("加密后:"+key1);
            System.out.println("判断是否为admin加密而来:"+verify("wenhao",key1));


        } catch (Exception e) {
            e.printStackTrace();
        }
    }
    */
    public Encrypt() {
    }
    public Encrypt(String KEY, String OFFSET, String ENCODING, String ALGORITHM, String CIPHER_ALGORITHM) {
    }

    public Encrypt(String MD5KEY) {
    }

    /**
     * AES加密
     *
     * @param data
     * @return String
     * @author anson
     * @date 2019-8-24 18:43:07
     */
    public String AESencrypt(String data) throws Exception {
        Cipher cipher = Cipher.getInstance(CIPHER_ALGORITHM);
        SecretKeySpec skeySpec = new SecretKeySpec(KEY.getBytes("ASCII"), ALGORITHM);
        IvParameterSpec iv = new IvParameterSpec(OFFSET.getBytes());//CBC模式偏移量IV
        cipher.init(Cipher.ENCRYPT_MODE, skeySpec, iv);
        byte[] encrypted = cipher.doFinal(data.getBytes(ENCODING));
        return new Base64().encodeToString(encrypted);//加密后再使用BASE64做转码
    }

    /**
     * AES解密
     *
     * @param data
     * @return String
     * @author anson
     * @date 2019-8-24 18:46:07
     */
    public String AESdecrypt(String data) throws Exception {
        Cipher cipher = Cipher.getInstance(CIPHER_ALGORITHM);
        SecretKeySpec skeySpec = new SecretKeySpec(KEY.getBytes("ASCII"), ALGORITHM);
        IvParameterSpec iv = new IvParameterSpec(OFFSET.getBytes()); //CBC模式偏移量IV
        cipher.init(Cipher.DECRYPT_MODE, skeySpec, iv);
        byte[] buffer = new Base64().decode(data);//先用base64解码
        byte[] encrypted = cipher.doFinal(buffer);
        return new String(encrypted, ENCODING);
    }

    //---------------------MD5--------------------

    /**
     * MD5方法
     *
     * @param text 明文
     * @return 密文
     * @author anson
     * @date 2019-8-24 18:54:42
     */
    public String MD5encrypt(String text) throws Exception {
        //加密后的字符串
        String encodeStr = DigestUtils.md5Hex(text + MD5KEY);
        return encodeStr;
    }

    /**
     * MD5验证方法
     *
     * @param text 明文
     * @param md5  密文
     * @return true/false
     * @author anson
     * @date 2019-8-24 18:58:56
     */
    public boolean verify(String text, String md5) throws Exception {
        //根据传入的密钥进行验证
        String md5Text = MD5encrypt(text);
        if (md5Text.equalsIgnoreCase(md5)) {
            return true;
        }
        return false;
    }
}
