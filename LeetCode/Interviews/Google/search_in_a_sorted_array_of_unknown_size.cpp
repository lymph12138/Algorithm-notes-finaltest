/*
702
*/

/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int n=pow(2,31)-1;
        int l=0,r=10000,mid;
        
        while(l<=r){
            mid=(l+r)/2;
            if(reader.get(mid)==n || reader.get(mid)>target){
                r=mid-1;
                continue;
            }
            if(reader.get(mid)<target){
                l=mid+1;
                continue;
            }
            if(reader.get(mid)==target)
                return mid;
        }
        return -1;
    }
};