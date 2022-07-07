import java.util.*;
public class skruop {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        int vol = 7;
        while (n >= 0) {
            n--;
            String req = s.nextLine();
            if (vol < 10 && req.equals("Skru op!"))
            	vol++;
            else if (vol > 0 && req.equals("Skru ned!"))
            	vol--;
        }
        System.out.println(vol);
    }
}