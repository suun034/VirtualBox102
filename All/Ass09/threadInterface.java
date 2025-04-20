class Study implements Runnable {
    public void run() {
        while(true){
            System.out.println("I am studying");
        }
    }
}

class Cook implements Runnable {
    public void run() {
        while(true){
            System.out.println("I am cooking");
        }
    }
}

class Sleep implements Runnable {
    public void run() {
        while(true){
            System.out.println("I am sleeping");
        }
    }
}

public class threadInterface {
    public static void main(String[] args) {
        Thread t1 = new Thread(new Study());
        Thread t2 = new Thread(new Cook());
        Thread t3 = new Thread(new Sleep());

        t1.start();
        t2.start();
        t3.start();
    }
}
