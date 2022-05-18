/*
42
class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int water=0,temp=0;
        int pre=height[0],preidx=0;
        for(int i=1;i<n;i++){
            if(height[i]>=pre){
                pre=height[i];
                preidx=i;
                temp=0;
            }
            else{
                water+=pre-height[i];
                temp+=pre-height[i];
            }
        }
        if(preidx<n-1){
            water-=temp;
            pre=height[n-1];
            for(int i=n-1;i>=preidx;i--){
                if(height[i]>=pre)
                    pre=height[i];
                else
                    water+=pre-height[i];
            }
        }
        return water;
    }
};
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
vector<int> height;
int main()
{

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%d", &height[i]);
    int water = 0, temp = 0;
    int pre = height[0], preidx = 0;
    for (int i = 1; i < n; i++)
    {
        if (height[i] >= pre)
        {
            pre = height[i];
            preidx = i;
            temp = 0;
        }
        else
        {
            water += pre - height[i];
            temp += pre - height[i];
        }
    }
    if (preidx < n - 1)
    {
        water -= temp;
        pre = height[n - 1];
        for (int i = n - 1; i >= preidx; i--)
        {
            if (height[i] >= pre)
                pre = height[i];
            else
                water += pre - height[i];
        }
    }
    printf("%d", water);

    return 0;
}
