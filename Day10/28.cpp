/**
 * @brief  找出字符串中第一个匹配项的下标
 * @details
 *
 */
class Solution {
   public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        if (haystack.size() == 0)
            return -1;
        return haystack.contains(needle);
    }
};