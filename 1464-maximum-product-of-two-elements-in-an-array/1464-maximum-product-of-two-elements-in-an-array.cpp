class Solution {
public:
    int maxProduct(vector<int>& nums) {
       /* int n = nums.size();
        sort(nums.begin(),nums.end());
        return (nums[n-1]-1) * (nums[n-2]-1);
        */
        int n = nums.size();
        int mx1 = -1;
        int mx2 = -1;
        for(int i =0;i<n;i++){
            if(nums[i]>mx1){
                mx2=mx1;
                mx1=nums[i];
            }else if(nums[i]>mx2){
                mx2=nums[i];
            }
        }
        return (mx1-1) * (mx2-1);
    }
};