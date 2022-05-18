class Trie{
private:
    bool isEnd;
    Trie* next[26];
public:
    void insert(string word){
        Trie* node = this;
        for(auto c:word){
            if(!node->next[c-'a'])
                node->next[c-'a']=new Trie();
            node=node->next[c-'a'];
        }
        node->isEnd=true;
    }
    bool search(string word){
        Trie* node=this;
        for(auto c:word){
            node=node->next[c-'a'];
            if(!node)   return false;
        }
        return node->isEnd;
    }
    bool startWith(string prefix){
        Trie* node=this;
        for(auto c:prefix){
            node=node->next[c-'a'];
            if(!node)   return false;
        }
        return true;
    }
};