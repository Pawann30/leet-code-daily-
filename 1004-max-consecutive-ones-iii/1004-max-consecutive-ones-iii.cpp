class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int j=0;
        int count =0;
        int Max=INT_MIN;
        int i=0;
        while(i<n){
            if(nums[i]==0){
                count++;
                i++;
            }else{
                i++;
            }
            if(count>k){
                Max=max(Max,i-j-1);
                i=j+1;
                j++;
                count=0;
            }
        }
        Max = max(Max, i - j);
        return Max;

    }
};