/*
753
*/
class Solution {
public:
    set<string> visited;
    string ans;
    void dfs(string s, int k){
        string temp;
        for(int i=0;i<k;i++){
            temp=s+to_string(i);
            if(!visited.count(temp)){
                visited.insert(temp);
                dfs(temp.substr(1),k);
                ans+=to_string(i);
            }
        }
    }
	string crackSafe(int n, int k) {
		if(n==1 && k==1)    return "0";
        ans="";
        string s="";
        for(int i=0;i<n-1;i++)  s+="0";
        dfs(s,k);
        for(int i=0;i<n-1;i++)  ans+="0";
        return ans;
	}
};

class Solution {
public:
	string crackSafe(int n, int k) {
		map<string, int> mp;
        string ans="";
        for(int i=0;i<n-1;i++)  ans+="0";
        for(int i=0;i<pow(k,n);i++){
            string temp=ans.substr(ans.size()-n+1,n-1);
            mp[temp]=(mp[temp]+1)%k;
            ans+=('0'+mp[temp]);
        }
        return ans;
	}
};