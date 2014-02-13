import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Scanner;


public class Compiler {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		int i,j = 0, len;
		String lastStr = null, line;
		BufferedReader inp = new BufferedReader (new InputStreamReader(System.in));
		while((line=inp.readLine())!=null) {
			len = line.length();
			lastStr = "";
			for (i=0; i<len; i++) {
				if (i< len-1 && line.charAt(i) == '/' && line.charAt(i+1) == '/') {
					j = i;
					lastStr = line.substring(i, len);
					break;
				}
			}
			String str = line.substring(0, j);
			str = str.replace("->", ".");
			System.out.println(str + lastStr);
		}

	}

}