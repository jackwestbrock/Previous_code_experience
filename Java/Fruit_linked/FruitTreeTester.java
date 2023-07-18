/*
 * Jack Westbrock
 */
import java.util.*;
import java.io.*;
public class FruitTreeTester {

	public static void main(String[] args) {
		System.out.println("Welcome to the fruit tree!\n" + 
				"Please enter a Fruit File Name");//prompts user
		Scanner scan = new Scanner(System.in);//creates scanner
		String fileName = scan.nextLine();//takes users file and stores
		System.out.println("Populating tree file");
		
		LinkedBST<Fruit> fruitTree = new LinkedBST<Fruit>();//creates new instance of tree
		try
		{
			Scanner fileScan = new Scanner(new File(fileName));//scans for the file given
			while(fileScan.hasNextLine())//continues to run as long as there is a next line in the file
			{
				String currLine = fileScan.nextLine();//takes the strings on the line stores it in currLine
				String[] splitLine = currLine.split("\t");//takes the currLine and splits where the tab to separate wieght and fruit
				if(splitLine.length == 2)//if the string is populated correctly
				{
					Fruit f = new Fruit(Double.parseDouble(splitLine[1]),splitLine[0]);//changes the weight from string to a double
					fruitTree.add(f);//adds to the tree
				}
			}
			fileScan.close();//closes file scanner
		}
		catch(Exception e)
		{
			e.printStackTrace();
		}
		System.out.println("Printing the in-order traversal");//prints the values of the tree inorder preorder and postorder
		fruitTree.printInorder();
		System.out.println("\nPrinting the pre-order traversal");
		fruitTree.printPreorder();
		System.out.println("\nPrinting the post-order traversal");
		fruitTree.printPostorder();
		System.out.println(fruitTree.search(new Fruit(0.4859853412170728, "Apple")));//searches for specific fruit
		System.out.println("\nDeleting Apple 0.4859853412170728");
		System.out.println("Printing in-order traversal");
		fruitTree.printInorder();//prints the inorder again with out that fruit
	}

}
