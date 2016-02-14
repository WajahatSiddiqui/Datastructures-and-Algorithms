/**
 * To implement minimum stack that returns minimum element in O(1) time
 */
 #include <iostream>
 #include <stack>
 using namespace std;

 class MinStack {
 private:
 	stack<int> min;
 	stack<int> s;
 public:
 	void push(int data) {
 		if (min.empty()) {
 			min.push(data);
 		} else if (data < min.top()) {
 			min.push(data);
 		} else if (data > min.top()) {
 			min.push(min.top());
 		}
 		
 		s.push(data);
 	}

 	void pop() {
 		min.pop();
 		s.pop();
 	}

 	int top() {
 		return s.top();
 	}

 	/**
 	 * T(n) = O(1)
 	 **/
 	int getMin() {
 		return min.top();
 	}
 };

 int main() {
 	MinStack minStack;
 	int keys[] = {3, 1, 2, -1, 0, 4, -6};
 	int size = sizeof(keys)/sizeof(keys[0]);

 	for (int i = 0; i < size; i++) {
 		cout<<"Pushing key: "<<keys[i]<<endl;
 		minStack.push(keys[i]);
 		cout<<"Current Minimum: "<<minStack.getMin()<<endl;
 	}

 	cout<<"Popping 5 values\n";
 	for (int i = 0; i < 5; i++) {
 		cout<<"Popping: "<<minStack.top()<<endl;
 		minStack.pop();
 		cout<<"Current Minimum: "<<minStack.getMin()<<endl;
 	}

 	return 0;
 }