import java.util.*;

public class Average {
	public static void main(String args[]) {
		Scanner s = new Scanner(System.in);
		int repeats = s.nextInt();
		for (; repeats > 0; repeats--) {
			int average = 0;
			ArrayList<Integer> al = new ArrayList<Integer>();

			float length = s.nextFloat();
			for (int i = 0; i < length; i++) {
				al.add(s.nextInt());
				average += al.get(i);
			}
			average /= length;

			float above = 0;
			for (int elem : al) {
				if (elem > average) {
					above++;
				}
			}

			System.out.println(String.format("%.3f", (above / length) * 100) + "%");
		}
	}
}