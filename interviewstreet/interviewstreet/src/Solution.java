import java.util.Scanner;
import java.util.Vector;

public class Solution 
{

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner (System.in);
		
		int N, D, i, j , currentindex;
		N = sc.nextInt();
		D = sc.nextInt();
		
		int [] pointx = new int [N];
		int [] pointy = new int [N];
		
		for(i=0;i<N;i++)
	    {
			pointx[i] = sc.nextInt();
			pointy[i] = sc.nextInt();
	    }
		
		Vector<Integer> outputpointx = new Vector<Integer>();
		Vector<Integer> outputpointy = new Vector<Integer>();
		
		outputpointx.addElement(new Integer (pointx[0]));
		outputpointy.addElement(new Integer (pointy[0]));
		
		currentindex = 0;
	    do
	    {
	        for(j=N-1; j>currentindex;j--)
	        {
	            float dist, slope;
	            slope = ((float)(pointy[j]-pointy[currentindex])/(pointx[j]-pointx[currentindex]));
	            boolean flag = true;

	            for(i=currentindex+1 ; i<j; i++)
	            {
	                dist = (slope*pointx[i]) - (slope*pointx[currentindex]) + pointy[currentindex];
	                float diff;
	                if(dist<pointy[i])
	                {
	                    diff = pointy[i]-dist;
	                }
	                else
	                {
	                    diff = dist - pointy[i];
	                }
	                if(diff>=D)
	                {
	                    flag = false;
	                    break;
	                }
	            }
	            if(flag)
	            {
	                outputpointx.addElement(new Integer (pointx[j]));
	                outputpointy.addElement(new Integer (pointy[j]));
	                currentindex = j;
	                break;
	            }
	        }
	    }while(currentindex!=N-1);
		
	    System.out.println(outputpointx.size());
	    for(i=0;i<outputpointx.size();i++)
	    {
	        System.out.println(outputpointx.elementAt(i) + " " + outputpointy.elementAt(i));
	    }
	    
	}

}
