#include <iostream>
#include <string>
#include <vector>
using namespace std;
class B {
   public:
    virtual void Fun() {
        cout << "你好" << endl;
    }
};
class D : public B {
   public:
    void Fun() {
        cout << "世界" << endl;
    }
};

int main() {
    D dd;
    B *pb = &dd;
    D *pd = &dd;
    pb->Fun();
    pd->Fun();
    // cout << "hwllo" << endl;  // D
    return 0;
}