/*
418
*/
class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int m=sentence.size();
        int idx=0,word=0,ans=0;
        for(int i=0;i<rows;i++){
            idx=0;
            while((idx?idx:idx-1)+sentence[word].size()+1<=cols){
                idx=(idx?idx:idx-1)+sentence[word].size()+1;
                word=word+1;
                if(word==m){
                    ans++;
                    word=0;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int m=sentence.size();
        vector<int> dp(m,0),next(m,0);
        for(int i=0;i<m;i++){
            int n=cols;
            int p=i,cnt=0;
            while(n>=(int)sentence[p].size()){
                n-=sentence[p].size()+1;
                p++;
                if(p==m){
                    p=0;
                    cnt++;
                }
            }
            dp[i]=cnt;
            next[i]=p;
        }
        int ans=0,cur=0;
        for(int i=0;i<rows;i++){
            ans+=dp[cur];
            cur=next[cur];
        }
        return ans;
    }
};