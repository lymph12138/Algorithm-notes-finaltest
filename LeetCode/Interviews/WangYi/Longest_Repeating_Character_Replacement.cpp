/*
424
*/
class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int> mp;
        int left=0,right=0,ans=0,same=0;
        for(right=0;right<s.size();right++){
            same=max(same,++mp[s[right]]);
            while(right-left+1>k+same){
                mp[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};