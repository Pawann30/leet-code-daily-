class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        for(int l=2; l<= 9;l++) {
            for (int i=0;i+l <=9; i++) {
                int num =stoi(s.substr(i,l));
                if (num >= low && num <= high)
                    ans.push_back(num);
            }
        }

        return ans;
    }
};