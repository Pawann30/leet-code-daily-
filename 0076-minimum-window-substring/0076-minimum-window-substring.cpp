class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.length();
        int m= t.length();
        unordered_map<char,int> mp;
        if(m>n) return "";
        for(int i=0;i<m;i++){
            mp[t[i]]++;
        }
        int Min=INT_MAX;
        int j=0;
        int start =0;
        for(int i=0;i<n;i++){
            if(mp.count(s[i])){
                mp[s[i]]--;
            }
            bool allZero = true;
            for(auto &it : mp){
                if(it.second>0){
                    allZero = false;
                    break;
                }
            }
            while(allZero){
                if(i-j+1 < Min){
                    Min = i-j+1;
                    start=j;
                }
                if(mp.count(s[j])){
                    mp[s[j]]++;
                }
                j++;
                allZero = true;
                for(auto &it : mp){
                    if(it.second>0){
                        allZero = false;
                        break;
                    }
                }
            }
        }
        return Min==INT_MAX ? "" : s.substr(start,Min);
    }
};