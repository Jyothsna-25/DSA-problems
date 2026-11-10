package Wiprotraining;

class LinkedList1{
	Node head;
	LinkedList1(){
		head=null;
	}
	
	class Node{
		int data;
		Node next;
		Node(int d){
			data = d;
			next = null;
		}
	}
	
	public void insertAtFirst(int d) {
		Node newnode = new Node(d);
		if(head == null) {
			head = newnode;
		}
		else {
			newnode.next = head;
			head = newnode;
		}
	}
	
	public void insertAtLast(int d) {
		Node newnode = new Node(d);
		if(head == null) {
			head = newnode;
		}
		else {
			Node temp = head;
			while(temp.next!=null) {
				temp=temp.next;
			}
			
			temp.next = newnode;
		}
	}
	
	public void display() {
		System.out.println("The elements in the linekd List: ");
		if(head == null) {
			System.out.println("The linked list is empty");
			return;
		}
		else {
			Node temp = head;
			while(temp!=null) {
				System.out.print(temp.data+" ");
				temp=temp.next;
			}
			System.out.println();
		}
	}
	
	public void deleteAtFirst() {
		System.out.println("Deletion at First of Linked List: ");
		if(head == null) {
			System.out.println("The linked list is empty");
			return;
		}
		else {
			head = head.next;
		}
	}
	public void deleteAtLast() {
		System.out.println("Deletion at Last of Linked List: ");
		if(head == null) {
			System.out.println("The linked list is empty");
			return;
		}
		else if(head.next == null) {
			head = null;
		}
		else {
			Node temp = head;
			while(temp.next.next!=null) {
				temp=temp.next;
			}
			temp.next = null;
		}
	}
	
	public void displayKthNode(int k) {
		if(head == null) {
			System.out.println("the linked list is empty");
			return;
		}
		else {
			int count = 1;
			Node temp = head;
			while(k!=count) {
				temp = temp.next;
				count++;
			}
			System.out.println("Displaying "+k+"th node of Linked List: "+temp.data);
		}
	}
	
	public void insert_at_middle(int d) {
		System.out.println("Insertion at the middle of the linked list: ");
		Node newnode = new Node(d);
		if(head == null || head.next == null) {
			newnode.next = head;
			head = newnode;
			return;
		}
		else {
			Node slow = head;
			Node fast = head;
			Node prev = null;
			
			while(fast!=null && fast.next!=null) {
				prev = slow;
				slow = slow.next;
				fast=fast.next.next;
			}
			
			prev.next = newnode;
			newnode.next = slow;
		}
	}
	
	public void delete_at_middle() {
		System.out.println("Deletion at the middle of the linked list: ");
		if(head == null || head.next == null) {
			System.out.println("The list is empty");
			return;
		}
		else {
			Node slow = head;
			Node fast = head;
			Node prev = null;
			
			while(fast!=null && fast.next!=null) {
				prev = slow;
				slow = slow.next;
				fast=fast.next.next;
			}
			
			prev.next = slow.next;
			slow.next = null;
		}
	}
	
	public void countNodes() {
		System.out.println("The number of nodes in a linked list: ");
		if(head == null) {
			System.out.println("The list is empty");
			return;
		}
		
		int count = 0;
		Node temp = head;
		while(temp!=null) {
			count++;
			temp = temp.next;
		}
		
		System.out.println("Count: "+count);
	}
	
	public void printPrimeNumbers() {
		System.out.println("The prime numbers of a linked list are: ");
		if(head == null) {
			System.out.println("The list is empty");
			return;
		}
		
		Node temp = head;
		while(temp!=null) {
			int n = temp.data;
			boolean flag = true;
			if(n<=1) {
				flag = false;
			}
			else {
				for(int i=2;i<=n/2;i++) {
					if(n%i==0) {
						flag = false;
					}
				}
			}
			if(flag) {
				System.out.print(n+" ");
			}
			
			temp = temp.next;
		}
		System.out.println();
	}
	
	public void reverse() {
		
		Node next = null;
		Node current = head;
		Node prev = null;
		
		while(current!=null) {
			next = current.next;
			current.next = prev;
			prev = current;
			current=next;
		}
		head = prev;
		
	}
	
	public boolean floidDetectionAlgorithm() {
		Node fast = head;
		Node slow = head;
		while(fast!=null && fast.next!=null) {
			slow = slow.next;
			fast = fast.next.next;
			if(fast == slow) {
				return true;
			}
		}
		return false;
	}
	
	public boolean pallindrome() {
		
		Node temp = head;
		while(temp!=null) {
			if(head == null || head.next == null) {
				return true;
			}
			
			Node slow= head;
			Node fast = head;
			while(fast!=null && fast.next!=null) {
				slow = slow.next;
				fast = fast.next.next;
			}
			
			Node prev = null;
			Node current = slow;
			Node next = null;
			
			while(current!=null) {
				next = current.next;
				current.next = prev;
				prev = current;
				current = next;
			}
			
			Node first = head;
			Node second = prev;
			
			while(second!=null) {
				if(first.data!=second.data) return false;
				
				first=first.next;
				second=second.next;
			}
		}
			
			return true;
	}
}

public class SingleLinkedList {

	public static void main(String[] args) {
		
		LinkedList1 node = new LinkedList1();
		node.insertAtFirst(10);
		node.insertAtFirst(20);
		node.insertAtLast(7);
		node.insertAtLast(90);
		node.display();

		node.reverse();
		node.display();
		
		node.printPrimeNumbers();
		
		node.insert_at_middle(80);
		node.display();
		
		node.delete_at_middle();
		node.display();

		node.displayKthNode(3);
		
		node.deleteAtFirst();
		node.display();
		
		node.deleteAtLast();
		node.display();
		
		node.countNodes();
		
		System.out.println("Floid Detection: "+ node.floidDetectionAlgorithm());
		System.out.println("pallindrome: "+ node.pallindrome());
		
	}

}