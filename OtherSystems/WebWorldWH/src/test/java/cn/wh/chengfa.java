package cn.wh;

public class chengfa {
    public static void main(String[] args) {
//        for(int a = 1;a<=9;a++){
//            for (int b = 0;b<a;b++){
//                System.out.print((b+1)+"*"+a+"="+(b+1)*a+" ");
//            }
//            System.out.println();
//        }
        f();

        String s = "祝你考出好成绩！";
        System.out.println(s.length());
    }

    public static void f() {
        for (int i = 1, j = 1; j < 10; i++) {
            System.out.print(i + "*" + j + "=" + i * j + "  ");
            if (i == j) {
                System.out.println();
                i = 0;
                j++;
            }
        }
    }

    public static void m(int x) {
        System.out.println(x % 10);
        if ((x / 10) != 0) {
            m(x / 10);

        }
        System.out.println(x % 10);
    }


}
