class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int n=nums.size();
        int i=0,j=n-1;
        int count=0;
        /*while(i<j){
            if(nums[i]==0){
                if(nums[j]==0){
                    while(nums[j]==0){
                        j--;
                    }
                    swap(nums[i],nums[j]);
                    count++;
                    j--,i++;
                }else{
                    swap(nums[i],nums[j]);
                    count++;
                    i++,j--;
                }
            }else{
                i++;
            }
        }*/
        while(i<j){
            while (i<n && nums[i]!= 0){
                i++;
            }
            while (j>=0 && nums[j]==0){
                j--;
            }
            if(i<j){
                swap(nums[i], nums[j]);
                count++;
                i++;
                j--;
            }
        }
        return count;
    }
};