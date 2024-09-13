class Solution {
public:
    int ver[8] = {2, 2, -2, -2, 1, -1, 1, -1}; //Night horizontal movement coordinates
    int hor[8] = {1, -1, 1, -1, 2, 2, -2, -2}; // Night vertical movement coordinates
    int dp[5001][3][4];
    int x = 0, y = 0;
    int ans=0;

    bool isValidPosition(int x, int y) {
        if(x == 1 && y == 0) return true;
        if(x <0 || x > 2 ) return false;
        if(y<1 | y > 3) return false;
        return true;
    }

    void getNextPos() {
        while(x++) {
            if(x>2) {
                x=0, y++;
            }
            if(isValidPosition(x, y)) return;
            if(y>4) return;
        }
    }

    int solve(int px, int py, int p) {
        if(p==1) return dp[p][px][py]=1;
        int tmp=0;

        if(dp[p][px][py] !=-1) return dp[p][px][py];
        else {
            for(int i = 0; i < 8; i++) {
                if(isValidPosition(px+hor[i], py+ver[i])){
                    tmp = (tmp+ solve(px+hor[i], py+ver[i], p-1)) % 1000000007 ; // Sum up using DP.
                }
            }
            return dp[p][px][py]= tmp;
        }
    }

    int knightDialer(int n) {
        int ans = 0;
        memset(dp, -1, sizeof(dp));

        for(int i = 0; i < 10; i++) { // only 10 initial positions.
            getNextPos();

            ans = (ans + solve(x, y, n)) % 1000000007;
        }
        return ans;
    }
};
