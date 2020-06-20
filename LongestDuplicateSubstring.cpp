class Solution {
public:
    string longestDupSubstring(string S) {
        int start = 0;
        int end = S.size()-1;
        string_view res;
        unordered_set<string_view> p;
        while (start <= end){
            int len = start + ((end-start)>>1);
            bool found = false;
            for (int i = 0; i < S.size()+1-len; i++){              
                string_view str = string_view(S).substr(i, len);   
                if (p.count(str)){                              
                    res = str;
                    found = true;
                    break;
                } else
                    p.emplace(str);
            }
            if (found)
                start = len+1;
            else
                end = len-1;        
            p.clear();           
        }
        return {res.begin(),res.end()};    
    }
};
