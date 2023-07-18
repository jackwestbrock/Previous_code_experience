//Jack Westbrock
public class SlopedLine implements Line{//implements uses the instence from line
	private double slope;//create instance
	public SlopedLine()
	{
		this.slope = 0.0;//set default
	}
	public SlopedLine(double m)
	{
		this.setSlope(m);//call mutator
	}
	
	public double getSlope()//get the instance
	{
		return this.slope;
	}
	public void setSlope(double m)//set the mutator
	{
		this.slope = m;
	}
	public double getYPoint(double x)
	{
		return x * this.slope;//find y coord by multiplying x by slope
	}
}
