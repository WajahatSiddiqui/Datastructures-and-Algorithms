import java.util.HashMap;
import java.util.Map;
//import java.util.Integer;

class Node {
    int data;
    Node next;
    public Node(int d) {
        data = d;
        next = null;
    }
}

class LinkedList {
    Map<Integer, Node> mMap;
    Node mHead;
    int count = 1;
    public LinkedList() {
        mMap = new HashMap<Integer, Node>();
    }

    void push(int data) {
        Node node = new Node(data);
        node.next = mHead;
        mHead = node;
        mMap.put(count++, node);
    }

    void insert(int data) {
        Node node = new Node(data);
        if (mHead == null)
            mHead = node;
        else {
            Node temp = mHead;
            while (temp.next != null)
                temp = temp.next;
            temp.next = node;
        }
    }


    void printMap() {
        System.out.println("Key\tValue");
        System.out.println("-----\t----");
        for (int i = 1; i <= mMap.size(); i++)
            System.out.println(""+i+"\t"+mMap.get(i));
    }

    void print() {
        if (mHead == null)
            return;
        Node temp = mHead;
        while (temp != null) {
            System.out.println(""+temp.data);
            temp = temp.next;
        }
    }

    Node findNth(int n) {
        return mMap.get(mMap.size() - n +1);
    }
}

class findNth {
    public static void main(String args[]) {
        LinkedList linkedList = new LinkedList();
        /*linkedList.insert(1);
        linkedList.insert(2);
        linkedList.insert(3);
        linkedList.insert(4);
        linkedList.insert(5);*/
        linkedList.push(1);
        linkedList.push(2);
        linkedList.push(3);
        linkedList.push(4);
        linkedList.push(5);
        linkedList.print();
        System.out.println("** Printing Map **");
        linkedList.printMap();
        System.out.println("2nd Node from end: "+linkedList.findNth(2));
    }
}
