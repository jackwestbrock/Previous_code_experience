/*
 * Jack Westbrock
 */
public class Fruit implements Comparable <Fruit>{
	private double weight = 0.0;//instance variables for defining a fruit
	private String type; 
	public Fruit()//default constructor
	{
		this.weight = 1.0;
		this.type = "apple";
	}
	public Fruit(double aW, String aT)//parameterized method
	{
		this.setWeight(aW);
		this.setType(aT);
	}
	public double getWeight()//accessor methods to get the variables
	{
		return this.weight;
	}
	public String getType()
	{
		return this.type;
	}
	public void setWeight(double aW)//mutator methods
	{
		if(aW <= 0.0)//if weight is negative set to default 0
			this.weight = 1.0;
		else
			this.weight = aW;//if not set to input
	}
	public void setType(String aT)
	{
		if(aT != null && ((aT.equalsIgnoreCase("apple")) || (aT.equalsIgnoreCase("orange")) || (aT.equalsIgnoreCase("bannana")) || 
				(aT.equalsIgnoreCase("kiwi")) || (aT.equalsIgnoreCase("tomato"))))//if not null or equal to a valid fruit then set to input
			this.type = aT;
		else
			this.type = "apple";//if not then set to default
	}
	public String toString()//method that returns the type and weight of the fruit
	{
		return this.type + " " + this.weight;
	}
	public int compareTo(Fruit aFruit)//returns an integer value based on the fruits weight and type
	{
		if(aFruit == null)
			return -1;
		if(this.weight < aFruit.getWeight())
			return -1;
		else if(this.weight > aFruit.getWeight())
			return 1;
		else
			return this.type.compareTo(aFruit.getType());
	}
}
