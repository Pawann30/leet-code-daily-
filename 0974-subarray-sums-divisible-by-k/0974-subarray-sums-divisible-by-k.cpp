class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int sum = 0 ;
        int ans = 0;
        mp[0] = 1;
        for(int x : nums){
            sum += x;
            int rem  = sum % k;
            if(rem < 0 ){
                rem += k;
            }
            ans += mp[rem];
            mp[rem]++;
        }
        return ans;
    }
};