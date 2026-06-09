class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        unordered_map<int,int> Mp;
        for(int i=0;i<mp.size();i++){
            Mp[mp[i]]++;
        }
        for(int i=0;i<n;i++){
            if(Mp[mp[nums[i]]]==1){
                return nums[i];
            }
        }
        return -1;
    }
};