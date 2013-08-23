
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Scanner;

/**
 * Date: 12/20/11
 * Time: 5:59 PM
 */
public class Xorkey1
{
    private static final int NUM_OF_BITS = 16;
    public static void main(String[] args)
    {
        solve(new Scanner(System.in), System.out);
    }

    private static void solve(Scanner sc, final PrintStream output)
    {
        int c = Integer.parseInt(sc.nextLine());
        for (int i = 0; i < c; i++)
        {
            new Xorkey1().solveCase(sc, output);
        }
    }

//    ---------------------------------------------------------


    private void solveCase(Scanner sc, PrintStream output)
    {
        Scanner lineScanner = new Scanner(sc.nextLine());
        int N = lineScanner.nextInt();
        int Q = lineScanner.nextInt();

        lineScanner = new Scanner(sc.nextLine());
        int[] key = new int[N];

//        int max = 0;
        for(int i = 0; i < N; i++){
            final int v = lineScanner.nextInt();
            key[i] = v;
//            if (v > max) max = v;
        }

        Tree tree = new Tree();

        for(int i = 0; i < N; i++){
            updateTree(tree, key[i], i);
        }

        for (int i = 0; i < Q; i++){
            lineScanner = new Scanner(sc.nextLine());
            int a = lineScanner.nextInt();
            int p = lineScanner.nextInt();
            int q = lineScanner.nextInt();

            output.printf("%d\n", solveQuery(key, tree, a, p, q));
        }
    }

    private void updateTree(Tree tree, int v, int index)
    {
        tree.insert(v, index + 1);
    }

    private int solveQuery(int[] key, Tree tree, final int query, int p, int q)
    {
        int temp = tree.findMax(query, p, q);
        if (temp == Tree.NOT_FOUND) {
            throw new IllegalArgumentException("Cannot find anything");
        }
        else {
            return key[temp - 1] ^ query;
        }
    }

    private static class Tree
    {
        private static final int NOT_FOUND = -1;
        int[] max;
        int[] min;
        private int maxBit = 16;

        private Tree()
        {
            max = new int[0x10000];
            min = new int[0x10000];

            Arrays.fill(max, -1);
            Arrays.fill(min, Integer.MAX_VALUE);
        }

        public void insert(int v, int index)
        {
            int cursor = 0;
            for (int i = 0; i < maxBit; i++) {
                if (index > max[cursor]) max[cursor] = index;
                if (index < min[cursor]) min[cursor] = index;
                if (getBit(v, i)) {
                    cursor = 2 * cursor + 2;
                } else {
                    cursor = 2 * cursor + 1;
                }
                System.out.print(cursor+" ");
            }
        }

        private boolean getBit(int v, int bit)
        {
            return ((v << bit) & 0x8000) > 0;
        }

        public int findMax(int v, int p, int q)
        {
            return findMax(v, p , q, 0, 0);
        }

        public int findMax(int v, int p, int q, int bit, int cursor)
        {
            if ((max[cursor] < p) || (min[cursor] > q)) return NOT_FOUND;

            if (bit == maxBit - 1) {
                if (getBit(v, bit)) {
                    final int i = min[cursor];
                    boolean isValid = (i >= p) && (i <= q);
                    if (isValid) {
                        return i;
                    }
                }

                final int i = max[cursor];
                boolean isValid = (i >= p) && (i <= q);
                if (isValid) {
                    return i;
                }

                return NOT_FOUND;
            } else {
                if (!getBit(v, bit)) {
                    int next = 2 * cursor + 2;
                    int temp = findMax(v, p, q, bit + 1, next);
                    if (temp > NOT_FOUND) {
                        return temp;
                    } else {
                        next = 2 * cursor + 1;
                        return findMax(v, p, q, bit + 1, next);
                    }
                } else {
                    int next = 2 * cursor + 1;
                    int temp = findMax(v, p, q, bit + 1, next);
                    if (temp > NOT_FOUND) {
                        return temp;
                    } else {
                        next = 2 * cursor + 2;
                        return findMax(v, p, q, bit + 1, next);
                    }
                }
            }
        }
    }
}