class bitmask{
public:
    int num=31;
    int n=__builtin_popcount(num);//
    int m=__builtin_ctz(num);
}