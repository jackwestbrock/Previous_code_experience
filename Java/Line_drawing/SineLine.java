//Jack Westbrock
public class SineLine implements Line{
	private double amplitude;//set instances
	private double frequency;
	public SineLine()
	{
		this.amplitude = 0.0;//set defaults
		this.frequency = 0.0;
	}
	public SineLine(double a, double f)
	{
		this.setAmplitude(a);//call mutators
		this.setFrequency(f);
	}
	public double getAmplitude()//get the instances
	{
		return this.amplitude;
	}
	public double getFrequency()
	{
		return this.frequency;
	}
	public void setAmplitude(double a)//set the mutators
	{
		this.amplitude = a;
	}
	public void setFrequency(double f)
	{
		this.frequency = f;
	}
	public double getYPoint(double x)
	{
		return this.amplitude * Math.sin(x*this.frequency);//find the y coord by amp times sin of x times freq
	}
}
