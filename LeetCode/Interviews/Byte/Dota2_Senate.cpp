/*
649
*/
class Solution {
public:
    string predictPartyVictory(string senate) {
        int m=senate.size();
        queue<int> radiant,dire;
        for(int i=0;i<m;i++){
            if(senate[i]=='R')   radiant.push(i);
            else    dire.push(i);
        }
        while(radiant.size() && dire.size()){
            int r=radiant.front(),d=dire.front();
            if(r<d){
                radiant.pop();
                radiant.push(r+m);
                dire.pop();
            }
            else{
                dire.pop();
                dire.push(m+d);
                radiant.pop();
            }
        }
        return radiant.size()?"Radiant":"Dire";
    }
};