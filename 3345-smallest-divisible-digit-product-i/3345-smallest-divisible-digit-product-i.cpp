class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int pro = 1;
            string s = to_string(n);
            for(char c : s){
                pro *= (c -'0');
            }
            if(pro%t == 0){
                return n;
            }
            n++;
        }
    }
};