import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Hackerearth1 {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		for (;;) {
			String line = in.next();
			String[] lines = line.split("\\/\\/");
			if (lines.length > 1) {
				lines[0] = lines[0].replace("->", ".");
				System.out.println(lines[0] + "//" + lines[1]);
			} else
				System.out.println(line);
		}
	}

}