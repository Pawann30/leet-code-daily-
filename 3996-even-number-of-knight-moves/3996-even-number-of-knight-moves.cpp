class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int dis =0;
        int x = (target[0] - start[0] )* (target[0] - start[0] );
        int y = (target[1] - start[1] ) * (target[1] - start[1] );

        //dis = (int)sqrt(x+y);
        return(( x %2 ==0 && y %2 ==0) ||  ( x %2 !=0 && y %2 !=0)) ? true : false;
        

    }
};