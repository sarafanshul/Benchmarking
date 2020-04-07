// Fastest(Java)
class Queens {
	
	public static void main(String[] args){

		int n = 13;
		int nsol = 0;
		double t1 = System.nanoTime();
		Board b = new Board(n);
		nsol = b.allQueensRec();

		double t2 = System.nanoTime();
		double dt = (t2 - t1) * 1e-9;
		System.out.println(String.format("%d	%f", n,dt));

	}
	
}


class Board {

	protected int n;
	protected boolean col[],dg1[],dg2[];

	public Board(int n) {
		this.n = n;
		col = new boolean[n];
		dg1 = new boolean[2*n];
		dg2 = new boolean[2*n];
	}

	int addQueensRecursive(int n, int i) {

		if (n == i) {
			return 1;
		}

		int nsol = 0;
		for (int j = 0; j < n; j++) {
			if (col[j] && dg1[i+j] && dg2[i-j+n]) {
				col[j] = false;
				dg1[i+j] = false;
				dg2[i-j+n] = false;

				nsol += addQueensRecursive(n, i+1);

				col[j] = true;
				dg1[i+j] = true;
				dg2[i-j+n] = true;
			}
		}
		return nsol;
	}

	public int allQueensRec() {
		for (int i=0;i<2*n;i++){
			dg1[i] = true;
			dg2[i] = true;	
		}
		for (int i=0;i<n;i++){
			col[i] = true;	
		}
		return addQueensRecursive(n, 0);
	}
}

