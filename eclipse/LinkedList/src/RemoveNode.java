import java.util.Scanner;


public class RemoveNode {
	static class Node {
		int val;
		Node next;
		public Node(int val) {
			this.val = val;
			next = null;
		}
	}
	public static Node insert(Node head, Node tail, int item) {
		if (head == null) {
			head = new Node(item);
			tail = head;
		} else {
			tail.next = new Node(item);
			tail = tail.next;
		}
		return tail;
	}
	
	public static void print(Node head) {
		if (head == null) return;
		Node curr = head;
		while (curr != null) {
			System.out.print(curr.val + " ");
			curr = curr.next;
		}
		System.out.println();
	}
	
	public static Node removeNode(Node head, int x) {
		if (head == null) return head;
		Node curr = head, prev = null;
		while (curr != null) {
			if (curr.val > x) {
				if (curr == head) {
					head = curr.next;
					curr.next = null;
					prev = curr = head;
				} else if (curr.next == null) {
					prev.next = null;
					curr = null;
				} else {
					prev.next = curr.next;
					curr.next = null;
					curr = prev.next;
				}
			} else {
				prev = curr;
				curr = curr.next;
			}
		}
		return head;
	}
	
	public static void main(String args[]) {
		Scanner scanner = new Scanner(System.in);
		int n = scanner.nextInt();
		int item;
		Node head = null, tail = null;
		for (int i = 0; i < n; i++) {
			item = scanner.nextInt();
			if (i == 0) {
				head = insert(head, tail, item);
				tail = head;
			} else {
				tail = insert(head, tail, item);
			}
		}
		print(head);
		int x = scanner.nextInt();
		head = removeNode(head, x);
		print(head);
		scanner.close();
	}
}
