class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        map<int,int> hash;
        for(int i=0 ; i<n; i++){
            int num = nums[i];
            int need = target - num;
            if(hash.find(need) != hash.end()){
                return {i , hash[need]};
            }
            hash[num] = i;
        }
        return {-1,-1};
    }
};