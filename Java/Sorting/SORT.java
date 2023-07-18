/*
 * Jack Westbrock
 */
import java.util.Scanner;

public class SORT {
	public static final int SIZE = 10;//size of array 
	public static void main(String args[])
	{
		Scanner scan = new Scanner(System.in);//define scanner
		System.out.println("Enter any number of strings and I will sort by SORT’s.  Once you’re done entering sentences enter “quit”.");
		SortCounter[] words = new SortCounter[SIZE];
		String input = "";//declares word varible
		int count = 0;
		while(count < SIZE)
		{
			input = scan.nextLine();//puts scanner in input
			if(input.equalsIgnoreCase("quit"))//if input is quit then stop
				break;
			words[count] = new SortCounter(input);//put the word into the array to be used later
			count++;//iterate the position of the 
		}
		mergeSort(words);//calls on the merge sort method with the array input
		System.out.println("sort SORTED!");
		for(SortCounter s : words)//for statement that prints all the words in the oder from least sorts to most
		{
			if(s == null)
				break;
			System.out.println(s.getStr());
		}
		
	}
	public static void mergeSort(SortCounter[] sortArr)//method that sorts an array by merge sort
	{
		int size = sortArr.length;//size of the array
		if(size < 2)//means if the array is only one element
			return;
		int mid = size/2;//int where to split the array into two
		int leftSize = mid;// size of the left array will be the mid 
		int rightSize = size - mid;//right side of the array will be sized 
		SortCounter[] left = new SortCounter[leftSize];//creates the arrays 
		SortCounter[] right = new SortCounter[rightSize];
		for(int i = 0; i < mid; i++)//populates the arrays
			left[i] = sortArr[i];
		for(int i = mid; i < size; i++)
			right[i-mid] = sortArr[i];
		mergeSort(left);
		mergeSort(right);
		merge(left, right, sortArr);//merge sorts the arrays
	}
	public static void merge(SortCounter[] left, SortCounter[] right, SortCounter[] a)//method that takes in tow arrays and sorts them into 1
	{
		int leftSize = left.length;//defines the lengths
		int rightSize = right.length;
		int i = 0; //Index for left array
		int j = 0;//Index for right array
		int k = 0;//index for the merged array a
		while (i < leftSize && j < rightSize)//while there are still elements not sorted
		{
			if(left[i] == null || right[j] ==null)//if the elements are null stop
				break;
			if(left[i].getNumberOfSorts() < right[j].getNumberOfSorts())//if the left element is less then the right element
			{
				a[k] = left[i];//add the left element to the combined array and iterate
				i++;
				k++;
			}
			else
			{
				a[k] = right[j];//add the right element to the combined array and iterate
				j++;
				k++;
			}
		}
		while(i < leftSize)//adds any remaining elements to the array
		{
			a[k] = left[i];
			i++;
			k++;
		}
		while(j < rightSize)//adds any remaining elements to the array
		{
			a[k] = right[j];
			j++;
			k++;
		}
	}
}
