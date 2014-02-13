import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Bot {

	public static void main(String[] args) throws Exception {
		
		int T, i, j, lenA, lenB;
		int[] arrA1 = new int [1000003];
		int[] arrA2 = new int [1000003];
		int[] arrB1 = new int [1000003];
		int[] arrB2 = new int [1000003];		
		String line;
		BufferedReader reader = new BufferedReader (new InputStreamReader(System.in));
		T = Integer.parseInt(reader.readLine());
		while(T != 0) {
			line = reader.readLine();
			String[] parts = line.split(" ");
			lenA = parts[0].length();
			lenB = parts[1].length();
			
			if (lenA != lenB) {
				System.out.println("No");
				continue;
			}
			
			for (i=0; i<lenA; i++) {
				arrA1[i] = 0;
				arrB1[i] = 0;
			}
			for (i=0; i<lenB; i++) {
				arrA2[i] = 0;
				arrB2[i] = 0;
			}
			
			arrB1[0] = 0;
			if (parts[0].charAt(0) == 'B')
				arrB1[0] = 1;
			arrB2[0] = 0;
			if (parts[1].charAt(0) == 'B')
				arrB2[0] = 1;
			
			arrA1[lenA-1] = 0;
			if (parts[0].charAt(lenA-1) == 'A')
				arrA1[lenA-1] = 1;
			arrA2[lenB-1] = 0;
			if (parts[1].charAt(lenB-1) == 'A')
				arrA1[lenB-1] = 1;
			
			for (i=1; i<lenA; i++) {
				arrB1[i] = arrB1[i-1];
				if (parts[0].charAt(i) == 'B') {
					arrB1[i] = arrB1[i-1] + 1;
				}
			}
			
			for (i=lenA-2; i>=0; i--) {
				arrA1[i] = arrA1[i+1];
				if (parts[0].charAt(i) == 'A') {
					arrA1[i] = arrA1[i+1] + 1;
				}
			}
			
			for (i=1; i<lenB; i++) {
				arrB2[i] = arrB2[i-1];
				if (parts[1].charAt(i) == 'B') {
					arrB2[i] = arrB2[i-1] + 1;
				}
			}
			
			for (i=lenB-2; i>=0; i--) {
				arrA2[i] = arrA2[i+1];
				if (parts[1].charAt(i) == 'A') {
					arrA2[i] = arrA2[i+1] + 1;
				}
			}
			

//			for (i=0; i<lenA; i++) {
//				System.out.println(arrA1[i] + " " + arrA2[i] + " " + arrB1[i] + " " + arrB2[i]);
//			}
			
			parts[0] = parts[0].replace("#", "");
			parts[1] = parts[1].replace("#", "");
			if (parts[0].equals(parts[1])) {
				boolean flag = false;
				for (i=0; i<lenA; i++) {
					if (arrB1[i] < arrB2[i]) {
						//System.out.println(arrB1[i] + " " + arrB2[i]);
						System.out.println("No");
						flag = true;
						break;
					}
					if (arrA1[i] < arrA2[i]) {
						//System.out.println(arrA1[i] + " " + arrA2[i]);
						System.out.println("No");
						flag = true;
						break;
					}
				}
				if (flag) 
					continue;
				System.out.println("Yes");
			}
			else 
				System.out.println("No");
			T--;
		}

	}

}
