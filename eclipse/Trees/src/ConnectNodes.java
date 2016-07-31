import java.util.ArrayDeque;
import java.util.Queue;


public class ConnectNodes {
	private static class TreeNode {
		int data;
		TreeNode left, right;
		TreeNode nextRight;
		
		public TreeNode(int data) {
			this.data = data;
			left = right = nextRight = null;
		}
	}
	
	public static TreeNode insert(TreeNode root, int data) {
		TreeNode node = new TreeNode(data);
		if (root == null) root = node;
		else if (data < root.data)
			root.left = insert(root.left, data);
		else
			root.right = insert(root.right, data);
		return root;
	}
	
	public static void print(TreeNode root) {
		if (root == null) return;
		print(root.left);
		int next = root.nextRight != null ? root.nextRight.data : -1;
		System.out.println(root.data+ " " + next);
		print(root.right);
	}
	
	private static class QNode {
		TreeNode node;
		int level;
		public QNode(TreeNode node, int level) {
			this.node = node;
			this.level = level;
		}
	}
	
	public static TreeNode connectNodes(TreeNode root) {
		if (root == null) return null;
		Queue<QNode> Q = new ArrayDeque<>();
		Q.add(new QNode(root, 0));
		QNode front;
		while (!Q.isEmpty()) {
			front = Q.poll();
			if (front.node.left != null) {
				Q.add(new QNode(front.node.left, front.level+1));
			}
			if (front.node.right != null) {
				Q.add(new QNode(front.node.right, front.level+1));
			}
			if (Q.peek() != null && front.level == Q.peek().level) {
				front.node.nextRight = Q.peek().node;
			} else {
				front.node.nextRight = null;
			}
		}
		return root;
	}
	
	public static void printlevel(TreeNode root) {
		TreeNode curr = root;
		TreeNode start;
		while (curr != null) {
			start = curr;
			while (start != null) {
				System.out.print(start.data + " ");
				start = start.nextRight;
			}
			System.out.println();
			if (curr.left != null)
				curr = curr.left;
			else
				curr = curr.right;
		}
	}
	
	public static void main(String args[]) {
		TreeNode root = null;
		root = insert(root, 20);
		root = insert(root, 10);
		root = insert(root, 30);
		root = insert(root, 5);
		root = insert(root, 15);
		root = insert(root, 25);
		root = insert(root, 1);
		root = insert(root, 11);
		root = insert(root, 26);
		System.out.println("Given Tree: ");
		print(root);
		System.out.println("After connecting the nodes: ");
		root = connectNodes(root);
		print(root);
		printlevel(root);
	}
}
