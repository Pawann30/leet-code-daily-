class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        sort(cost.rbegin(),cost.rend());
        int mcost=0;
        int c=0;
        for(int i=0;i<n;i++){
            if(c<2){
                mcost+=cost[i];
                c++;
            }else{
                c=0;
            }       
        }
        return mcost;
    }
};