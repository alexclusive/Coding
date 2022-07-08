import java.util.*;
public class WeakVertices {
	static int n;
	static Vertex[] g;
	static Scanner sc;

	public static void main(String[] args) {
		sc = new Scanner(System.in);
		n = sc.nextInt();
		
		while (n != -1) {
			g = new Vertex[n];
			for (int i = 0; i < n; i++) {
				g[i] = new Vertex(i);
			}
		
			scanIn();
		
			for (Vertex v : g) {
				if (v.isWeak())
					System.out.print(v.ID + " ");
			}
			System.out.println();
			
			n = sc.nextInt();
		}
		
		
	}

	public static void scanIn() {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (sc.nextInt() == 1)
					g[i].addNeighbour(g[j]);
			}
		}
	}
}

class Vertex {
	int ID;
	ArrayList<Vertex> neighbours;
	int degree;
	
	public Vertex(int id) {
		ID = id;
		neighbours = new ArrayList<Vertex>();
		degree = 0;
	}
	
	public void addNeighbour(Vertex v) {
		neighbours.add(v);
		degree++;
	}
	
	public boolean isWeak() {
		if (degree < 2)
			return true;
		
		for (Vertex i : neighbours) {
			for (Vertex j : neighbours) {
				if (i != j && i.connectedTo(j)) {
					return false;
				}
			}
		}
		return true;
	}
	
	private boolean connectedTo(Vertex v) {
		return neighbours.contains(v);
	}
}