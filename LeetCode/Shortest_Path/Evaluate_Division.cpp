/*
399
*/
class Solution {
public:
    
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values,
     vector<vector<string>>& queries) {
        map<string,map<string,double>> data;
        int n=equations.size();
        for(int i=0;i<n;i++){
            data[equations[i][0]][equations[i][1]]=values[i];
            data[equations[i][1]][equations[i][0]]=1.0/values[i];
        }
        vector<double> ans;
        for(int i=0;i<queries.size();i++){
            double res=-1.0;
            set<string> used;
            DFS(data,queries[i][0],queries[i][1],1.0,used,res);
            ans.push_back(res);
        }
        return ans;
    }
    void DFS(map<string,map<string,double>>& data, string begin, string end, double multi, set<string>& used, double& res){
        used.insert(begin);
        if(data.find(begin)==data.end())    return;
        if(begin==end){
            res=multi;
            return;
        }
        for(auto it=data[begin].begin();it!=data[begin].end();it++){
            if(used.find(it->first)!=used.end())    continue;
            DFS(data,it->first,end,multi*it->second,used,res);
        }
    }
};