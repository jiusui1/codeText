#include <iostream>
#include <string>
#include <vector>
using namespace std;
class B {
   public:
    virtual void Fun() {
        cout << "" << endl;
    }
};
class D : public B {
   public:
    void Fun() {
        cout << "hello" << endl;
        cout << "ÄãºÃ" << endl;
    }
};

int main() {
    D dd;

    B *pb = &dd;
    D *pd = &dd;
    pb->Fun();
    pd->Fun();
    // cout << "hwllo" << endl;  // D
    // system("pause");
    return 0;
}