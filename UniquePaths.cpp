class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> v(n,vector<int>(m));
        for(int i=0;i<m;i++){
            v[n-1][i]=1;
        }
        for(int i=0;i<n;i++){
            v[i][m-1]=1;
        }
        for(int i=n-2;i>=0;i--){
            for(int j=m-2;j>=0;j--){
             v[i][j]=v[i+1][j]+v[i][j+1];   
            }
        }
        return v[0][0];
    }
};
