/////////////////////////////////////////////////////////////////////////////////////////////
// Standard Input
// int a;
// float b, c;
// double d, e, f;
// char g;
// char var[256];
// long long AB;
// cin >> a;                            
// cin >> b >> c;                       
// cin >> d >> e >> f;                   
// cin >> g;                            
// cin >> var;                          
// cin >> AB;                           
/////////////////////////////////////////////////////////////////////////////////////////////
// Standard Output
// int a = 0;                            
// float b = 1.0, c = 2.0;               
// double d = 3.0, e = 0.0; f = 1.0;
// char g = 'b';
// char var[256] = "ABCDEFG";
// long long AB = 12345678901234567L;
// cout << a;                           
// cout << b << " " << c;               
// cout << d << " " << e << " " << f;   
// cout << g;                           
// cout << var;                         
// cout << AB;                          
/////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>

using namespace std;

struct TreeNode {
	int data;
	TreeNode *left, *right;
	TreeNode(int _data) : data(_data) {
		left = NULL;
		right = NULL;
	}
};

int main(int argc, char** argv)
{
	int test_case;
	int T, V, E, V1, V2;
	int *E1, *E2;
	/* 
	The freopen function below opens input.txt in read only mode and 
	sets your standard input to work with the opened file. 
	When you test your code with the sample data, you can use the function
	below to read in from the sample data file instead of the standard input.
	So. you can uncomment the following line for your local test. But you
	have to comment the following line when you submit for your scores.
	*/

	//freopen("input.txt", "r", stdin);
	cin>>T;

	/*
	   Read each test case from standard input.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		/////////////////////////////////////////////////////////////////////////////////////////////
		/*
			Please, implement your algorithm from this section.
		*/
		/////////////////////////////////////////////////////////////////////////////////////////////
		cin>>V>>E>>V1>>V2;
		E1 = new int[E];
		E2 = new int[E];
		for (int i = 0; i < E; i++) {
			cin>>E1[i]>>E2[i];
		}
		TreeNode* tree = buildTree(E1, E2, E);

		// Print the answer to standard output(screen).
		cout << "#" << test_case << endl;
		delete E1;
		delete E2;
		E1 = E2 = NULL;
	}
	return 0;//Your program should return 0 on normal termination.
}