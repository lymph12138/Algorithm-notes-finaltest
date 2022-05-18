/*
1130
*/
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        vector<vector<int>> maxnum(n,vector<int>(n,0));
        for(int i=0;i<n;i++){
            maxnum[i][i]=arr[i];
            for(int j=i+1;j<n;j++){
                maxnum[i][j]=max(maxnum[i][j-1],arr[j]);
            }
        }
        for(int len=1;len<=n;len++){
            for(int i=0;i+len<n;i++){
                dp[i][i+len]=INT_MAX;
                for(int k=i;k<i+len;k++)
                    dp[i][i+len]=min(dp[i][i+len],dp[i][k]+dp[k+1][i+len]+maxnum[i][k]*maxnum[k+1][i+len]);
            }
        }
        return dp[0][n-1];
    }
};

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<int> stack;
        int ans=0;
        stack.push_back(INT_MAX);
        for(auto a:arr){
            while(stack.back()<=a){
                int mid=stack.back();
                stack.pop_back();
                ans+=mid*min(stack.back(),a);
            }
            stack.push_back(a);
        }
        for(int i=2;i<stack.size();i++)
            ans+=stack[i]*stack[i-1];
        return ans;
    }
};