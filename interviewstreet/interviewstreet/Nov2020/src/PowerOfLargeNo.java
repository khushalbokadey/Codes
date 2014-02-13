import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.math.BigInteger;
import java.util.HashMap;
import java.util.Map;


public class PowerOfLargeNo {

	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new FileReader("/Users/khushal/Documents/khushal/Codes/interviewstreet/interviewstreet/Nov2020/src/input.txt"));
		int T;
		BigInteger A, B, modConst, answer, currVal;
		String strA, strB, ip[];
		Map<BigInteger, BigInteger> data;
		T = Integer.parseInt(reader.readLine());
		modConst = new BigInteger("1000000007");
		while(T != 0) {
			strA = reader.readLine();
			ip = strA.split(" ");
			strA = ip[0];
			strB = ip[1];
			A = new BigInteger(strA);
			B = new BigInteger(strB);
			data = new HashMap<BigInteger, BigInteger>();
			currVal = new BigInteger("1");
			answer = A;
			data.put(currVal, answer);
			while(currVal.add(currVal).compareTo(B) == -1) {
				answer = answer.mod(modConst).multiply((answer.mod(modConst)));
				currVal = currVal.add(currVal);
				data.put(currVal, answer);
			}
			while (currVal.compareTo(B) != 1) {
				answer = answer.mod(modConst).multiply(A.mod(modConst));
				currV
			}
			System.out.println(strA + " " + strB);
			T--;
		}
	}

}
