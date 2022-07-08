import java.util.*;

public class Autori {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        String in = s.next();
        String out = in.charAt(0) + "";
        for (int i = 1; i < in.length(); i++) {
            if (in.charAt(i) == '-') {
                out += in.charAt(i + 1);
                i++;
            }
        }
        System.out.print(out);
    }
}