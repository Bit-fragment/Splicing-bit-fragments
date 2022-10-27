package cn.wh.demo;

public class Demo6 {
    //作用于当前类Class对象
    public static synchronized void m4() {
    }

    //作用于当前类Class对象
    public static void m5() {
        synchronized (Demo6.class) {
        }
    }

    public static void main(String[] args) {
        Demo6 d1 = new Demo6();
        Thread t1 = new Thread(() -> {
            d1.m1();
        });
        t1.start();
        Thread t2 = new Thread(() -> {
            d1.m2();
        });
        t2.start();
        Thread t3 = new Thread(() -> {
            d1.m2();
        });
        t3.start();
        Demo6 d2 = new Demo6();
        Thread t4 = new Thread(() -> {
            d2.m2();
        });
        t4.start();
        Thread t5 = new Thread(() -> {
            Demo6.m4();
        });
        t5.start();
        Thread t6 = new Thread(() -> {
            Demo6.m5();
        });
        t6.start();
    }

    //作用于当前类的实例对象
    public synchronized void m1() {
    }

    //作用于当前类的实例对象
    public synchronized void m2() {
    }

    //作用于当前类的实例对象
    public void m3() {
        synchronized (this) {
        }
    }

    public static class T extends Thread {
        Demo6 demo6;

        public T(Demo6 demo6) {
            this.demo6 = demo6;
        }

        @Override
        public void run() {
            super.run();
        }
    }
}