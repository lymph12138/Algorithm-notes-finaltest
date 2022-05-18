/*
447
*/
class Solution {
public:
    int dist(vector<int> a,vector<int> b){
        return (a[0]-b[0])*(a[0]-b[0])+(a[1]-b[1])*(a[1]-b[1]);
    }
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int n=points.size();
        int ans=0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            mp.clear();
            for(int j=0;j<n;j++){
                if(i!=j){
                    mp[dist(points[i],points[j])]++;
                }
            }
            for(auto it=mp.begin();it!=mp.end();it++){
                if(it->second>1)
                    ans+=it->second*(it->second-1);
            }
        }
        return ans;
    }
};