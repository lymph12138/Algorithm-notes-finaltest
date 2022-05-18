/*
843
*/
/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    bool helper(string initial,string compare,int k){
        int ans=0;
        for(int i=0;i<initial.size();i++){
            if(initial[i]==compare[i])  ans++;
        }
        return ans==k;
    }
    void findSecretWord(vector<string>& wordlist, Master& master) {
        sort(wordlist.begin(),wordlist.end());
        vector<string> w1=wordlist,w2;
        while(true){
            w2.clear();
            int trynum=rand()%w1.size();
            int cnt=master.guess(w1[trynum]);
            if(cnt==6)  break; 
            for(int i=0;i<w1.size();i++)
                if(helper(w1[trynum],w1[i],cnt))
                    w2.push_back(w1[i]);
            w1=w2;
        }
    }
};