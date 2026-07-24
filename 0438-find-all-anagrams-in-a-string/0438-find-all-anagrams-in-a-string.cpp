class Solution {
public:
    bool allzero(vector<int>&freq){
        for(int i =0 ;i < 26;i++){
            if(freq[i] !=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>freq(26,0);
        vector<int> ans;
        int n = p.length();
        int m = s.length();
        if(n > m){
            return ans;
        }
        for(int i=0; i<n; i++){
            freq[p[i]-'a']++;
            //freq2[p[i]-'a']++;
        }
        
        for(int i =0 ;i<n;i++ ){
            freq[s[i]-'a']--;

        }
        int i = n;
        
        while(i < m){
            if(allzero(freq) == true ){
                ans.push_back(i-n);
                //i++;
            }
                freq[s[i-n]-'a']++;
                
                freq[s[i]-'a']--;
                i++;
        
        }
        if(allzero(freq)){
            ans.push_back(m-n);
        }
        return ans;


    }
};