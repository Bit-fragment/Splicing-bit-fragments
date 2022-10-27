package cn.wh.demo;

import java.util.concurrent.locks.ReentrantLock;

public class test1 {
    private static int i = 0;
    private static int o = 0;
    private static ReentrantLock lock = new ReentrantLock();
    private static void add(){
        lock.lock();
        try{
            i++;
        }finally {
            lock.unlock();
        }
    }

    private static void add1(){
        lock.lock();
        try{
            o++;
        }finally {
            lock.unlock();
        }
    }

    public static class thre implements Runnable{
        @Override
        public void run() {
            for (int i =0;i<10000;i++){
                test1.add();
            }
        }
    }

    public static class thre1 extends Thread{
        @Override
        public void run() {
            for (int i =0;i<20000;i++){
                test1.add1();
            }
        }
    }

    public static void main(String[] args) {
        thre t1 = new thre();
        thre t2 = new thre();
        thre t3 = new thre();

        t1.run();
        t2.run();
        t3.run();

        thre1 t11 = new thre1();
        thre1 t12 = new thre1();
        thre1 t13 = new thre1();

        t11.start();
        t12.start();
        t13.start();

        try {
            t11.join();
            t12.join();
            t13.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }

        System.out.println(i);
        System.out.println(o);
    }
}
