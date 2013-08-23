import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.BitSet;

class NewNode
{
	BitSet index = new BitSet();
	public NewNode left;
	public NewNode right;

	public NewNode getLeft() {
		return left;
	}

	public void setLeft(NewNode left) {
		this.left = left;
	}

	public NewNode getRight() {
		return right;
	}

	public void setRight(NewNode right) {
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

public class Stonegame {
	static int bestMatch(NewNode pRoot, int m, int p, int q) 
	{
		BitSet range = new BitSet();
		range.set(p, q+1);
		NewNode node = pRoot;

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

	static void insertNode(NewNode root, int x, int index)
	{
		int maxx = 1<<15;
		NewNode node = root;
		for (int i = 15; i >= 0; i--) {
			node.setIndex(index);
			int bit = (maxx & x);
			if(bit == 0)
			{
				if(node.left == null)
					node.left = new NewNode();
				node = node.left;
			}
			else
			{
				if(node.right == null)
					node.right = new NewNode();
				node = node.right;
			}
			
			maxx >>= 1;
		}
		node.setIndex(index);
	}
	static NewNode buildTree(int x[])
	{
		NewNode root = new NewNode();
		for (int i = 0; i < x.length; i++) {
			insertNode(root, x[i], i);
		}
		while(root.right != null)
		{
			root = root.left;
		}
		System.out.println();
		return root;
	}



	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int N = Integer.parseInt(br.readLine().trim());
		for (int i = 0; i < N; i++) 
		{
			String[] temp = br.readLine().trim().split(" ");
			int x[] = new int[N];
			for(int j=0; j<temp.length; j++)
			{
				x[j] = Integer.parseInt(temp[j].trim());
				System.out.println(x[j]);
			}

			NewNode root = buildTree(x);
			
			/*for (int j = 0; j < Q; j++) 
			{
				temp = br.readLine().trim().split(" ");
				int a = Integer.parseInt(temp[0]);
				int p = Integer.parseInt(temp[1]);
				int q = Integer.parseInt(temp[2]);;
				System.out.println(a ^ x[bestMatch(root, ~a, p-1, q-1)]);
			}*/
		}
	}
}