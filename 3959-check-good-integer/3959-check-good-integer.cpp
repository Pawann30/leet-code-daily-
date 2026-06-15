class Solution {
public:
    bool checkGoodInteger(int n) {
        int sum=0;
        int sq=0;
        while(n>0){
            int rem=n%10;
            sum +=rem;
            sq += rem*rem;
            n/=10;
            
        }
        return sq - sum >= 50;
    }
};