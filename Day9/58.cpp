#include <string>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        int n = s.size() - 1;
        int size = 0;
        bool foundLastWord = false;  // 标记是否找到最后一个单词
        //"   fly me   to   the moon  "
        for (int i = n; i >= 0; i--) {
            if (s[i] == ' ') {
                if (foundLastWord) {
                    break;  // 已经找到最后一个单词，并且遇到空格，结束循环
                }
                continue;  // 跳过连续的空格
            } else {
                size++;
                foundLastWord = true;  // 找到了最后一个单词
            }
        }
        return size;
    }
};
