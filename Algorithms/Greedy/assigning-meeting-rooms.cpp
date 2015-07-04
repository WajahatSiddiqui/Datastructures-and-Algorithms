/* In our company, there is a popular meeting room. Many meetings are reserved to use this room with starting time and finishing time, and the place can’t hold two meetings at the same time if the time is overlapped. Thus only one of the same time-framed meetings can be held in here and the others should give up. However, it is not overlapped for the same starting time of a meeting and the finishing time of another meeting.
When the number of meetings, starting time and finishing time of each meetings are given, you want to hold as many meetings as possible.
In a given number of meetings and each given starting/finishing time, you want to hold as many meetings as possible. Create a program that can assign meetings to the meeting room as many as it can.

[Input]
Several test cases can be included in the inputs. T, the number of cases is given in the first row of the inputs. After that, the test cases as many as T (T ≤ 20) are given in a row. 
N, the number of meetings is given in the first row of each test case (1 ≤ N ≤ 500).
Numbers of each meeting, starting time, and finishing time are given separately from the second row to the number of N. (Each number is natural numbers below 500) 

[Output]
Output the maximum number of meetings which can assign in the first row of each test case. */
// Assigning a Meeting Room 
#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

struct Meeting {
    int id;
    int startTime;
    int endTime;
};

vector<Meeting> meetings;

void print() {
    for (int i = 0; i < meetings.size(); i++)
        cout<<meetings[i].id<<" "<<meetings[i].startTime<<" "<<meetings[i].endTime<<endl;
}

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// sort based on finish time
// uses insertion sort
void sort() {
    vector<Meeting>::iterator it1, it2;
    for (it1 = meetings.begin(); it1 != meetings.end(); ++it1) {
        for (it2 = it1+1; it2 != meetings.end(); ++it2) {
            if (it1->endTime > it2->endTime) {
                swap(&it1->endTime, &it2->endTime);
                swap(&it1->startTime, &it2->startTime);
                swap(&it1->id, &it2->id);
            }
        }
    }
}

// Use Greedy Strategy to get the optimal solution
// First Meeting room will always be in the solution
// from next onwards check if the start time of meeting room
// is greater than or equal to the end time of prev
// then increment the count to get the max meetings possible
// in a day.
void printMaxMeetings() {
    sort();
    int count = 1; // first meeting is always selected;
    vector<Meeting>::iterator it1, it2;
    it1 = meetings.begin();
    for (it2 = meetings.begin()+1; it2 != meetings.end(); it2++) {
        if (it2->startTime >= it1->endTime) {
            count++;
            it1 = it2;
        }
    }
    cout<<count<<endl;

}

int main() {
    int T, N;
    freopen("assigning-meeting-rooms.txt", "r", stdin);
    cin>>T;
    while (T--) {
        cin>>N;
        for (int i = 0; i < N; i++) {
            Meeting meeting;
            cin>>meeting.id>>meeting.startTime>>meeting.endTime;
            meetings.push_back(meeting);
        }
        printMaxMeetings();
        meetings.clear();
    }
    return 0;
}
