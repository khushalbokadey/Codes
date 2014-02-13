import java.util.Arrays;


public class LittleElephantAndDouble {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int [] A = {4,2,8,1,16};
		int [] B = {1,2,3};
		int [] C = {148, 298, 1184};
		int [] D = {4,2,8,1,16};
		int [] E = {4,2,8,1,16};
		System.out.println(getAnswer(A));
		System.out.println(getAnswer(B));
		System.out.println(getAnswer(C));
		System.out.println(getAnswer(D));
		System.out.println(getAnswer(E));
	}
	
	public static String getAnswer(int[] A) {
		
		int i, j, size;
		String answer;
		Boolean flag;
		size = A.length;
		Arrays.sort(A);
		answer = "YES";
		flag = true;
		for (i=0; i<size; i++) {
			j = i+1;
			while (j < size) {
				if (A[j]%A[i] != 0) {
					flag = false;
					break;
				}
				j++;
			}
			if (!flag) {
				break;
			}
		}
		if (!flag)
			answer = "NO";
		
		return answer;
	}

}
