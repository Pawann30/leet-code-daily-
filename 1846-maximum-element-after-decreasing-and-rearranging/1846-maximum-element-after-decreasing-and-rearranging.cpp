class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        if(arr[0]!=1){
            arr[0]=1;
        }
        int i=0;
        while(i<n-1){
            if(abs(arr[i+1]-arr[i])<=1){
                i++;
            }else{
                arr[i+1]=arr[i]+1;
                i++;
            }
        }
        int Max = *max_element(arr.begin(),arr.end());
        return Max;

    }
};