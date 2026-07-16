class Solution {
public:
    bool check(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans=nums;
        sort(ans.begin(),ans.end());
        int i =0 ;
        while(i<n){
            int k = 1;
            rotate(ans.begin() , ans.begin()+k,ans.end());
            if(nums == ans){
                return true;
            }
            i++;
        }
        return false;
    }
};