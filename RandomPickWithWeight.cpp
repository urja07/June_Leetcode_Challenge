class Solution {
    vector<int> v;
    int sum;
public:
    Solution(vector<int>& w) {
        sum=0;
        for(auto i : w) {
            sum+=i;
            v.push_back(sum);
            }
    }
    int pickIndex() {
        int k=rand()%sum;
        /* Linear Search
        int p=0;
        for (int i =0;i<v.size()-1;i++)
        {
            if(k>=v[i] && k<v[i+1])
                p=i+1;
        }
        return p;
        */
        return search(k+1);
    }
       // Binary Search
    int search(int k){
        int l=0;
        int r=v.size()-1;
        while(l<r){
            int mid = l+(r-l)/2;
             if(v[mid]<k)
                 l=mid+1;
             else 
                 r=mid;
        }
        return l;
    }
};
