#include <bits/stdc++.h> 
#include <vector>

bool findTargetInMatrix(vector < vector < int >> & mat, int m, int n, int target) {
    // Write your code here.
    for(auto ls : mat){
        if(count(ls.begin(),ls.end(),target)) return true;
    }
    return false;
}