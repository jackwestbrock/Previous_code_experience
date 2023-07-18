/*
 * Jack Westbrock
 */
public class SortCounter {
	private int numOfSorts;
	private String str;
	public SortCounter(String aStr)//default constructor
	{
		this.str = aStr;
		this.numOfSorts = 0;
		this.countSorts(aStr);
	}
	public int getNumberOfSorts()
	{
		return this.numOfSorts;
	}
	public String getStr()
	{
		return this.str;
	}
	public void countSorts(String aStr)//method that inputs a string and counts the number of times sort is counted
	{
		 if(aStr == null)//if string is null the return nothing
			 return;
		 aStr = aStr.toUpperCase();//takes string to all upper case
		 for(int i = 0; i < aStr.length()-3; i++)
		 {
			 if(aStr.charAt(i) == 'S' && //if sort is in the string then the numb is iterated
					 aStr.charAt(i+1) == 'O' && 
					 aStr.charAt(i+2) == 'R' && 
					 aStr.charAt(i+3) == 'T')
			 {
				 this.numOfSorts++;
			 }
		 }
	}
	
}
