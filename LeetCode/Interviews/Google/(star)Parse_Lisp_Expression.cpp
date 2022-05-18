/*
736
*/

class Solution {
private:
    int brackets[2010];
    vector<map<string,int>> VariableList;
    bool IsLetter(char c){
        return c>='a' && c<='z';
    }
    bool IsDigit(char c){
        return (c>='0' && c<='9') || c=='-';
    }
    int GetVariable(const string& variable){
        for(auto ptr=VariableList.crbegin();ptr!=VariableList.crend();ptr++){
            auto ptr2=ptr->find(variable);
            if(ptr2!=ptr->end())
                return ptr2->second;
        }
        return 0;
    }
public:
    int evaluate(string expression) {
        
    }
};