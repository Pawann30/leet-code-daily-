class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int p=0,i=0;
        int Min = INT_MAX;
        while(i<n){
            sum += nums[i];
            while(sum >= t){
                Min = min(Min,(i + 1) - p);
                sum -= nums[p];
                p++;
            }
            i++;
        }
        if(Min == INT_MAX){
            return 0;
        }
        return Min;
    }
};