class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26,0);
        int n = s.length();
        int l=0 ,maxx=0,ans=0;
        for(int i=0 ; i<n ; i++){
            freq[s[i] - 'A']++;
            maxx = max(maxx , freq[s[i]-'A']);
            while((i-l +1) -maxx > k){
                freq[s[l]-'A']--;
                l++;
            }
            ans = max(ans , i - l+1);
        }
        return ans;
    }
};