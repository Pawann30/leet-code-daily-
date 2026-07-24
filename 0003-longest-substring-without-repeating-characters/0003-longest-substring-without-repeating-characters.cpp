class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<int,int> freq;
        int n =s.length();
        int count = 0;
        int maxi =0;
        int i =0, j =0;
        while(i < n ){
            
            freq[s[i]-'a']++;
            while(freq[s[i]-'a'] >1){
                
                freq[s[j]-'a']--;
                j++;
               // count--;
            }
           
                 i++;
            count = i-j;
           
            
            maxi = max(count,maxi);
            }

            
        
        return maxi;
        /*
        vector<int> freq(26,0);
        int n = s.length();
        int count = 0;
        int maxx = 0;
        for(int i =0;i<n;i++){
            freq[s[i] - 'a']++;
            if(freq[s[i]-'a'] > 1){
                count = ;
                freq[s[i]-'a']--;
            }else{
                count++;
                maxx = max(count , maxx);
            }
        }
        return maxx;
*/
}
};