#include <string.h>
#include <iostream>
using namespace std;

namespace china {
class string {
   public:
    friend ostream &operator<<(ostream &out, const china::string &s);
    string(const char *s = NULL);
    ~string();
    string(const string &rhs);
    string &operator=(const string &rhs);

    // �ƶ�����
    string(string &&rhs);
    // �ƶ���ֵ
    string &operator=(string &&rhs);

    size_t size() const;
    // ������[]��������������ع�ϵ
    char &operator[](int index);
    char operator[](int index) const;

    // ���ӵ���������
    class iterator {
       public:
        iterator(char *p)
            : _pos(p) {}

        iterator &operator++() {
            _pos++;
            return *this;
        }
        bool operator!=(const iterator &rhs) const {
            return this->_pos != rhs._pos;
        }
        // *it
        char &operator*() {
            return *_pos;
        }

       private:
        char *_pos;
    };
    // ��ȡ��Ԫ�ص�����
    iterator begin() {
        return iterator(_data);
    }
    // β��������������һ��Ԫ�غ����Ǹ�λ��
    iterator end() {
        return iterator(_data + this->size());
    }

   private:
    char *_data;
};
ostream &operator<<(ostream &out, const china::string &s);
// ���������ַ�������
void swap(china::string &s1, china::string &s2);
}  // namespace china

void print_string(const china::string &s) {
    for (int i = 0; i < s.size(); i++) {
        cout << s[i] << " ";
    }
    cout << endl;
}

int main() {
    china::string s1 = "hello iterator";
    for (china::string::iterator it = s1.begin(); it != s1.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    auto it = s1.begin();
    *it = 'A';  // ͨ���������޸���ָ���Ԫ��
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        char c = *it;
        cout << *it << " ";
    }
    cout << endl;

    // C++11�ṩ��һ���µ�forѭ�������������ۺ϶��� ��Χforѭ��
    for (auto c : s1) {
        cout << c << " ";
    }
    cout << endl;
}

void china::swap(china::string &s1, china::string &s2) {
    china::string tmp = std::move(s1);
    s1 = std::move(s2);
    s2 = std::move(tmp);
}

ostream &china::operator<<(ostream &out, const china::string &s) {
    out << s._data;
    return out;
}

size_t china::string::size() const {
    return strlen(this->_data);
}

char &china::string::operator[](int index) {
    return _data[index];
}

char china::string::operator[](int index) const {
    return _data[index];
}

// ������ֵ
china::string &china::string::operator=(const string &rhs) {
    cout << "copy assignment!" << endl;
    // ��ֹ�Ը�ֵ
    if (this == &rhs)
        return *this;
    // �ͷ�������ԭ�еĲ����ʵĿռ�
    delete[] _data;
    // ����ռ䣬��С���Ҳ����Ŀռ�һ����
    _data = new char[strlen(rhs._data) + 1];
    // ���Ҳ����ռ��е��ַ����������Լ����¿ռ���
    strcpy(_data, rhs._data);
    // ����������
    return *this;
}
// �ƶ���ֵ
china::string &china::string::operator=(string &&rhs) {
    cout << "move assignment!" << endl;
    // ��ֹ�Ը�ֵ
    if (this == &rhs)
        return *this;

    delete[] _data;

    _data = rhs._data;
    rhs._data = nullptr;

    // ����������
    return *this;
}

china::string::string(const char *s) {
    if (s == NULL) {
        _data = new char[1];
        _data[0] = '\0';
    } else {
        int len = strlen(s) + 1;
        _data = new char[len];
        strcpy(_data, s);
    }
}

// ��������
china::string::string(const string &rhs) {
    cout << "copy constructor!" << endl;
    int len = strlen(rhs._data) + 1;
    _data = new char[len];
    strcpy(_data, rhs._data);
}
// �ƶ�����
china::string::string(string &&rhs)
    : _data(rhs._data) {
    rhs._data = nullptr;
    cout << "move constructor!" << endl;
}

china::string::~string() {
    delete[] _data;
    _data = nullptr;
}