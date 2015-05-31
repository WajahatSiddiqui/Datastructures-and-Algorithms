import java.util.Iterator;

// Driver program to simulate LinkedList Iterator
public class ListDriver {
	public ListDriver() {
		ListIterator<Integer> li = new ListIterator<Integer>();
		li.add(10);
		li.add(20);
		li.add(30);
		li.add(40);
		for (Integer i : li) {
			System.out.println(i);
		}
	}
	public static void main(String args[]) {
		new ListDriver();
	}

	// Class to define node
	class Node<T> {
		T mData;
		Node<T> mNext;
		public Node(T data, Node<T> next) {
			mData = data;
			mNext = next;
		}
	}

	// Iterator class
	class ListIterator<T> implements Iterator<T>, Iterable<T> {
		private Node<T> mHead = null, mIterator = null;
		private int mSize = 0, mIndex = 0;
		void push(T item) {
			Node<T> node = new Node<T>(item, mHead);
			mHead = node;
			mIterator = mHead;
			mSize++;
		}
		
		void add(T item) {
			Node<T> node = new Node<T>(item, null);
			Node<T> tmp = mHead, prev = null;
			while(tmp != null) {
				prev = tmp;
				tmp = tmp.mNext;
			}
			if (mHead == null) mHead = node;
			else {
				prev.mNext = node;
				node.mNext = tmp;
			}
			mIterator = mHead;
			mSize++;
		}

		@Override
		public boolean hasNext() {
			return mIndex < mSize;
		}

		@Override
		public T next() {
			if (mIterator == null || !hasNext()) return null;
			T data = mIterator.mData;
			if (mIterator != null) {
				mIndex++;
				mIterator = mIterator.mNext;
				
			} else {
				mIterator = mHead;
				mIndex = 0;
				return null;
			}
			return data;
		}

		@Override
		public void remove() {
		}

		@Override
		public Iterator<T> iterator() {
			return this;
		}
	}
}
