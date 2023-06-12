import java.util.*;

public class Arrangement {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int N = s.nextInt();
		int M = s.nextInt();
		int[] arr = new int[N];
		for (int i = 0, counter = 0; counter < M; i++, counter++, arr[i % N]++)
			;
		for (int i = 0; i < N; i++) {
			String tmp = "";
			for (int j = 0; j < arr[i]; j++, tmp += '*')
				;
			System.out.println(tmp);
		}
	}
}