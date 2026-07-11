class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.rbegin(),nums.rend());
        int n =nums.size();
        int i =0;
        long long sum=0;
        
        while(k > 0){
            if(mul > 0){
                sum  += 1LL*nums[i]*mul;
                mul--;
                k--;i++;
            }else{
                sum +=nums[i];
                k--;
                i++;
            }
        }
        return sum;
    }
};