class Solution {
public:
    bool isSubsequence(string s, string t) {
        int count=0;
        int m=t.size(),i=0,j=0;
        int n=s.size();
        while(i<m && j<n){
            if(t[i]==s[j])
            {
                count++;
                j++;
            }
            i++;
        }
        if(n==count)
            return true;
        else
            return false;
    }
};
