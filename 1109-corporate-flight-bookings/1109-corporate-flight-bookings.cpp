class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> ans(n+2,0);
        for(int i =0;i<bookings.size();i++){
            int a=bookings[i][0];
            int b=bookings[i][1];

            ans[a] += bookings[i][2];
            ans[b+1] -= bookings[i][2];
        }
        int sum = 0;
        for(int i=0;i<n+2;i++){
            sum +=ans[i];
            ans[i]=sum;
        }
        return vector<int>(ans.begin()+1,ans.begin()+n+1);
    }
};