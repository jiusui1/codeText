/**
 * @brief еп╤овспРап
 *
 */
class Solution {
   public:
    bool isSubsequence(string s, string t) {
        int num1, num2;
        while (num1 < s.size() and num2 < t.size()) {
            if (s[num1] == t[num2])
                num1++;
            else
                num2++;
        }
        return num1 == s.size();
    }
};