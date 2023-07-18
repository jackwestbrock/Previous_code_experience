//Jack Westbrock
public class StaircaseLine implements Line{
	private double width;//set instances
	private double height;
	public StaircaseLine()
	{
		this.width = 1.0;//set defaults
		this.height = 1.0;
	}
	public StaircaseLine(double aW, double aH)
	{
		this.setHeight(aH);//call mutators
		this.setWidth(aW);
	}
	public double getWidth()//get the instances
	{
		return this.width;
	}
	public double getHeight()
	{
		return this.height;
	}
	public void setWidth(double aW)//set the mutators
	{
		if(aW < 0)//check if values are valid
			this.width = 1.0;
		else
			this.width = aW;
	}
	public void setHeight(double aH)
	{
		if(aH < 0)
			this.height = 1.0;
		else
			this.height = aH;
	}
	public double getYPoint(double x)
	{
		return ((int)(x/this.width))* this.height; //finds y coord by x divided by width times height
	}
}
