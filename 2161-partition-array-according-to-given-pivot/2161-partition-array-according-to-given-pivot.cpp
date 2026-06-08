class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n=nums.size();
        vector<int> ans = nums;
        sort(ans.begin(),ans.end());
        int j=0;
        while(j < n && ans[j] <= pivot){
            j++;
        }
        int i=0;
        for(int z=0;z<n;z++){
            if(nums[z]<pivot){
                ans[i]=nums[z];
                i++;
            }else if(nums[z]>pivot){
                ans[j]=nums[z];
                j++;
            }
        }
        return ans;
    }
};