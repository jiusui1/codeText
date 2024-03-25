/**
 * @brief 验证回文串
 *
 */
class Solution {
   public:
    bool isPalindrome(string s) {
        int left, right;
        for (int i = 0; i < s.size();) {
            if (isalnum(s[i])) {
                i++;
            } else {
                s.erase(s.begin() + i);
            }
        }
        left = 0;
        right = s.size() - 1;
        while (left < right) {
            if (tolower(s[left++]) != tolower(s[right--]))
                return false;
        }
        return true;
    }
};