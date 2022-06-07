vector<int> fun(vector<int>& nums1, vector<int>& nums2) {
    // Write your code here.
    int m=nums1.size();
    int n=nums2.size();
    vector<int> ans;
        int i=0;
        int j=0;
        while(i<m && j<n){
            if(nums1[i]<=nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }
        while(i<m){
            ans.push_back(nums1[i]);
            i++;
        }
        while(j<n){
            ans.push_back(nums2[j]);
            j++;
        }
        return ans;
}
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    if(k==1) return kArrays[0];
    vector<vector<int>> ans;
    for(int i=0;i<k-1;i++){
        kArrays[i+1]=fun(kArrays[i],kArrays[i+1]);
    }
    return kArrays.back();
}
