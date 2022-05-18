/*
30
*/
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        unordered_map<string,int> mp;
        int size=words[0].size(),m=words.size(),n=s.size();
        for(int i=0;i<m;i++){
            mp[words[i]]++;
        }
        for(int i=0;i<size;i++){
            unordered_map<string,int> temp;
            string pre;
            for(int k=0;k<m;k++){
                string st=s.substr(i+k*size,size);
                if(mp.count(st))  temp[st]++;
            }
            if(temp==mp)    ans.push_back(i);
            int l=1;
            while(l*size+i<=n-size*m){
                string st=s.substr(i+m*size+l*size-size,size);
                if(mp.count(st))    temp[st]++;
                pre=s.substr(i+l*size-size,size);
                if(mp.count(pre))   temp[pre]--;
                if(temp==mp)    ans.push_back(i+l*size);
                l++;
            }
        }
        return ans;
    }
};