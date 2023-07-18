/*
 * Jack Westbrock
 */
import java.awt.*;
import javax.swing.*;
import java.util.*;
public class Triangles extends JPanel{
	//private static final long serialVersionUID = 1L;
	public static void main(String[] args)
	{
		JFrame.setDefaultLookAndFeelDecorated(true);
		JFrame frame = new JFrame("Triangle");//creates new frame
		frame.setSize(900,900);//sets the size
		frame.setVisible(true);
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);//closes when done
		Triangles panel = new Triangles();//creates new triangle
		frame.add(panel);//adds the triangle to the frame
	}
	public void paint(Graphics g) //method that paints the first black triangle
	{
		int[] x = {375,720,30};//coordinates for the big triangle
		int[] y = {30,720,720};
		g.fillPolygon(x,y,3);//fills in the space between the 3 points
		g.setColor(new Color(255,255,255));//now sets the new color of triangles to white
		serpinskiDraw(x,y,g);//calls on the serpinski method for a new triangle
	}
	public void serpinskiDraw(int x[], int y[],Graphics g)//method that adds a white triangle inside of each black triangle
	{
		int pixelDistance = Math.abs(x[0]-x[1]);//finds the distance between a pixel
		if(pixelDistance <= 4)//if distance is less than four then no more triangles are made
			return;
		else
		{
			int midx[] = {(x[0]+x[1])/2 ,(x[1]+x[2])/2,(x[2]+x[0])/2};//finds the mid points of the sides
			int midy[] = {(y[0]+y[1])/2 ,(y[1]+y[2])/2,(y[2]+y[0])/2};
			g.fillPolygon(midx, midy, 3);//fills in the space between the mid points with a white triangle
			int x1[] = {x[0],midx[0],midx[2]};//makes new arrays for the new triangles to be filled in
			int y1[] = {y[0],midy[0],midy[2]};
			int x2[] = {midx[0],x[1],midx[1]};
			int y2[] = {midy[0],y[1],midy[1]};
			int x3[] = {midx[2],midx[1],x[2]};
			int y3[] = {midy[2],midy[1],y[2]};
			serpinskiDraw(x1,y1,g);//calls serpinksi 3 more times to fill in 3 new white triangles for every white triangle created
			serpinskiDraw(x2,y2,g);
			serpinskiDraw(x3,y3,g);
		}
	}
}
