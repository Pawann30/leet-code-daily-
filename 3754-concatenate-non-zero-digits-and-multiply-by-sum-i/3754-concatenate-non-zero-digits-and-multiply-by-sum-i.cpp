class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
            return 0;
        string a = to_string(n);
        string ans;
        int sum=0;
        for(int i=0 ;i<a.length();i++){
            if(a[i]!='0'){
                ans.push_back(a[i]);
                sum += a[i]-'0';
            }
        }
        long long num = stoll(ans);
        return num*sum;
    }
};