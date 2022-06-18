#include<bits/stdc++.h>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    // Write your code here.
    stack<int> st;
    vector<int> ans(n,-1);
    st.push(0);
    for(int i=1;i<n;i++){
        if(arr[i]>=arr[st.top()]) st.push(i);
        else{
            while(st.empty()==false && arr[i]<arr[st.top()]){
                ans[st.top()]=arr[i];
                st.pop();
            }
            st.push(i);
        }
    }
    return ans;
}