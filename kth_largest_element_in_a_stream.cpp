#include<bits/stdc++.h>
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int kth;
    Kthlargest(int k, vector<int> &nums) {
       // Write your code here.
        kth=k;
        for(int i : nums){
            pq.push(i);
            if(pq.size()>kth){
                pq.pop();
            }
        }
    }

    void add(int val) {
        // Write your code here.
        pq.push(val);
        if(pq.size()>kth){
            pq.pop();
        }
    }

    int getKthLargest() {
       // Write your code here.
        return pq.top();
    }

};