// Designing Custom Hash Table 
// with a very simple hash function

import java.util.LinkedList;

class Cell<Key, Value> {
	private Key k;
	private Value v;
	
	public Cell(Key k, Value v) {
		this.k = k;
		this.v = v;
	}
	Key getKey() { return this.k; }
	Value getValue() { return this.v; }
	
	public boolean equivalent(Key k) {
		return k.equals(this.k);
	}
}

public class Hash<Key, Value> {
	private LinkedList<Cell<Key, Value>>[] mLinkedList;
	private int mSize;
	
	public Hash(int size) {
		mSize = size;
		mLinkedList = new LinkedList[mSize];
	}
	
	// length(Key) % N
	int getHash(Key k) {
		return k.toString().length() % mLinkedList.length;
	}
	
	// puts the value for the appropriate key
	public void put(Key k, Value v) {
		int hash = getHash(k);
		if (mLinkedList[hash] == null)
			mLinkedList[hash] = new LinkedList<>();
		// Check if the key is already present
		// then remove the cell value
		for (Cell<Key, Value> c : mLinkedList[hash]) {			
			if (c.equivalent(k)) {
				mLinkedList[hash].remove(c);
				break;
			}
		}
		mLinkedList[hash].add(new Cell<Key, Value>(k, v));
	}
	
	public Value get(Key k) {
		int hash = getHash(k);
		if (mLinkedList[hash] == null)
			return null;
		
		for (Cell<Key, Value> c : mLinkedList[hash]) {
			if (c.equivalent(k)) {
				return c.getValue();
			}
		}
		return null;
	}
	
	public void print() {
		for (int i = 0; i < mLinkedList.length; i++) {
			if (mLinkedList[i] == null) continue;
			System.out.println("Bucket: "+i);
			for (Cell<Key, Value> c : mLinkedList[i]) {
				System.out.println("Key: " + c.getKey() + " Value: "+c.getValue());
			}
		}
	}
	
	public static void main(String args[]) {
		Hash<String, Integer> h = new Hash<>(4);
		h.put("ab", 1);
		h.put("xyz", 2);
		h.put("pqr", 3);
		h.put("ab", 4);
		h.put("mnop", 4);
		h.put("pqrstquuljfgjlfd", 10);
		
		h.print();
	}
}
