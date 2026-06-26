class Solution {
public:
    int maxScore(string s) {
        int n = s.length();
        int c = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                c++;
            }
        }
        int maxx = INT_MIN;
        int i =0 ;
        int z =0;
        while(i<n-1){
            if(s[i] == '1'){
                c--;
            }
            if(s[i] == '0'){
                z++;
            }
            maxx = max(maxx , c+z);
            i++;
        }
        return maxx;
    }
};