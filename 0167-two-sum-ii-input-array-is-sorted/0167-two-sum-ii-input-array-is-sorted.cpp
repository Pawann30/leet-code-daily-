class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {\

        // BRUTE FORCE

        /*int n = nums.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(target == nums[i]+nums[j]){
                    return {i+1,j+1};
                }
            }
        }
        return {-1,-1};*/

        //Optimized 

        int n = nums.size();
        int i=0,j=n-1;
        while(i<n  && j>=0){
            int sum = nums[i] + nums[j];
            if(sum == target){
                return { i+1 , j+1};
            }else if( sum < target){
                i++;
            }else{
                j--;
            }
        }
        return{-1,-1};
    }
};