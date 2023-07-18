/*
 Jack Westbrock
 */
import java.util.Scanner;//import scanner

public class ByteConverter {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		System.out.println("Enter an 8 bit binary number and I will convert it to decimal");//prompt user
		String num = scan.nextLine();//store users input
		String initialNum = num;
		int decimal = 0;//declare that the minimum value of the binary to decimal could be 0
		
		String one = num.substring(7);//stores the last digit of the binary 
		int iOne = Integer.parseInt(one);//converts the number in the string to an integer
		if(iOne == 1)//if the integer is 1 and since its in the 2^0 column, 1 is added to the final decimal 
			decimal++;//adds 1 to the decimal
		
		String two = num.substring(6,7);//stores the second last digit of the binary
		int iTwo = Integer.parseInt(two);//converts the number in the string to an integer
		if(iTwo == 1)//if the integer is 1 and since its in the 2^1 column, 2 is added to the final decimal
			decimal+= 2;//adds 2 to the decimal
		
		String three = num.substring(5,6);
		int iThree = Integer.parseInt(three);//converts the number in the string to an integer
		if(iThree == 1)//if the integer is 1 and since its in the 2^2 column, 4 is added to the final decimal
			decimal+= 4;//adds 4 to the decimal
		
		String four = num.substring(4,5);
		int iFour = Integer.parseInt(four);//converts the number in the string to an integer
		if(iFour == 1)//if the integer is 1 and since its in the 2^3 column, 8 is added to the final decimal
			decimal+= 8;//adds 8 to the decimal
		
		String five = num.substring(3,4);
		int iFive = Integer.parseInt(five);//converts the number in the string to an integer
		if(iFive == 1)//if the integer is 1 and since its in the 2^4 column, 16 is added to the final decimal
			decimal+= 16;//adds 16 to the decimal
		
		String six = num.substring(2,3);
		int iSix = Integer.parseInt(six);//converts the number in the string to an integer
		if(iSix == 1)//if the integer is 1 and since its in the 2^5 column, 32 is added to the final decimal
			decimal+= 32;//adds 32 to the decimal
		
		String seven = num.substring(1,2);
		int iSeven = Integer.parseInt(seven);//converts the number in the string to an integer
		if(iSeven == 1)//if the integer is 1 and since its in the 2^6 column, 64 is added to the final decimal
			decimal+= 64;//adds 64 to the decimal
		
		String eight = num.substring(0,1);
		int iEight = Integer.parseInt(eight);//converts the number in the string to an integer
		if(iEight == 1)//if the integer is 1 and since its in the 2^7 column, 128 is added to the final decimal
			decimal+= 128;//adds 128 to the decimal
		
		System.out.println(initialNum + " in decimal form is " + decimal);//print the decimal form
		
	}

}
