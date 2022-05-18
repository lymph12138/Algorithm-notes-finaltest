/*
241
*/
class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n=expression.size();
        vector<int> ways;
        if(n==1 || n==2){
            ways.push_back(stoi(expression));
            return ways;
        }
        for(int i=0;i<n;i++){
            char c=expression[i];
            if(c=='+' || c=='-' || c=='*'){
                vector<int> left=diffWaysToCompute(expression.substr(0,i));
                vector<int> right=diffWaysToCompute(expression.substr(i+1));
                for(int l=0;l<left.size();l++){
                    for(int r=0;r<right.size();r++){
                        switch (c){
                            case '+':ways.push_back(left[l]+right[r]);break;
                            case '-':ways.push_back(left[l]-right[r]);break;
                            case '*':ways.push_back(left[l]*right[r]);break;
                        }
                    }
                }
            }
        }
        return ways;
    }
};