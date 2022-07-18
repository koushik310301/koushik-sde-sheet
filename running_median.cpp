#include<bits/stdc++.h>
void addNum(int num,priority_queue<int>& pmax,priority_queue<int,vector<int>,greater<int>>& pmin) {
        if(pmax.empty()==true || pmax.top()>=num){
            pmax.push(num);
        }
        else{
            pmin.push(num);
        }
        
        if(pmax.size()>pmin.size()+1){
            pmin.push(pmax.top());
            pmax.pop();
        }
        else if(pmin.size()>pmax.size()){
            pmax.push(pmin.top());
            pmin.pop();
        }
    }


int median(priority_queue<int>& pmax,priority_queue<int,vector<int>,greater<int>>& pmin) {
        int n1=pmax.size();
        int n2=pmin.size();
        
        if((n1+n2)%2==0){
            return (pmax.top()+pmin.top())/2;
        }
        return pmax.top();
        
    }
void findMedian(int *arr, int n)
{
    // Write your code here
    priority_queue<int> pmax;
    priority_queue<int,vector<int>,greater<int>> pmin;
    for(int i=0;i<n;i++){
        addNum(arr[i],pmax,pmin);
        cout<< median(pmax,pmin) <<" ";
    }
}