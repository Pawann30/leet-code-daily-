class Solution {
public:
    int maxScore(vector<int>& cp, int k) {
        int n = cp.size();
        int sum = 0; 
        for(int i =0 ;i<k;i++){
            sum += cp[i];
        }
        int maxx = sum;
        int i=1;
        while(k!=0){
            sum -= cp[k-1];
            sum += cp[n-1];
            maxx = max(maxx ,sum);
            n--;
            k--;
        }
        return maxx;
    }
};