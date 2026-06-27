class Solution {
public:
    int maximumLength(vector<int>& nums) {
         unordered_map<long long, int> mp;

        for (int x : nums)
            mp[x]++;

        int ans = 1;

        if (mp.count(1)) {
            ans = max(ans, (mp[1] % 2 == 0) ? mp[1] - 1 : mp[1]);
        }

        for (auto &[x, cnt] : mp) {
            if (x == 1) continue;

            long long cur = x;
            int len = 0;

            while (true) {
                if (!mp.count(cur) || mp[cur] == 0) {
                    len--;
                    break;
                }

                long long nxt = cur * cur;

                if (cur > 1000000000LL / cur || !mp.count(nxt)) {
                    len++;
                    break;
                }

                if (mp[cur] >= 2) {
                    len += 2;
                    cur = nxt;
                } else {
                    len++;
                    break;
                }
            }

            ans = max(ans, len);
        }

        return ans;
    }
};