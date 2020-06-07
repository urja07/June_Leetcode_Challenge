class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        int a[n+1][amount+1];
        for(int i=0;i<n+1;i++){
            a[i][0]=1;
        }
        for(int i=1;i<amount+1;i++){
            a[0][i]=0;
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<amount+1;j++){
                if(coins[i-1]>j)
                    a[i][j]=a[i-1][j];
                else
                    a[i][j]=a[i-1][j]+a[i][j-coins[i-1]];
            }
        }
        return a[n][amount];
    }
};
