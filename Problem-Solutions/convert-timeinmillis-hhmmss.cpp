#include <stdio.h>
using namespace std;

// converts the time in millis to 
// human readable format in hh:mm:ss
// I/P: 901000
// O/P: 00:15:01
void convertTime(int timeInMillis) {
    // convert millisecs into secs
    int secs = timeInMillis/1000;
    // convert secs into minutes and round off if it reaches 60
    int mins = secs/60 % 60;
    // convert secs into hrs and round off if it reaches 24
    int hrs = (secs/(60*60)) % 24;
    // print the time in the format hh:mm:ss
    printf("%02d:%02d:%02d\n", hrs, mins, secs%60);
}

int main() {
    convertTime(901000);
    convertTime(3601000);

    return 0;
}

