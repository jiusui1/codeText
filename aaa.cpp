#include <iostream>
#include <vector>
std::vector<int> plusOne(std::vector<int> &digits) {
    int n = digits.size();
    for (int i = n - 1; i >= 0; --i) {
        if (digits[i] < 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    // �������λ����9������Ҫ���������ǰ�����һ��1
    digits.insert(digits.begin(), 1);
    return digits;
}

int main(int argc, char const *argv[]) {
    std::vector<int> vec{1, 3, 5, 7, 9, 9};
    std::vector<int> ret = plusOne(vec);
    for (int i : ret) {
        std::cout << i << std::endl;
    }
    return 0;
}