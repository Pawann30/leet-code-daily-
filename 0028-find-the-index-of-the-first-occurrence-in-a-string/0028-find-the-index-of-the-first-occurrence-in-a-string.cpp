class Solution {
public:
    int strStr(string h, string n) {
        int a = h.length();
        int b = n.length();
        if( b > a){
            return -1;
        }
        int i = 0 ;
        int j = 0 ; 
        while(i < a){
            if(h[i] == n[j]){
                i++,j++;
                if(j == b){
                    return i - j;
                }
            }else{
                i = i-j+1;
                j=0;
            }
            if(i+b-j > a){
                return -1;
            }
        }
        return -1;
    }
};