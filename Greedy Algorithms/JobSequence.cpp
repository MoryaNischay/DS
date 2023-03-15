#include<bits/stdc++.h>
using namespace std; 


struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    bool static compare(Job a,Job b){
        return a.profit>b.profit;
    }  
    vector<int> JobScheduling(vector<Job> arr, int n) 
    { 
        sort(arr.begin(),arr.end(),compare);
        int maxdead=arr[0].dead;
        for (int i=1;i<n;i++){
            maxdead=max(arr[i].dead,maxdead);
        }
        vector<int> gant(maxdead+1,-1);
        int countjob=0,jobprofit=0;
        for (int i=0;i<n;i++){
            for (int j=arr[i].dead;j>0;j--){
                if (gant[j]==-1){
                    gant[j]=i;
                    countjob++;
                    jobprofit+=arr[i].profit;
                    break;
                }
            }
        }
        vector<int> v1;
        v1.push_back(countjob);
        v1.push_back(jobprofit);
        return v1;
    } 
};

int main() 
{ 
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        vector<Job> arr(n);
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}
