/*
857
*/
class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double,int>> worker;
        for(int i=0;i<wage.size();i++)
            worker.push_back({wage[i]*1.0/quality[i],quality[i]});
        sort(worker.begin(),worker.end());
        priority_queue<int> pq;
        int sumq=0;
        int temp=0;
        for(auto q:quality) temp+=q;
        double mincost=worker.back().first*temp;
        for(auto [r,q]:worker){
            sumq+=q;
            pq.push(q);
            if(pq.size()>k){
                sumq-=pq.top();
                pq.pop();
            }
            if(pq.size()==k)   mincost=min(mincost,r*sumq); 
        }
        return mincost;
    }
};