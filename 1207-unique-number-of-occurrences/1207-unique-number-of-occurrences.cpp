class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        int n=arr.size();
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
        }
        unordered_map<int,int> Mp;
        for(auto it : mp){
            Mp[it.second]++;
            if(Mp[it.second]>1){
                return false;
            }
        }
        
        return true;
    }
};