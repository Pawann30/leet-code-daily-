class Solution {
public:
    int minimumBuckets(string h) {
        int  count =0;
        int n=h.length();
        for(int i=0;i<h.length();i++){
            if(h[i]=='H'){
                if(i>0 && h[i-1]=='B'){
                    continue;
                }
                if(i+1 < n && h[i+1]=='.'){
                    h[i+1]='B';
                    count++;
                }
                else if(i>0 && h[i-1]=='.'){
                    h[i-1]='B';
                    count++;
                }
                else{
                    return -1;
                }
            }
            
        }
        return count;
    }
};