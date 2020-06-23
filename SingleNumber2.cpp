class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }
        for(auto i:m){
            if(i.second!=3)
                return i.first;
        }
        return 0;
    }
};
