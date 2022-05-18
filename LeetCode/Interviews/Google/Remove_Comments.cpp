/*
722
*/
class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> ans;
        bool tag=false;
        for(auto line:source){
            if(!tag && (ans.empty()||ans.back()!=""))
                ans.push_back("");
            int i=0;
            while(i<line.size()){
                if(line.substr(i,2)=="//"){
                    if(!tag)    break;
                }
                else if(line.substr(i,2)=="/*"){
                    if(!tag){
                        tag=true;
                        i+=2;
                        continue;
                    }
                }
                else if(line.substr(i,2)=="*/"){
                    if(tag){
                        tag=false;
                        i+=2;
                        continue;
                    }
                }
                if(!tag)    ans.back().push_back(line[i]);
                i++;
            }
        }
        return ans;
    }
};