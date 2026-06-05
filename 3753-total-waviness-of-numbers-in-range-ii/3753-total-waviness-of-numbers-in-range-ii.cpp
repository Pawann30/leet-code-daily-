class Solution {
public:
    struct Node {
        long long ways;
        long long wave;
    };

    string s;
    Node dp[20][11][11][2][2];
    bool vis[20][11][11][2][2];

    Node dfs(int pos, int prev1, int prev2,
             bool tight, bool started) {

        if (pos == s.size())
            return {1, 0};

        if (vis[pos][prev1][prev2][tight][started])
            return dp[pos][prev1][prev2][tight][started];

        vis[pos][prev1][prev2][tight][started] = true;

        Node ans = {0, 0};

        int lim = tight ? s[pos] - '0' : 9;

        for (int d = 0; d <= lim; d++) {

            bool ntight = tight && (d == lim);

            if (!started && d == 0) {
                Node child = dfs(pos + 1, 10, 10, ntight, false);

                ans.ways += child.ways;
                ans.wave += child.wave;
            }
            else {
                long long extra = 0;

                if (started && prev2 != 10) {
                    if ((prev1 > prev2 && prev1 > d) ||
                        (prev1 < prev2 && prev1 < d))
                        extra = 1;
                }

                int nprev2, nprev1;

                if (!started) {
                    nprev2 = 10;
                    nprev1 = d;
                }
                else if (prev2 == 10) {
                    nprev2 = prev1;
                    nprev1 = d;
                }
                else {
                    nprev2 = prev1;
                    nprev1 = d;
                }

                Node child =
                    dfs(pos + 1, nprev1, nprev2, ntight, true);

                ans.ways += child.ways;
                ans.wave += child.wave + extra * child.ways;
            }
        }

        return dp[pos][prev1][prev2][tight][started] = ans;
    }

    long long solve(long long x) {
        if (x < 0) return 0;

        s = to_string(x);

        memset(vis, 0, sizeof(vis));

        return dfs(0, 10, 10, true, false).wave;
    }

    long long totalWaviness(long long num1, long long num2) {
        return solve(num2) - solve(num1 - 1);
    }
};