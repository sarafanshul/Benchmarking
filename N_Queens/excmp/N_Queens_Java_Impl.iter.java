class NQueens {
  
  private static int N = 13;
  private static int[] b = new int[N];
  private static int s = 0;
 
  static boolean unsafe(int y) {
    int x = b[y];
    for (int i = 1; i <= y; i++) {
      int t = b[y - i];
      if (t == x ||
          t == x - i ||
          t == x + i) {
        return true;
      }
    }
 
    return false;
  }
 
public static void main(String[] args) {
    int cnt = 0;
    int y = 0;
    b[0] = -1;
    double t1 = System.nanoTime();
    while (y >= 0) {
      do {
        b[y]++;
      } while ((b[y] < N) && unsafe(y));
      if (b[y] < N) {
        if (y < N-1) {
          b[++y] = -1;
        } else {
          cnt++;
        }
      } else {
        y--;
      }
    }
    double t2 = System.nanoTime();
    double dt = (t2 - t1) * 1e-9;
    // System.out.println(cnt);
    System.out.println(String.format("%d  %f %d", N,dt ,cnt));
  }
}