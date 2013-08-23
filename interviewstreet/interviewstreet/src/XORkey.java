import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;

class Nodes
{
	BitSet index = new BitSet();
	public Nodes left;
	public Nodes right;

	public Nodes getLeft() {
		return left;
	}

	public void setLeft(Nodes left) {
		this.left = left;
	}

	public Nodes getRight() {
		return right;
	}

	public void setRight(Nodes right) {
		this.right = right;
	}

	boolean indexInRange(BitSet set)
	{
		return index.intersects(set);
	}
	void setIndex(int i)
	{
		index.set(i);
	}

	BitSet getIndex(){
		return index;
	}
}

public class XORkey {
	static int bestMatch(Nodes pRoot, int m, int p, int q) 
	{
		BitSet range = new BitSet();
		range.set(p, q+1);
		Nodes node = pRoot;

		for (int i = 15; i >= 0; i--) {
			byte bit = (byte) ((m >> i) & 0x01);

			if (bit != 0) {
				if (node.right != null) {
					if(node.right.indexInRange(range))
						node = node.right;
					else
						node = node.left;
				} else {
					node = node.left;
				}
			} else {
				if (node.left != null) {
					if(node.left.indexInRange(range))
						node = node.left;
					else
						node = node.right;
				} else {
					node = node.right;
				}
			}
		}

		return node.getIndex().nextSetBit(0);
	}

	static void insertNode(Nodes root, int x, int index)
	{
		int maxx = 1<<15;
		Nodes node = root;
		for (int i = 15; i >= 0; i--) {
			node.setIndex(index);
			int bit = (maxx & x);
			if(bit == 0)
			{
				if(node.left == null)
					node.left = new Nodes();
				node = node.left;
			}
			else
			{
				if(node.right == null)
					node.right = new Nodes();
				node = node.right;
			}
			maxx >>= 1;
		}
		node.setIndex(index);
	}
	static Nodes buildTree(int x[])
	{
		Nodes root = new Nodes();
		for (int i = 0; i < x.length; i++) {
			insertNode(root, x[i], i);
		}
		while(root.right != null)
			root = root.left;

		return root;
	}



	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int T = Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < T; i++) {

			String[] temp = br.readLine().trim().split(" ");
			int N = Integer.parseInt(temp[0].trim());
			int Q = Integer.parseInt(temp[1].trim());
			temp = br.readLine().trim().split(" ");
			int x[] = new int[N];

			for (int j = 0; j < N; j++) {
				x[j] = Integer.parseInt(temp[j].trim());
			}
			Nodes root = buildTree(x);
			for (int j = 0; j < Q; j++) {
				temp = br.readLine().trim().split(" ");
				int a = Integer.parseInt(temp[0]);
				int p = Integer.parseInt(temp[1]);
				int q = Integer.parseInt(temp[2]);;
				System.out.println(a ^ x[bestMatch(root, ~a, p-1, q-1)]);
			}
		}
	}
}