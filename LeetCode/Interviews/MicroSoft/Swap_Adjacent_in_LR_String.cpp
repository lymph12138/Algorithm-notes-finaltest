/*
777
*/
class Solution {
public:
    bool canTransform(string start, string end) {
        int n=start.size();
        int s=0,e=0;
        for(;e<n;e++){
            if(end[e]=='X') continue;
            while(s<n && start[s]=='X') s++;
            if(s==n)    return false;
            if(end[e]=='L'){
                if(start[s]!='L' || e>s)
                    return false;
            }
            else{
                if(start[s]!='R' || s>e)
                    return false;
            }
            s++;
        }
        while(s<n && start[s]=='X') s++;
        return s==n;
    }
};