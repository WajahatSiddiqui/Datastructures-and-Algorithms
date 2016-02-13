/**
 * Compress character stream as follows
 * aaabbcccddeeff to a3b2c3d2e2f2
 * Run Length Encoding of a character stream
 */
 #include <iostream>
 #include <string>
 using namespace std;
 char toChar[] = {'a', 'b', 'c', 'd', 'e', 'f'};

 string rle(const string& str) {
 	int rle[6];
 	string rleString = "";
 	int count = 1;
 	for (int i = 0; i < str.size(); i++) {
 		if (str[i] == 'a') rle[0]++;
 		if (str[i] == 'b') rle[1]++;
 		if (str[i] == 'c') rle[2]++;
 		if (str[i] == 'd') rle[3]++;
 		if (str[i] == 'e') rle[4]++;
 		if (str[i] == 'f') rle[5]++;
 	}
 	for (int i = 0; i < 6; i++) {
 		rleString += toChar[i] + rle[i];
 	}
 	return rleString;
 }

 int main() {
 	string str = "aaabbcccddeeff";
 	cout<<rle(str)<<endl;

 	return 0;
 }


