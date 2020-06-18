class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int r=board.size();
        if(r<=2)
            return;
        int c=board[0].size();
        if(c<=2)
            return;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==r-1 || j==c-1))
                {
                    change(board,i,j);
                }
            }
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++){
                if(board[i][j]=='O')
                {
                  board[i][j]='X';
                }
                else if(board[i][j]=='a')
                {
                    board[i][j]='O';
                }
            }
        }
        
    }
    void change(vector<vector<char>>& board,int r,int c){
        if(r>=0 && r<board.size() & c>=0 && c<board[0].size() && board[r][c]=='O'){
            board[r][c]='a';
            change(board,r+1,c);
            change(board,r-1,c);
            change(board,r,c+1);
            change(board,r,c-1);
        } 
    }
};
