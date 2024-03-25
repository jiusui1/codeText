/**
 * @brief 单词规律
 *
 */
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        unordered_map<string, char> map1;
        unordered_map<char, string> map2;
        string str;
        // 解析字符串 s，将单词存入 vec 中
        for (int i = 0; i < s.size(); i++) {
            str += s[i];
            if (s[i] == ' ') {
                vec.push_back(str);
                str = "";
            }
        }
        vec.push_back(str);  // 处理最后一个单词
        // 如果 pattern 和 vec 的大小不一致，直接返回 false
        if (pattern.size() != vec.size())
            return false;

        // 遍历 pattern 和 vec，建立字符到字符串和字符串到字符的映射关系
        for (int i = 0; i < pattern.size(); i++) {
            char a = pattern[i];
            string b = vec[i];
            // 对于已有映射 a -> s2t[a]，若和当前字符映射 a -> b 不匹配，
            // 说明有一对多的映射关系，则返回 false ；
            // 对于映射 b -> a 也同理
            // 检查当前映射是否和之前的映射冲突
            if (map1.find(a) != map1.end() && map1[a] != b ||
                map2.find(b) != map2.end() && map2[b] != a)
                return false;
            // 更新映射
            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};

