/*
243
*/
class Solution {
public:
    int shortestDistance(vector<string>& wordsDict, string word1, string word2) {
        vector<int> w1,w2;
        for(int i=0;i<wordsDict.size();i++){
            if(wordsDict[i]==word1) w1.push_back(i);
            else if(wordsDict[i]==word2)    w2.push_back(i);
        }
        int ans=INT_MAX,pos1=0,pos2=0;
        while(pos1<w1.size() && pos2<w2.size()){
            ans=min(ans,abs(w1[pos1]-w2[pos2]));
            if(w1[pos1]<w2[pos2]){
                pos1++;
            }
            else    pos2++;
        }
        return ans;
    }
};