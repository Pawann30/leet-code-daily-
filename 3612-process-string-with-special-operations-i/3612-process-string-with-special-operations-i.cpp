class Solution {
public:
    string processStr(string s) {
        int n = s.length();
        int i = 0;
        string ans;
        while(i<n){
            if(s[i] >= 'a' && s[i]<= 'z'){
                ans.push_back(s[i]);
                i++;
            }
            else if(s[i] == '*'){
                if(!ans.empty()){
                    ans.pop_back();
                }
                i++;
            }
            else if(s[i] == '#'){
                ans.append(ans);
                i++;
            }
            else if(s[i] == '%'){
                reverse(ans.begin(),ans.end());
                i++;
            }
        }
        return ans;
    }
};