class StudyThread extends Thread {
    public void run() {
        while(true){
            System.out.println("I am studying");
        }
    }
}

class CookThread extends Thread {
    public void run() {
        while(true){
            System.out.println("I am cooking");
        }
    }
}

class SleepThread extends Thread {
    public void run() {
        while(true){
            System.out.println("I am sleeping");
        }
    }
}

public class threadClass {
    public static void main(String[] args) {
        StudyThread t1 = new StudyThread();
        CookThread t2 = new CookThread();
        SleepThread t3 = new SleepThread();

        t1.start();
        t2.start();
        t3.start();
    }
}
