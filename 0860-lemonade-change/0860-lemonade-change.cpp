class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n =bills.size();
        int i=0;
        int a=0,b=0,c=0;
        int total = 0;
        while(i<n){
            if(bills[i]==5){
                a++;
                i++;
            }else if(bills[i]==10){
                if(a >= 1){
                    b++;a--;
                    i++;
                }else{
                    return false;
                }

            }else  if(bills[i]==20){
                if(a >= 1 && b>=1){
                    a--;b--;
                    i++;
                }else if(a>=3){
                    a -=3;i++;
                }else{
                    return false;
                }
            }         
        }
        return true;
    }
};