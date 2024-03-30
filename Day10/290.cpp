/**
 * @brief ���ʹ���
 *
 */
class Solution {
   public:
    bool wordPattern(string pattern, string s) {
        vector<string> vec;
        unordered_map<string, char> map1;
        unordered_map<char, string> map2;
        string str;
        // �����ַ��� s�������ʴ��� vec ��
        for (int i = 0; i < s.size(); i++) {
            str += s[i];
            if (s[i] == ' ') {
                vec.push_back(str);
                str = "";
            }
        }
        vec.push_back(str);  // �������һ������
        // ��� pattern �� vec �Ĵ�С��һ�£�ֱ�ӷ��� false
        if (pattern.size() != vec.size())
            return false;

        // ���� pattern �� vec�������ַ����ַ������ַ������ַ���ӳ���ϵ
        for (int i = 0; i < pattern.size(); i++) {
            char a = pattern[i];
            string b = vec[i];
            // ��������ӳ�� a -> s2t[a]�����͵�ǰ�ַ�ӳ�� a -> b ��ƥ�䣬
            // ˵����һ�Զ��ӳ���ϵ���򷵻� false ��
            // ����ӳ�� b -> a Ҳͬ��
            // ��鵱ǰӳ���Ƿ��֮ǰ��ӳ���ͻ
            if (map1.find(a) != map1.end() && map1[a] != b ||
                map2.find(b) != map2.end() && map2[b] != a)
                return false;
            // ����ӳ��
            map1[a] = b;
            map2[b] = a;
        }
        return true;
    }
};
