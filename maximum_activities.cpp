#include<bits/stdc++.h>
bool cmp(pair<int,int>& a, pair<int,int>& b){
    if(a.first==b.first) return a.second<b.second;
    return a.second<b.second;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
    // Write your code here.
    vector<pair<int,int>> v;
    stack<pair<int,int>> st;
    int n=start.size();
    for(int i=0;i<n;i++){
        v.push_back({start[i],finish[i]});
    }
    
    sort(v.begin(),v.end(),cmp);
    st.push(v[0]);
    for(int i=1;i<n;i++){
        if(v[i].first>=st.top().second) st.push(v[i]);
    }
    return st.size();
}