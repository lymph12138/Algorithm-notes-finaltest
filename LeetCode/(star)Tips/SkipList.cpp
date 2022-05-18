//http://zhangtielei.com/posts/blog-redis-skiplist.html
class Skiplist {
private:
    struct SkipListNode{
        int val;
        vector<SkipListNode *> level;
        SkipListNode(int x,int size=32):val(x),level(size){}
    };
    SkipListNode *head,*tail;
    int level,length;
public:
    const int MaxLevel=32;
    Skiplist() {
        level=length=0;
        tail=new SkipListNode(INT_MAX,0);
        head=new SkipListNode(INT_MAX);
        for(int i=0;i<MaxLevel;i++)
            head->level[i]=tail;
    }
    int randomlevel(){
        int level=1;
        while(level<MaxLevel && rand()%4==1)
            level++;
        return level;
    }
    bool search(int target) {
        SkipListNode* p=head;
        for(int i=level-1;i>=0;i--)
            while(p->level[i] && p->level[i]->val<target)
                p=p->level[i];
        return p->level[0]->val==target;
    }
    
    void add(int num) {
        vector<SkipListNode*> pre(MaxLevel);
        SkipListNode* p=head;
        for(int i=level-1;i>=0;i--){
            while(p->level[i] && p->level[i]->val<num)
                p=p->level[i];
            pre[i]=p;
        }
        int lv=randomlevel();
        if(lv>level){
            lv=++level;
            pre[lv-1]=head;
        }
        SkipListNode* newnode=new SkipListNode(num,lv);
        for(int i=lv-1;i>=0;i--){
            p=pre[i];
            newnode->level[i]=p->level[i];
            p->level[i]=newnode;
        }
        length++;
    }
    
    bool erase(int num) {
        vector<SkipListNode*> pre(MaxLevel);
        SkipListNode* p=head;
        for(int i=level-1;i>=0;i--){
            while(p->level[i] && p->level[i]->val<num)
                p=p->level[i];
            pre[i]=p;
        }
        p=p->level[0];
        if(p->val!=num) return false;
        for(int i=0;i<level;i++){
            if(pre[i]->level[i]!=p)    break;
            pre[i]->level[i]=p->level[i];
        }
        while(level && head->level[level-1]==tail)  level--;
        length--;
        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */