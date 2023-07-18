/*
 * Written by Jack Westbrock
 */

public class GenDoubleLinkedList <T>
{
	private class ListNode
	{
		T data;
		ListNode nextLink, prevLink;
		public ListNode(T aData, ListNode aNext, ListNode aPrev)
		{
			data = aData;
			nextLink = aNext;
			prevLink = aPrev;
		}
	}
	
	private ListNode head;
	private ListNode current;
	public GenDoubleLinkedList()// Constructor that initializes the head and current pointers to null
	{
		head = current = null;
	}
	public void gotoNext() // Moves the current pointer to the next node in the list
	{
		if(current == null)
			return;
		current = current.nextLink;
	}
	public void gotoPrev() // Moves the current pointer to the previous node in the list
	{
		if(current == null)
			return;
		current = current.prevLink;
	}
	public boolean hasMore() // Checks if there are more nodes in the list after the current node
	{
		return current != null;
	}
	public void reset() // Resets the current pointer to the head of the list
	{
		current = head;
	}
	public T getCurrent() // Returns the data stored in the current node
	{
		if(current == null)
			return null;
		return current.data;
	}
	public void setCurrent(T aData) // Sets the data of the current node to the given data
	{
		if(current != null)
			current.data = aData;
	}
	public void add(T aData) // Adds a new node with the given data at the end of the list
	{
		ListNode newNode = new ListNode(aData, null, null);
		if(head == null)
		{
			head = newNode;
			current = head;
			return;
		}
		ListNode temp = head;
		while(temp.nextLink != null)
			temp = temp.nextLink;
		temp.nextLink = newNode;
		newNode.prevLink = temp;
	}
	public void addAfterCurrent(T aData) // Adds a new node with the given data after the current node
	{
		if(current == null)
			return;
		ListNode newNode = new ListNode(aData, current.nextLink, current);
		if(current.nextLink != null)
			current.nextLink.prevLink = newNode;
		current.nextLink = newNode;
	}
	public void removeCurrent() // Removes the current node from the list
	{
		if(current == null)
			return;
		if(current == head)
		{
			head = head.nextLink;
			if(head != null)
				head.prevLink = null;
			current = head;
			return;
		}
		current.prevLink.nextLink = current.nextLink;
		if(current.nextLink != null)
			current.nextLink.prevLink = current.prevLink;
		current = current.nextLink;
	}
	public void print() // Prints the data in each node of the list
	{
		ListNode temp = head;
		while(temp != null)
		{
			System.out.println(temp.data);
			temp = temp.nextLink;
		}
	}
	public boolean contains(T aData) // Checks if the list contains a node with the given dat
	{
		for(ListNode temp = head; temp != null; temp = temp.nextLink)
			if(temp.data.equals(aData))
				return true;
		return false;
	}
}
