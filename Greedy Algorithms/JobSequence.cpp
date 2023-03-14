#include<bits/stdc++.h>
using namespace std;

struct Job{
    int id;
    int deadline;
    int profit;
};

bool compare(Job a, Job b){
    return a.profit > b.profit;
}

void JobSequence(vector <Job> jobs){
    sort(jobs.begin(), jobs.end(), compare);
    int maxDeadline = 0;
    for(int i = 0; i < jobs.size(); i++){
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }
    vector <int> slot(maxDeadline, -1);
    int profit = 0;
    for(int i = 0; i < jobs.size(); i++){
        for(int j = jobs[i].deadline - 1; j >= 0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                profit += jobs[i].profit;
                break;
            }
        }
    }
    cout << "Profit: " << profit << endl;
    cout << "Job Sequence: ";
    for(int i = 0; i < slot.size(); i++){
        if(slot[i] != -1){
            cout << jobs[slot[i]].id << " ";
        }
    }
    cout << endl;
}

int main(){
    vector <Job> jobs = {{1, 4, 20}, {2, 1, 10}, {3, 1, 40}, {4, 1, 30}};
    JobSequence(jobs);
    return 0;
}