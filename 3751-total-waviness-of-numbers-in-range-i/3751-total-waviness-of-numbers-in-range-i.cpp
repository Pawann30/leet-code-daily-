class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        int n= num2 - num1;
        string k = to_string(num1);
        int c=0;   
        for (int num = num1; num <= num2; num++) {
            string k = to_string(num);
            if (k.size() < 3) 
                continue;
    
            for (int i = 1; i<k.size()-1; i++){
                if((k[i] > k[i-1]) && (k[i] > k[i+1])){
                    c++;
                }else if((k[i] < k[i-1]) && (k[i]<k[i+1])){
                    c++;
                }      
            }
        }
        return c;
    }
};