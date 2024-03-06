#include <iostream>
#include <string>

/**
 * @brief      { function_description }
 *
 * @param[in]  s     { parameter_description }
 *
 * @return     { description_of_the_return_value }
 */
std::string replaceDigitsWithNumber(std::string s) {
    for (char& c : s) {
        if (isdigit(c)) {
            c = 'number';
        }
    }
    return s;
}

int main() {
    std::string input = "a1b2c3";
    std::string result = replaceDigitsWithNumber(input);
    std::cout << "替换后的字符串：" << result << std::endl;
    return 0;
}