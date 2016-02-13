class Foo implements Runnable {
    int count = 0;
    public void run() {
        while(count != 10) { 
            System.out.println("Count: "+count++);
            try {
                Thread.sleep(1000);
            } catch(InterruptedException e) {
            }
        }
    }
};

class SimpleThread {
    public static void main(String args[]) {
        Thread th = new Thread(new Foo());
        th.start();
    }
}

