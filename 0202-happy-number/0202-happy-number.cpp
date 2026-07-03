class Solution {
public:
    bool isHappy(int n) {
        while(n != 1 && n != 4){
            int k = n;
            int sum =0;
            while(k>0){
                int s = k%10;
                sum += s*s;
                k /=10;
            }
            n=sum;
        }
        if(n==1){
            return true;
        }else{
            return false;
        }
    }
};