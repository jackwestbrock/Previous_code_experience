/*
 Jack Westbrock
 */
import java.util.Scanner;

public class octalCalculator {
	public static final int EIGHT_0 = (int)Math.pow(8,0);//define constants
	public static final int EIGHT_1 = (int)Math.pow(8,1);
	public static final int EIGHT_2 = (int)Math.pow(8,2);
	public static final int EIGHT_3 = (int)Math.pow(8,3);

	public static void main(String[] args) {
		System.out.println("Enter a 4 digit octal number");
		Scanner scan = new Scanner(System.in);
		String num1 = scan.nextLine();//stores the input of the octal in a string
		System.out.println("Enter another 4 digit octal number");
		String num2 = scan.nextLine();
		
		String num11 = num1.substring(0,1);//the next several lines separates the octal into separate numbers and then converts them into an octal 
		int iNum11 = Integer.parseInt(num11);
		String num12 = num1.substring(1,2);
		int iNum12 = Integer.parseInt(num12);
		String num13 = num1.substring(2,3);
		int iNum13 = Integer.parseInt(num13);
		String num14 = num1.substring(3,4);
		int iNum14 = Integer.parseInt(num14);
		
		int decimal1 = (iNum11* EIGHT_3) + (iNum12* EIGHT_2) + (iNum13* EIGHT_1) + (iNum14* EIGHT_0); //converts to decimal form by multiplying each number by the position its in
		
		String num21 = num2.substring(0,1);//does the same thing as the first one 
		int iNum21 = Integer.parseInt(num21);
		String num22 = num2.substring(1,2);
		int iNum22 = Integer.parseInt(num22);
		String num23 = num2.substring(2,3);
		int iNum23 = Integer.parseInt(num23);
		String num24 = num2.substring(3,4);
		int iNum24 = Integer.parseInt(num24);
		
		int decimal2 = (iNum21* EIGHT_3) + (iNum22* EIGHT_2) + (iNum23* EIGHT_1) + (iNum24* EIGHT_0); //converts to decimal
		
		int numCombCopy = decimal1 + decimal2;//adds the two numbers
		int numComb = numCombCopy;
		String octNum = "";//defines the string for the octal number of the combined decimal number
		int eight3 = numComb/EIGHT_3; //figures out if 512 can fit into the number
		if(0 == eight3)//if 512 cannot fit in then the first number is 0
			octNum = "0";
		if(0 != eight3) {
			octNum = Integer.toString(eight3);//if not the number of 512 can go into the number is the first digit of the octal
			numComb = numComb % EIGHT_3;//makes the comb number what ever the remainder is of the number divided my 512
		}
			
		
		int eight2 = numComb/EIGHT_2;//figures of if 64 can fit into the remainder number
		if(0 == eight2)
			octNum = octNum.concat(Integer.toString(eight2));//if not 2nd number in the octal is 0
		if(0 != eight2) {
			octNum = octNum.concat(Integer.toString(eight2));//if so makes the second number that number
			numComb = numComb % EIGHT_2;//makes the remainder the new numb
		}
			
		int eight1 = numComb/EIGHT_1;//figure out if 8 can fit into the remainder number
		if(0 == eight1)
			octNum = octNum.concat(Integer.toString(eight1));
		if(0 != eight1) {
			octNum = octNum.concat(Integer.toString(eight1));
			numComb = numComb % EIGHT_1;
		}
			
		int eight0 = numComb/EIGHT_0;//makes teh last number of the octal what ever the remainder is from the last remainder
		if(0 == eight0)
			octNum = octNum.concat(Integer.toString(eight0));
		if(0 != eight0) {
			octNum = octNum.concat(Integer.toString(eight0));
			numComb = numComb % EIGHT_0;
		}
		
		System.out.println("The first number is " + decimal1);
		System.out.println("The second number is " + decimal2);
		System.out.println("Added together is " + numCombCopy);
		System.out.println("Which is " + octNum + " in octal");//prints out the results
	}

}
