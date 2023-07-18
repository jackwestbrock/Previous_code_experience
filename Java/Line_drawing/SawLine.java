//Jack Westbrock
public class SawLine implements Line {
	private double modValue;//create instance
	public SawLine()
	{
		this.modValue = 1.0;//set default
	}
	public SawLine(double aMV)
	{
		this.setModValue(aMV);//call mutator
	}
	public double getModValue()//get instance
	{
		return this.modValue;
	}
	public void setModValue(double aMV)//set mutator
	{
		if(aMV == 0.0)//checks if valid
			this.modValue = 1.0;
		else
			this.modValue = aMV;
	}
	public double getYPoint(double x)
	{
		return x % this.modValue;//finds the y coord by finding x coord mod the value
	}
}
