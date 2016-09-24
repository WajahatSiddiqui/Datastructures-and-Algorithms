// Weighted Job Scheduling
// Given N Jobs there start time (st), end time (et) & profit
// find the maximum profit after scheduling a sequence of jobs
// where no two jobs overlap.

//http://www.geeksforgeeks.org/weighted-job-scheduling/

#include <iostream>
#include <cstdio>
#include <climits>
#include <vector>
using namespace std;

struct JOB {
	int id, start, end, profit;
	vector<int> scheduler;	
};

bool isOverlap(JOB j1, JOB j2) {
	return j1.end > j2.start;
}

void printJobs(JOB *jobs, int N) {
	cout<<"I S E P\n";
	for (int i = 0; i < N; i++) {
		cout<<jobs[i].id<<" "<<jobs[i].start<<" "<<jobs[i].end<<" "<<jobs[i].profit<<"\n";
	}
	cout<<endl;
}

void print(int *T, int N) {
	for (int i = 0; i < N; i++) cout << T[i] << " ";
	cout<<endl;
}

inline int maxim(int m1, int m2) {
	return m1 > m2 ? m1 : m2;
}

// copies j2 in j1
void copy(JOB j1, JOB j2) {
	j1.id = j2.id;
	j1.start = j2.start;
	j1.end = j2.end;
	j1.profit = j2.profit;
}

void swap(JOB *j1, JOB *j2) {
	JOB *tmp;
	copy(*tmp, *j1);
	copy(*j1, *j2);
	copy(*j2, *tmp);
}

void sort(JOB *jobs, int N) {
	int min_index = 0;
	for (int i = 0; i < N; i++) {
		min_index = i;
		for (int j = i+1; j < N; j++) {
			if (jobs[j].end < jobs[min_index].end)
				min_index = j; 
		}
		if (jobs[i].end != jobs[min_index].end) {
			swap(jobs[i], jobs[min_index]);
		}
	}
}

int findMaxProfit(JOB *jobs, int N) {
	//printJobs(jobs, N);
	sort(jobs, N);
	printJobs(jobs, N);
	int max = INT_MIN;
	int max_index = 0;
	int *T = new int[N];
	for (int i = 0; i < N; i++) T[i] = jobs[i].profit;
	//print(T, N);
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i != j && !isOverlap(jobs[j], jobs[i])) {
				T[i] = maxim(T[i], T[j] + jobs[i].profit);
				if (T[i] > max) {
					max = T[i];
					max_index = i;
					//cout<<"w " << i <<" "<<"id "<<jobs[j].id<<endl;
					jobs[i].scheduler.push_back(jobs[j].id);
				}					
			}
		}
	}
	print(T, N);
	//cout<<"Jobs with Max Profit: ";
	//cout << max_index;
	for (int i = 0; i < jobs[max_index].scheduler.size(); i++) {
		//cout<<"J"<<jobs[max_index].scheduler[i]<<" ";
	}
	delete [] T;
	return max;
}

int main() {
	int N;
	freopen("weighted_job_scheduling.txt", "r", stdin);
	cin >> N;
	JOB *jobs = new JOB[N];
	for (int i = 0; i < N; i++) {
		jobs[i].id = i+1;
		cin >> jobs[i].start >> jobs[i].end >> jobs[i].profit;
	}
	//printJobs(jobs, N);
	cout <<"Max Profit = " << findMaxProfit(jobs, N) << endl;
	delete [] jobs;
	return 0;
}
