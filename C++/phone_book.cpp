#include <iostream>
#include <map>
#include <string>
using namespace std;


int main() {
    map<string, int> mymap;
    int N, phone;
    string name;
    cin>>N;
    while (N--) {
        cin>>name>>phone;
        mymap.insert(pair<string, int>(name, phone));
    }
    while (!cin.eof()) {
        cin>>name;
        map<string, int>::iterator it = mymap.find(name);
        if (it != mymap.end())
            cout<<name<<"="<<mymap.at(name)<<endl;
        else
            cout<<"Not found"<<endl;
    }
    return 0;
}
