/**
 * Detects if a string is a pangram
 * Pangram: The quick brown fox jumps over the lazy dog
 */
#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

bool isPangram(const string& alphas) {
    int i, j;  
    // compare with a = 97 till z = 122
    for (i = 97, j = 0; i <= 122; i++) {
        if (alphas[j] != i) {
            return false;
        }
        j++;
    }
    return true; 
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int i;
    // 
    string pangram = "The quick brown fox jumps over the lazy dog";
    
    // Get the input
    //getline(cin, pangram);
    
    // Convert into lower case
    for (i = 0; pangram[i] != '\0'; ++i) {
          pangram[i] = tolower(pangram[i]);
    }

    cout<<"After lower: "<<pangram<<endl;
    
    // Remove spaces
    string::iterator end_pos = remove(pangram.begin(), pangram.end(), ' ');
    pangram.erase(end_pos, pangram.end());

    cout<<"After removing space: "<<pangram<<endl;
    
    // Sort
    sort(pangram.begin(), pangram.end());
    
    cout<<"After sorting: "<<pangram<<endl;
    // Remove duplicates
    string alphas;
    for (i = 1; pangram[i] != '\0'; i++) {
        if (pangram[i-1] != pangram[i]) {
           alphas.push_back(pangram[i-1]);
        }
    }
    alphas.push_back(pangram[i-1]);

    cout<<"After removing duplicates: "<<alphas<<endl;
    if (isPangram(alphas))
        cout<<"pangram\n";
    else
        cout<<"not pangram\n";
    
    return 0;
}
