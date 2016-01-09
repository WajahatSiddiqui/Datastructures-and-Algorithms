public class RunThread {
    public static void main(String args[]) throws Exception {
        RunImpl rI = new RunImpl();
        Thread t1 = new Thread(rI);
        t1.start();
        Thread.sleep(1000);
        Thread t2 = new Thread(rI);
        t2.start();
        Thread.sleep(1000);

        ThreadImpl tI1 = new ThreadImpl();
        tI1.start();
        Thread.sleep(1000);
        ThreadImpl tI2 = new ThreadImpl();
        tI2.start();
        Thread.sleep(1000);
    }
}

class RunImpl implements Runnable {
    private int count = 0;
    public void run() {
        count++;
        System.out.println("RunImpl count: "+count);
    }
}

class ThreadImpl extends Thread {
    private int count = 0;
    public void run() {
        count++;
        System.out.println("ThreadImpl count: "+count);
    }
}
