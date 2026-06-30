class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> freq(3,0);
        int n = s.size();
        int count = 0;
        int j=0;
        for(int i=0; i<n; i++){
            freq[s[i]-'a']++;
            while(freq[0] > 0 && freq[1] > 0 && freq[2] > 0 ){
                count += (n-i);
                freq[s[j]-'a']--;
                j++;
            }
        }
        return count;
    }
};