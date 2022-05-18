/*
208
*/
class Trie {
private:
    bool isEnd;
    Trie* next[26];
public:
    Trie() {
        isEnd=false;
        memset(next,0,sizeof(next));
    }
    
    void insert(string word) {
        Trie* node=this;
        for(auto c:word){
            if(!node->next[c-'a'])
                node->next[c-'a']=new Trie();
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }
    
    bool search(string word) {
        Trie* node=this;
        for(auto c:word){
            node=node->next[c-'a'];
            if(!node)   return false;
        }
        return node->isEnd;
    }
    
    bool startsWith(string prefix) {
        Trie* node=this;
        for(auto c:prefix){
            node=node->next[c-'a'];
            if(!node)   return false;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */