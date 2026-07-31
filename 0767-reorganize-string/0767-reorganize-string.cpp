class Solution {
public:
    string reorganizeString(string s) {
        vector<int> freq(26,0);
        int n = s.length();
        for(char c : s){
            freq[c -'a']++;
            if(freq[c - 'a'] > (n+1)/2){
                return "";
            }
        }
        priority_queue<pair<int,char>> pq;
        for(int i =0;i<26;i++){
            if(freq[i]>0){
                pq.push({freq[i],char(i+'a')});
            }
        }
        string ans;
        while(pq.size() >= 2){
            auto first = pq.top();
            pq.pop();
            auto sec = pq.top();
            pq.pop();

            ans.push_back(first.second);
            ans.push_back(sec.second);

            first.first--;
            sec.first--;

            if(first.first > 0){
                pq.push(first);
            }
            if(sec.first > 0){
                pq.push(sec);
            }
        }
        if(!pq.empty()){
            ans.push_back(pq.top().second);
        }
        return ans;
    }
};