#include<bits/stdc++.h>
int kthLargest(vector<int>& arr, int size, int k)
{
	// Write your code here.
    priority_queue<int> pq;
    for(int i : arr){
        pq.push(i);
        //if(pq.size()>k) pq.pop();
    }
    while(pq.empty()==false && k>1){
        pq.pop();
        k--;
    }
   return pq.top();
    
}