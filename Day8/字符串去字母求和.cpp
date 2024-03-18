#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
    string str1;
    string str2;
    cin >> str1;
    int sum = 0;
    for (int i = 0; i < str1.size(); i++) {
        if (str1[i] >= '0' && str1[i] <= '9') {
            str2.push_back(str1[i]);
        } else {
            sum += atoi(str2.c_str());
            str2 = "";
        }
    }
    // 处理最后一个数字
    sum += atoi(str2.c_str());
    cout << sum << endl;

    return 0;
}
