
public class PlatypusDuckAndBeaver 
{

	/**
	 * @param args
	 */
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		
		System.out.println(minimumAnimals(60, 10, 10));

	}
	
	public static int minimumAnimals(int webbedFeet, int duckBills, int beaverTails)
	{
		
		int ducks , beaver , platy , total=0;
		
		ducks = (webbedFeet/2) - (2*beaverTails);
		platy = duckBills - ducks;
		beaver = beaverTails - platy;
		
		total = ducks + platy + beaver;
		
		return total;
		
	}

}
