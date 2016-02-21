/**
 * Check if s1 is isomorphic to s2
 * A string is isomorphic if it has same length and looks
 * same in character count if it is mapped with s1
 */
#include <iostrea2m>
#include <string.h>
#define MAX_CHARS 255
using namespace std;

/**
 * returns true if s1 is isomorphic with s2
 * Algorithm:
 * 1) Initilize MAP and visited array to hold the mapping 
 * and visited info of characters
 * 2) if the lengths are not equal return false
 * 3) Check the map contains the char in s2,
 *    if it is already visited return false
 *    else visit the s2 char and update the map
 * 4) Return true if all the chars are visited
 * T(n) = O(n), S(n) = O(2n)
 */
bool isIsomorphic(string &s1, string &s2) {
	if (s1.length() != s2.length()) return false;
	int MAP[MAX_CHARS];
	memset(MAP, -1, sizeof(MAP));
	bool visited[MAX_CHARS];
	memset(visited, 0, sizeof(visited));
	for (int i = 0; s1[i] != '\0'; i++) {
		if (MAP[s1[i]] == -1) {
			if (visited[s2[i]]) return false;

			visited[s2[i]] = true;
			MAP[s1[i]] = s2[i];

		} else if (MAP[s1[i]] != s2[i]) return false;
	}
	return true;
}
int main() {
	string s1 = "aab";
	string s2 = "xyz";
	if (isIsomorphic(s1, s2)) {
		cout<<s1<<" is isomorphic to "<<s2<<endl;
	} else {
		cout<<s1<<" is not isomorphic to "<<s2<<endl;
	}
	return 0;
}

