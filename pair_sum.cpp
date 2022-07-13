#include <bits/stdc++.h> 
// bool cmp(vector<int>& a, vector<int>& b){
//     if(a[0]==b[0]) return a[1]<b[1];
//     return a[0]<b[0];
// }
//vector<vector<int>> pairSum(vector<int> &nums, int target){
   // Write your code here.
//     vector<vector<int>> ans;
//     int n=nums.size();
//     unordered_map<int,int> mp;
//     for(int i=0;i<n;i++ ){
//         mp[nums[i]]++;
//     }    
    
//     for(int i=0;i<n;i++){
//         if(mp[target-nums[i]]!=0){
//             int x=mp[target-nums[i]];
//             while(x--){
//                 ans.push_back({nums[i],target-nums[i]});
//             }
//         }
//     }
    
//     sort(ans.begin(),ans.end(),cmp);
//     vector<vector<int>> fans;
//     for(int i=0;i<ans.size()/2;i++){
//         fans.push_back(ans[i]);
//     }
//     return fans;
    
//}
vector<vector<int>> pairSum(vector<int> &arr, int s){

   vector<vector<int>> ans;

   for(int i=0; i<arr.size(); i++){

       for(int j=i+1; j<arr.size(); j++){

           if(arr[i]+arr[j]==s){

               vector<int> temp;

               temp.push_back(min(arr[i],arr[j]));

               temp.push_back(max(arr[i],arr[j]));

               ans.push_back(temp);

               

               

           }

       }

   }

   sort(ans.begin(), ans.end());

   return ans;

}