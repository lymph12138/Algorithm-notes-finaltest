/*
7
*/
class Solution {
public:
    int reverse(int x) {
        long long int res = 0;
        while(x)
        {
            res = res*10 + x%10;
            x /= 10;
            
            if(abs(res) > INT_MAX)
                return 0;
        }
        return res;
    }
};