import java.util.Scanner;


public class PenguinTiles {

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		String [] tiles = null;
		tiles[0] = "PPPPPPPP\n";
		tiles[1] = ".PPPPPPP\n";
		System.out.println(minMoves(tiles));
		
	}
	public static int minMoves(String[] tiles)
	{
		int steps=0, len;
		len = tiles.length;
		System.out.println(len);
		
		return steps;
	}

}
