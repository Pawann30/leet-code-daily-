class Solution {
public:
    string customSortString(string order, string s) {
        int n = order.length();
        vector<int> freq(26,0);
        for( char ch : s){
            freq[ch - 'a']++;
        }
        string k ;
        for(int i = 0 ; i < n ; i++){
            char c = order[i];
            if (s.find(c) != string::npos ) {
                while( freq[ c - 'a']>0){
                    k.push_back(c);
                    freq[ c - 'a']--;
                }
            }
        }
        int m = s.length();
        for(int i = 0 ; i < m ; i++){
            char c = s[i];
            if (k.find(c) == string::npos) {
                while( freq[ c - 'a']>0){
                    k.push_back(c);
                    freq[ c - 'a']--;
                }
            }
        }
        return k;
    }
};