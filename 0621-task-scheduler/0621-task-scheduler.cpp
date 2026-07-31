class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(char c : tasks){
            freq[c - 'A']++;
        }
        priority_queue<pair<int,char>> pq;
        for(int i=0; i<26; i++){
            if(freq[i]>0){
                pq.push({freq[i],char(i+'A')});
            }
        }
        int count = 0;
        while(!pq.empty()){
            vector<pair<int,char>> temp;
            int cycle = n+1;
            while(cycle > 0 && !pq.empty()){
                auto f = pq.top();
                pq.pop();
                f.first--;
                count++;
                cycle--;

                if(f.first>0){
                    temp.push_back(f);
                }
            }
            for(auto x : temp){
                pq.push(x);
            }
            if(pq.empty()){
                break;
            }
            count += cycle;
        }
        return count;
    }
};