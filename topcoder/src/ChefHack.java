import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.io.Writer;
import java.math.BigInteger;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.text.DecimalFormat;
import java.util.*; 


public class ChefHack {


 public static void main(String[] args) throws IOException {
      InputStream inputStream = System.in;
	  OutputStream outputStream = System.out;
	  InputReader in = new InputReader(inputStream);
	  OutputWriter out = new OutputWriter(outputStream);
	  ModSieve();
	int test = in.readInt();
	 CHEFHACK(test,in,out);
	  out.close();
	  }
      static int [] nPrimes = new int [10000008];
	  static boolean[] isPrime = new boolean[10000008]; //sieve
	  static long maxN = 10000007;
	
	  public static void CHEFHACK (int testCases,InputReader in,OutputWriter out){
	  for (int ii = 0;ii<testCases;ii++){
		  int N = in.readInt();
		  int aux = 0;
		  int res = 0;
		  int grid [][] = new int [N][N];
		  int gridH [][] = new int [N][N];
		  boolean gridHack [][] = new boolean [N][N];
		  for (int k=0;k<N;k++){
			  for (int l=0;l<N;l++){
				  aux =  in.readInt();
				  grid[k][l]= doHack(aux); 
			      gridH[k][l]= (isEven(aux)&& aux!=2)?1:-1; 
			  }
		  }
		  for (int k=0;k<N;k++){
			  for (int l = 0;l<N;l++){
				  if (gridH[k][l]!=1){
					  res+=grid[k][l];
					  gridHack[k][l]= true;
				  }else{
					  if (!(gridHack[k][l])){
					  res+= grid[k][l];
					  gridHack = Hackconnected(k,l,gridH,N,gridHack);
					  }else{
						  grid[k][l] = 0;
					  }
				  }
			  }
		  }
		
		  
		  out.printLine(res);
		
	  }
	   
  }
   public static void ModSieve()
  {
     Arrays.fill(isPrime,true);
     isPrime[0]=false;
     isPrime[1]=false;
     int p = 0;
     int e = 2;// counts 0 and 2
  //   int m=(int) Math.sqrt(n);
     for (int i=2; (i*i)<=maxN; i++){
        if (isPrime[i]){
       	  p+=1;
       	 nPrimes[i]=p;
           for (int k=i*i; k<=maxN; k+=i){
              isPrime[k]=false;
              if (isEven(k)){
           	   e+= 1;
           	   nPrimes[k]= e;
              }
           }
        }
     }

  } 
  
  public static boolean[][] Hackconnected (int i, int j, int grid[][],int N,boolean hGrid[][]){
	  int aux = 1; 
	    if ((i>0)&&(grid[i-1][j]==aux) &&!(hGrid[i-1][j])){hGrid[i-1][j]= true; hGrid = Hackconnected(i-1,j,grid,N,hGrid);}
	    if ((j>0)&&(grid[i][j-1]==aux)&&!(hGrid[i][j-1])){hGrid[i][j-1]= true;hGrid = Hackconnected(i,j-1,grid,N,hGrid);}
	    if ((i<(N-1))&&(grid[i+1][j]==aux)&& !(hGrid[i+1][j])){hGrid[i+1][j]= true;hGrid =Hackconnected(i+1,j,grid,N,hGrid);}
	    if ((j<(N-1))&&(grid[i][j+1]==aux) &&!(hGrid[i][j+1])){hGrid[i][j+1]= true;hGrid = Hackconnected(i,j+1,grid,N,hGrid);} 
  return hGrid;
  }
  
  public static int doHack(int num){
	  int res = 0;
	  if (isPrime[num]){
		  res = (nPrimes[num]-1);
	  }else {
	  if (isEven(num) && num!= 2){
		 res = (nPrimes[num]-1); 
	  }else{
		  res =(nPrimes[num+1]);  
	  }
	  }
	 return res; 
  }
  
  
   // Even Odd
   public static boolean isEven (int num){
	   return ((num&1)==0);
   }

  }
  class InputReader {
private InputStream stream;
private byte[] buf = new byte[1024];
private int curChar;
private int numChars;
public InputReader(InputStream stream) {
this.stream = stream;
}
public int read() {
if (numChars == -1)
throw new InputMismatchException();
if (curChar >= numChars) {
curChar = 0;
try {
numChars = stream.read(buf);
} catch (IOException e) {
throw new InputMismatchException();
}
if (numChars <= 0)
return -1;
}
return buf[curChar++];
}
public int readInt() {
int c = read();
while (isSpaceChar(c))
c = read();
int sgn = 1;
if (c == '-') {
sgn = -1;
c = read();
}
int res = 0;
do {
if (c < '0' || c > '9')
throw new InputMismatchException();
res *= 10;
res += c - '0';
c = read();
} while (!isSpaceChar(c));
return res * sgn;
}
public String readString() {
int c = read();
while (isSpaceChar(c))
c = read();
StringBuffer res = new StringBuffer();
do {
res.appendCodePoint(c);
c = read();
} while (!isSpaceChar(c));
return res.toString();
}
public static boolean isSpaceChar(int c) {
return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1 || c =='$';
}
public String next() {
return readString();
}
}
class OutputWriter {
private final PrintWriter writer;
public OutputWriter(OutputStream outputStream) {
writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
}
public OutputWriter(Writer writer) {
this.writer = new PrintWriter(writer);
}
public void print(Object...objects) {
for (int i = 0; i < objects.length; i++) {
if (i != 0)
writer.print(' ');
writer.print(objects[i]);
}
}
public void printLine(Object...objects) {
print(objects);
writer.println();
}
public void printLine(char[] array) {
writer.println(array);
}
public void close() {
writer.close();
}
} 