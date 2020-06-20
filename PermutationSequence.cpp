class Solution {
public:
    vector<string> v;
    string getPermutation(int n, int k) {
        string s="";
        for(int i=0;i<n;i++){
            
            s.push_back(i+49);
        }
        int curPerm = 1;
        while (curPerm < k) {
            curPerm++;
            next_permutation(s.begin(), s.end());
        }
        return s;
       
    }
};
