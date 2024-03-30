/**
 * @brief ͬ���ַ���
 *
 */
class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> t2s, s2t;
        for (int i = 0; i < s.size(); i++) {
            char a = s[i], b = t[i];
            // ��������ӳ�� a -> s2t[a]�����͵�ǰ�ַ�ӳ�� a -> b ��ƥ�䣬
            // ˵����һ�Զ��ӳ���ϵ���򷵻� false ��
            // ����ӳ�� b -> a Ҳͬ��
            if (s2t.find(a) != s2t.end() && s2t[a] != b ||
                t2s.find(b) != t2s.end() && t2s[b] != a)
                return false;
            s2t[a] = b;
            t2s[b] = a;
        }
        return true;
    }
};