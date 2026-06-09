class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        /*int sum=0;
        int i=1;
          #can use this also

         int presum = n*(n+1)/2;

        while(i<=n){
            sum +=i;
            i++;
        }
        for(int i=0;i<n;i++){
            sum -=nums[i];
        }
        return sum;

        */
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]!=i){
                return i;
            }
        }
        return n;

    }
};