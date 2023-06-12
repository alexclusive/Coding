import java.util.*;

class ABC {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		ArrayList<Integer> al = new ArrayList<Integer>();
		al.add(sc.nextInt());
		al.add(sc.nextInt());
		al.add(sc.nextInt());
		Collections.sort(al);

		String order = sc.next();
		char ch;
		for (int i = 0; i < 3; i++) {
			ch = order.charAt(i);
			if (ch == 'A') {
				System.out.print(al.get(0) + " ");
			} else if (ch == 'B') {
				System.out.print(al.get(1) + " ");
			} else if (ch == 'C') {
				System.out.print(al.get(2) + " ");
			}
		}

		sc.close();
	}
}