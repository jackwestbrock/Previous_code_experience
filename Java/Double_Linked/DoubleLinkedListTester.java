/*
 * Written by Jack Westbrock
 */
public class DoubleLinkedListTester {
	public static final int[] TEST_VALS_1 = {0,1,2,3,4,5,6,7,8,9};
	public static final int[] TEST_VALS_2 = {1,3,4,5,6,7,8};
	public static final int[] TEST_VALS_3 = {1,3,-4,5,-6,7,-8};

	public static final String DEC = "------------------------------------------------------\n";
	public static void main(String[] args) {
		printDecorated("Double Linked List Tester");
		GenDoubleLinkedList<Integer> intList = new GenDoubleLinkedList<Integer>(); // Create an instance of the double linked list.
		//perform tests and print result
		System.out.println("SUCCESS: "+insertAndContainsTest(intList)+"\n");
		System.out.println("SUCCESS: "+deleteTest(intList)+"\n");
		System.out.println("SUCCESS: "+modifyingValuesTest(intList)+"\n");
		
		printDecorated("Printing the list");
		intList.print();
	}
	
	public static boolean insertAndContainsTest(GenDoubleLinkedList<Integer> intList) // Test method for inserting values and checking if they exist in the list.
	{
		printDecorated("Inserting and Contains Test");
		for(int i=0;i<TEST_VALS_1.length;i++) // Insert the test values into the list.
			intList.add(TEST_VALS_1[i]);
		return valuesMatch(intList,TEST_VALS_1); // Check if the values match the expected test values.
	}
	public static boolean deleteTest(GenDoubleLinkedList<Integer> intList) // Test method for deleting values from the list.
	{
		printDecorated("Removing Test\nRemoving first item, third item, and last item");
		intList.reset(); // Reset the list and remove the first item.
		intList.removeCurrent();
		
		intList.gotoNext(); // Move to the next node and remove it.
		intList.removeCurrent();

		for(int i=0;i<6;i++) // Move to the sixth node and remove it.
			intList.gotoNext();
		intList.removeCurrent();
		// Check if the resulting list matches the expected values.
		return valuesMatch(intList,TEST_VALS_2) && valuesNotMatch(intList,TEST_VALS_4);
	}
	public static boolean modifyingValuesTest(GenDoubleLinkedList<Integer> intList) // Test method for modifying values in the list.
	{
		printDecorated("Modified Values Test\nChanging all even values to negative values");
		intList.reset();
		while(intList.hasMore())
		{
			if(intList.getCurrent() % 2 == 0)
				intList.setCurrent(-intList.getCurrent());
			intList.gotoNext();
		}
		
		return valuesMatch(intList,TEST_VALS_3);
	}
	public static boolean valuesMatch(GenDoubleLinkedList<Integer> intList, int[] testVals) // Helper method to check if the values in the list match the expected test values.
	{
		for(int i=0;i<testVals.length;i++)
			if(!intList.contains(testVals[i]))
				return false;
		return true;
	}
	public static final int[] TEST_VALS_4 = {0,2,9}; // Define an additional array of test values.

	public static boolean valuesNotMatch(GenDoubleLinkedList<Integer> intList, int[] testVals) // Helper method to check if the values in the list do not match the test values.
	{
		for(int i=0;i<testVals.length;i++)
			if(intList.contains(testVals[i]))
				return false;
		return true;
	}
	public static void printDecorated(String str) // Helper method to print a decorated string.
	{
		System.out.println(DEC+str+"\n"+DEC);
	}
}