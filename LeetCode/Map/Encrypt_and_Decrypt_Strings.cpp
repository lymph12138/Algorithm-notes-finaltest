/*
2227
*/
class Encrypter {
public:
    map<char,string> mp;
    map<string,int> freq;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i=0;i<keys.size();i++)    mp[keys[i]]=values[i];
        for(auto word:dictionary){
            string key="";
            for(auto c:word){
                if(!mp.count(c))    key+="**";
                else    key+=mp[c];
            }
            freq[key]++;
        }
    }
    
    string encrypt(string word1) {
        string ans="";
        for(auto c:word1)   ans+=mp[c];
        return ans;
    }
    
    int decrypt(string word2) {
        return freq[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */