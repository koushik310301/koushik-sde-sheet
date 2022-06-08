#include <bits/stdc++.h> 
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/
bool cmp(vector<int>& a, vector<int>& b){
    if(a[0]==b[0]) return a[0]<b[0];
    return a[0]<b[0];
}
vector<vector<int>> mergeIntervals(vector<vector<int>> &arr)
{
    // Write your code here.
    vector<vector<int>> ans;
    stack<vector<int>> st;
    sort(arr.begin(),arr.end(),cmp);
    st.push(arr[0]);
    for(int i=1;i<arr.size();i++){
        auto ls=st.top();
       
        if(arr[i][0]<=ls[1]){
             st.pop();
            vector<int> tmp;
            tmp.push_back(ls[0]);
            tmp.push_back(max(ls[1],arr[i][1]));
            st.push(tmp);
        }
        else{
            st.push(arr[i]);
        }
            
    }
    while(st.empty()==false){
        ans.push_back(st.top());
        st.pop();
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
