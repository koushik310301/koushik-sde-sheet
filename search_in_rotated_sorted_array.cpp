int search(int* nums, int n, int tg) {
    int l=0;
        int h=n-1;
        while(l<=h){
            int m=(l+h)/2;
            if(nums[m]==tg) return m;
            
            if(nums[l]<=nums[m]){
                if(tg>=nums[l] && tg<=nums[m]){
                    h=m-1;
                }else{
                    l=m+1;
                }
                
            }
            else{
                if(tg>=nums[m] && tg<=nums[h]){
                    l=m+1;
                }else{
                    h=m-1;
                }
            }
            
            
        }
        return -1;
}