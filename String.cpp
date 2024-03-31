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

    // 移动构造
    string(string &&rhs);
    // 移动赋值
    string &operator=(string &&rhs);

    size_t size() const;
    // 这两个[]运算符函数是重载关系
    char &operator[](int index);
    char operator[](int index) const;

    // 增加迭代器类型
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
    // 获取首元素迭代器
    iterator begin() {
        return iterator(_data);
    }
    // 尾后迭代器，即最后一个元素后面那个位置
    iterator end() {
        return iterator(_data + this->size());
    }

   private:
    char *_data;
};
ostream &operator<<(ostream &out, const china::string &s);
// 交换两个字符串对象
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
    *it = 'A';  // 通过迭代器修改它指向的元素
    for (auto it = s1.begin(); it != s1.end(); ++it) {
        char c = *it;
        cout << *it << " ";
    }
    cout << endl;

    // C++11提供了一种新的for循环，用来遍历聚合对象： 范围for循环
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

// 拷贝赋值
china::string &china::string::operator=(const string &rhs) {
    cout << "copy assignment!" << endl;
    // 防止自赋值
    if (this == &rhs)
        return *this;
    // 释放左侧对象原有的不合适的空间
    delete[] _data;
    // 分配空间，大小与右侧对象的空间一样大
    _data = new char[strlen(rhs._data) + 1];
    // 把右侧对象空间中的字符串拷贝到自己的新空间中
    strcpy(_data, rhs._data);
    // 返回自引用
    return *this;
}
// 移动赋值
china::string &china::string::operator=(string &&rhs) {
    cout << "move assignment!" << endl;
    // 防止自赋值
    if (this == &rhs)
        return *this;

    delete[] _data;

    _data = rhs._data;
    rhs._data = nullptr;

    // 返回自引用
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

// 拷贝构造
china::string::string(const string &rhs) {
    cout << "copy constructor!" << endl;
    int len = strlen(rhs._data) + 1;
    _data = new char[len];
    strcpy(_data, rhs._data);
}
// 移动构造
china::string::string(string &&rhs)
    : _data(rhs._data) {
    rhs._data = nullptr;
    cout << "move constructor!" << endl;
}

china::string::~string() {
    delete[] _data;
    _data = nullptr;
}