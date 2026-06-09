class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        int i=1;
        while(i<=n){
            sum +=i;
            i++;
        }
        for(int i=0;i<n;i++){
            sum -=nums[i];
        }
        return sum;
    }
};