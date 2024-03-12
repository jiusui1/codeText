#include <iostream>
#include <cstring>
using namespace std;
int main(int argc, char *argv[])
{
    cout << sizeof("str") << ", " << strlen(string("hello").c_str());
    return 0;
}