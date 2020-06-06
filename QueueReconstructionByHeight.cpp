bool f(const vector<int>&a ,const vector<int> &b){
    return a[0]>b[0] || a[0]==b[0] && a[1]<b[1];
}
class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
     vector<vector<int>> v;
     sort(people.begin(),people.end(),f);
     for(auto i:people){
         v.insert(v.begin()+i[1],i);
     }
    return v;
    }
};
