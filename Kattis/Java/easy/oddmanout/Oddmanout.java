// package Kattis.Java.easy.oddmanout;
import java.util.ArrayList;
import java.util.Scanner;

public class Oddmanout {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        for (int i = 1; i <= n; i++) {
            int g = sc.nextInt();
            ArrayList<Integer> volatileList = new ArrayList<Integer>();
            // ArrayList<Integer> list = new ArrayList<Integer>();
            while (g-- >= 0) {
                int current = sc.nextInt();
                // list.add(current);
                if (volatileList.contains(current)) {
                    volatileList.remove(current);
                } else {
                    volatileList.add(current);
                }
            }
            System.out.println("Case #" + i + ": ");// + volatileList.get(0));
        }
        sc.close();
    }
}