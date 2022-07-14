#include<bits/stdc++.h>
void insert(stack<int>& s, int num){
    if(s.empty() || (!s.empty() && num>s.top())){
        s.push(num);
        return;
    }
    int n=s.top();
    s.pop();
    insert(s,num);
    s.push(n);
}
void sortStack(stack<int> &s)
{
	// Write your code here
    if(s.empty()) return;
    int num=s.top();
    s.pop();
    sortStack(s);
    insert(s,num);
}