import java.util.*;

public class Homework {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line = sc.next();
		sc.close();
		String[] nums = line.split(";");
		int sum = 0;
		for (String num : nums) {
			String[] range = num.split("-");
			if (range.length > 1) {
				int n = Integer.valueOf(range[0]);
				int m = Integer.valueOf(range[1]);
				sum += m-n + 1;
			} else {
				sum++;
			}
		}
		System.out.println(sum);
	}
}