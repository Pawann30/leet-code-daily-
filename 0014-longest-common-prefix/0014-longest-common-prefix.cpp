class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans;
        sort(strs.begin(),strs.end());
        int n = strs.size();
        string a = strs[0];
        string b = strs[n-1];
        int maxx = max(a.length(),b.length());
        for(int i=0;i<maxx;i++){
            if(a[i] == b[i]){
                ans.push_back(a[i]);
            }else{
                break;
            }
        }
        if(ans.length() == 0)
            return "";

        return ans;
    }
};