class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int r=dungeon.size();
        int c=dungeon[0].size();
        vector<vector<int>> res(r,vector<int>(c));
        res[r-1][c-1] = dungeon[r-1][c-1] > 0 ? 1:1-dungeon[r-1][c-1];
        
        for(int i=r-2;i>=0;i--){
            res[i][c-1] = max(res[i+1][c-1] - dungeon[i][c-1],1);
        }
        for(int j=c-2;j>=0;j--){
            res[r-1][j] = max(res[r-1][j+1] - dungeon[r-1][j],1 );
        }
        for(int i=r-2;i>=0;i--){
            for(int j=c-2;j>=0;j--){
                res[i][j]=max(min(res[i+1][j],res[i][j+1])- dungeon[i][j],1);
            }
        }
        return res[0][0];
    }
};
