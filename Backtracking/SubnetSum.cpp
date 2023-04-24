#include <bits/stdc++.h>
using namespace std;

void displaySubset(vector<int> &subSet, int size) {
   for(int i = 0; i < size; i++) {
      cout << subSet[i] << "  ";
   }
   cout << endl;
}

void subsetSum(vector<int> &set, vector<int> &subSet, int n, int subSize, int total, int nodeCount ,int sum) {
   if( total == sum) {
      displaySubset(subSet, subSize);     //print the subset
      subsetSum(set,subSet,n,subSize-1,total-set[nodeCount],nodeCount+1,sum);     //for other subsets
      return;
   }else {
      for( int i = nodeCount; i < n; i++ ) {     //find node along breadth
         subSet[subSize] = set[i];
         subsetSum(set,subSet,n,subSize+1,total+set[i],i+1,sum);     //do for next node in depth
      }
   }
}

void findSubset(vector<int> &set , int size, int sum) {
   vector<int> subSet(size);     //create subset array to pass parameter of subsetSum
   subsetSum(set, subSet, size, 0, 0, 0, sum);
   
}

int main() {
   vector<int> weights = {15, 22, 14, 26, 32, 9, 16, 8};
   int size = 8;
   findSubset(weights, size, 53);
}