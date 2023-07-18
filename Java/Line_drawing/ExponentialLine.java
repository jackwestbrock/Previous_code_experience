//Jack Westbrock
public class ExponentialLine implements Line{
	private double exponent;//set instance
	public ExponentialLine()
	{
		this.exponent = 0.0;//set default
	}
	public ExponentialLine(double ex)
	{
		this.setExponent(ex);//call mutator
	}
	public double getExponent()//get instance
	{
		return this.exponent;
	}
	public void setExponent(double ex)//set mutator
	{
		this.exponent = ex;
	}
	public double getYPoint(double x)
	{
		return Math.pow(x, this.exponent);//get y coordinate by taking x to the power of exponent
	}
}
