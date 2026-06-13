class Solution {
public:
    int minElement(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            string a =to_string(nums[i]);
            int m= a.size();
            int sum =0;
            for(int j=0;j<m;j++){
                sum +=a[j] - '0';;
            }
            nums[i]=sum;
        }
        int Min =*min_element(nums.begin(),nums.end());
        return Min;

    }
};