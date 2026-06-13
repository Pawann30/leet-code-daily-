class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,int> ans;
        int n=word.length();
        int count =0;
        for(int i=0;i<n;i++){
            if(word[i] >= 97 && word[i]<=123){
                ans[word[i]]++;
            }
        }
        for(int i=0;i<n;i++){
            if(word[i] >= 65 && word[i]<=90){
                char ch = word[i] + 32;
                if(ans[ch] > 0) {
                    count++;
                    ans[ch]=0;
                }
            }
        }
        return count;

    }
};