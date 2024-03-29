/**
 * @brief      This class describes a solution.
 * 383. 赎金信
 */
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};

        if (ransomNote.size() > magazine.size())
        {
            return false;
        }
        for (int i = 0; i < magazine.size(); ++i)
        {
            record[magazine[i] - 'a']++;
        }

        for (int j = 0; j < ransomNote.size(); ++j)
        {
            record[ransomNote[j] - 'a']--;
            if (record[ransomNote[j] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};