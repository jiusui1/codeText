#include <algorithm>  // ?? std::max_element ??
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
    vector<string> s;
    s.push_back("hello");
    s.push_back("world");
    s.push_back("abcde");

    for (string i : s) {
        cout << i << endl;
    }
}
