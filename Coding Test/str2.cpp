#include <iostream>

int main(int argc, char const *argv[])
{
    std::string s = "a";
    int fast = 0, slow = 0;
    for (size_t i = 0; i < s.size(); i++)
    {
        slow = fast;
        while (s[fast] != ' ' && fast < s.size())
        {
            fast++;
        }
        while (s[fast] == ' ' && fast < s.size())
        {
            fast++;
        }
        i = i == s.size() ? fast - 1 : fast;
        s[slow] -= 32;
    }
    std::cout << s << std::endl;
    return 0;
}
