#include <algorithm>  // ?? std::max_element ??
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {3, 1, 4, 1, 5, 9, 2, 6};

    // ?? std::max_element ?????
    auto max_element_iterator = std::max_element(numbers.begin(), numbers.end());

    if (max_element_iterator != numbers.end()) {
        std::cout << "Max element is: " << *max_element_iterator << std::endl;
    } else {
        std::cout << "Vector is empty." << std::endl;
    }

    return 0;
}
