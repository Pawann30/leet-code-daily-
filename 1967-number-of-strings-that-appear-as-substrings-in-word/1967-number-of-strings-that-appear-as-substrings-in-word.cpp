class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int n = patterns.size();
        int count =0 ;
        for(int i=0;i<n;i++){
            int m=patterns[i].length();
            if (m > word.length()) continue;
            for(int j=0;j<=word.length()-m;j++){
                int k = 0;
                while(k < m && (k + j) < word.length() && patterns[i][k] == word[k + j]){
                    k++;
                }
                if(k == m){
                    count++;
                    break;
                }
            }
        }
        return count;
    }
};