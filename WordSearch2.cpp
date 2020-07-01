class Trie {
    public: 
    Trie* child[26];
    bool endofword;
    Trie(): endofword(false){
        for(int i=0;i<26; i++)
            child[i] = nullptr;
        }
    ~Trie(){
        for(int i=0;i<26;i++)
            if(child[i]) delete child[i];
    }
        void insert(string word){
            Trie* cur = this;
            for(char c:word){
                if(cur->child[c - 'a']==nullptr){
                    cur->child[c-'a'] = new Trie();
                }
                cur = cur->child[c-'a'];
            }
            cur->endofword = true;
        }
};


class Solution {
    void dfs(vector<vector<char>>& board,int i,int j,unordered_set<string> &res,Trie* trie,string s){
        char c = board[i][j]; 
        if( c=='$')return ;
        board[i][j]='$';
        Trie *t= trie->child[c-'a'];
        if(t){
            string s1=s+c;
            if(t->endofword) res.insert(s1);
            if(i<board.size()-1) dfs(board,i+1,j,res,t,s1);
            if(j<board[0].size()-1) dfs(board,i,j+1,res,t,s1);
            if(i>0) dfs(board,i-1,j,res,t,s1);
            if(j>0) dfs(board,i,j-1,res,t,s1);
        }
        board[i][j] = c;
    }
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(words.size()==0)
            return {};
        Trie trie;
        for(string w: words)
            trie.insert(w);
        unordered_set<string> res;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                dfs(board,i,j,res,&trie, "");
            }      
        }
        vector<string> v(res.begin(),res.end());
        return v;
    }
};
