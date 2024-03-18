#include <iostream>
#include <string>

int main()
{
    std::string s = "a";
    bool capitalizeNext = true;             // 用于标记下一个字符是否需要大写

    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            capitalizeNext = true;          // 下一个字符是单词的首字母
        }
        else
        {
            if (capitalizeNext)
            {
                s[i] -= 32;                 // 将当前字母转换为大写
                capitalizeNext = false;    // 下一个字母不需要大写
            }
        }
    }
    std::cout << s << std::endl;
    return 0;
}