class Solution {
public:
    string reverseWords(string s) {
        int n = s.length();
        string word = "";
        string ans = "";
        int i = 0 ;
        int j = n-1;
        while( j  >= 0){
            if(s[j] != ' '){
                word.push_back(s[j]);
                j--;
            }else {
                if(word.length() > 0 ){
                    reverse(word.begin(),word.end());
                    ans += word; 
                    ans.push_back(' ');
                    word = "";
                }
                j--;
            }

        }
        if(word.length() > 0 ){
            reverse(word.begin(),word.end());
            ans += word; 
            ans.push_back(' ');
        }
        if (!ans.empty()) {
            ans.pop_back();
        }
        return ans;
    }
};