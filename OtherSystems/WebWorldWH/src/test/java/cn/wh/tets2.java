package cn.wh;

public class tets2 {

    private static String[] args;

    public static void main(String[] args) {
        // tets2 t = new tets2();
        // t.go();
        int[] list = new int[]{1, 2, 6, 8, 4, 1, 1, 2, 5, 2, 64, 3, 4};
        test4(list);
    }

    static void test4(int[] list) {

        for (int i = 0; i < list.length - 1; i++) {
            for (int j = 0; j < list.length - 1 - i; j++) {
                if (list[j] > list[j + 1]) {
                    int a = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = a;
                }
            }
        }

        for (int number : list) {
            System.out.print(number);
        }
    }

    public void go() {
        Runnable r = new Runnable() {
            public void run() {
                System.out.println("go");
            }
        };
        Thread t = new Thread(r);
        t.start();
    }

    public void hi() {
        System.out.println("hi");
    }

    static class test3 {
        public static void main(String[] args) {
            tets2 t = null;
            t.hi();
        }
    }

}
