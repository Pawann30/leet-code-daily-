class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n=g.size();
        int m=s.size();
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int count =0;
        int j=0,i=0;
        while (j<m && i<n){
            if(s[j]>=g[i]){
                count++;
                i++,j++;
            }else{
                j++;
            }
        }
        return count;
    }
};