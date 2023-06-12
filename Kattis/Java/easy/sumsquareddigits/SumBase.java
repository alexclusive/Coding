import java.util.*;
public class SumBase {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int P = s.nextInt();
		int K = s.nextInt();
		while (K <= P) {
			int b = s.nextInt();
			int n = s.nextInt(); // might get overflow from signed
			System.out.println(K + " " + SSD(b,n));
			K = s.nextInt();
		}
		s.close();
	}
	
	private static int SSD(int b, int n) {
		ArrayList<Integer> num = new ArrayList<Integer>();
		while (n != 0) {
			num.add(n%b);
			n /= b;
		}
		int sum = 0;
		for (int i : num)
			sum += i * i;
		return sum;

	}
	
	// doesn't work for b>10 because symbols aren't encoded
	private static long baseConvert(int b, int n) {
		long depth = 1;
		long num = 0;
		while (n != 0) {
			num += n%b * depth;
			depth *= 10;
			n /= b;
		}
		return num;
	}
	
	private static int sumSquares(long n) {
		if (n < 0)
			n *= -1;
		int sum = 0;
		while (n > 0) {
			sum += (n%10) * (n%10);
			n /= 10;
			
		}
		return sum;
	}

}
