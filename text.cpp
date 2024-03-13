#include <iostream>

int func(unsigned int v)
{
    v ^= v >> 16;
    v ^= v >> 8;
    v ^= v >> 2;
    v &= 0xf;
    return (0x6996 >> v) & 1;
}
int funb(int n) // 10
{
    unsigned int t = 1 << n;
    int val = 0;
    for (int i = 0; i < t; ++i) // 1024
    {
        val += func(i);
    }
    return val;
}

int main()
{
    funb(10);
}