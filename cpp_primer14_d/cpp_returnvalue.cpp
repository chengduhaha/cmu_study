#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数的返回值
*/

int* function() {
    int a = 10;
    int* p = &a;
    cout << p << endl;
    return p;
}

int main(int argc, char const *argv[])
{
    int* p = function();
    cout << *p << endl;
    cout << p << endl;
    return 0;
}
