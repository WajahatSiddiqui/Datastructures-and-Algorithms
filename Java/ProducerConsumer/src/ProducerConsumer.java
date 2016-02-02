import java.util.Vector;


public class ProducerConsumer {
	public static void main(String args[]) {
		int size = 4;
		Vector<Integer> mQueue = new Vector<>(size);
		Thread producerThread = new Thread(new Producer(mQueue, size), "ProducerThread");
		Thread consumerThread = new Thread(new Consumer(mQueue), "ConsumerThread");
		
		producerThread.start();
		consumerThread.start();		
	}
	
	private static class Producer implements Runnable {
		Vector<Integer> mQueue;
		int mSize;
		public Producer(Vector<Integer> queue, int size) {
			mQueue = queue;
			mSize = size;
		}
		@Override
		public void run() {
			for (int i = 0; i < 12; i++) {
				System.out.println("Producer: trying to insert item: "+ i);
				try {
					produce(i);
				} catch (InterruptedException e) {
					System.out.println("Producer: Unable to insert an item: " + e.getMessage());
				}
			}
		}
		
		void produce(int i) throws InterruptedException {
			// Check if the queue is full
			while (mQueue.size() == mSize) {
				synchronized (mQueue) {
					System.out.println("Producer: Queue is full size = " + mQueue.size()
							 + " Current thread : " + Thread.currentThread().getName()
							 + " is waiting for consumer to consume!!!");
					mQueue.wait();
				}
			}
			
			// produce the items
			synchronized (mQueue) {
				System.out.println("Producer: adding item : " + i);
				mQueue.add(Integer.valueOf(i));
				mQueue.notifyAll();
			}
		}
	}
	
	private static class Consumer implements Runnable {
		Vector<Integer> mQueue;
		public Consumer(Vector<Integer> queue) {
			mQueue = queue;
		}
		@Override
		public void run() {
			while (true) {
				try {
					System.out.println("Consumer: consumes item = " + consume());
					Thread.sleep(1000);
				} catch(InterruptedException e) {
					System.out.println("Consumer: Unable to consume item : "+ e.getMessage());
				}
			}
		}
		
		int consume() throws InterruptedException {
			// Check if the queue is empty
			while (mQueue.isEmpty()) {
				synchronized(mQueue) {
					System.out.println("Consumer: Queue is empty, size = " + mQueue.size()
							+ " Current thread: " + Thread.currentThread().getName()
							+ " is waiting for producer to produce ...");
					mQueue.wait();
				}
			}
			
			// consume the items
			synchronized (mQueue) {
				int item = mQueue.remove(0);
				mQueue.notifyAll();
				return item;
			}
		}	
	}
}
