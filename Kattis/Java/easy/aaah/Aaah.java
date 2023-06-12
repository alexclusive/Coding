import java.util.*;

class Aaah {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in); // System.in is a standard input stream
		String str = sc.next(); // reads string before the space
		String str2 = sc.next();

		if (str.length() < str2.length()) {
			System.out.println("no");
		} else {
			System.out.println("go");
		}
	}
}