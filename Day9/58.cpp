#include <string>

class Solution {
   public:
    int lengthOfLastWord(std::string s) {
        int n = s.size() - 1;
        int size = 0;
        bool foundLastWord = false;  // ����Ƿ��ҵ����һ������
        //"   fly me   to   the moon  "
        for (int i = n; i >= 0; i--) {
            if (s[i] == ' ') {
                if (foundLastWord) {
                    break;  // �Ѿ��ҵ����һ�����ʣ����������ո񣬽���ѭ��
                }
                continue;  // ���������Ŀո�
            } else {
                size++;
                foundLastWord = true;  // �ҵ������һ������
            }
        }
        return size;
    }
};