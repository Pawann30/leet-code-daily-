class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> a=arr;
        sort(a.begin(),a.end());
        map<int,int> mp;

        int n = arr.size();
        int r = 1;
        for(int i=0;i<n;i++){
            if(mp.find(a[i]) == mp.end()){
                mp[a[i]] = r++;
            }
        }
        for(int i = 0; i< arr.size(); i++){
            arr[i] = mp[arr[i]];
        }
        return arr;

    }
};