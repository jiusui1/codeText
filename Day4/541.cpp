/**
 * @brief      This class describes a solution.
 * 541. 反转字符串 II
 */
class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size(); i += 2*k)
        {
            if(i + k <= s.size()){
                reverse(s.begin() + i, s.begin() + i +k);
            }
            else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};