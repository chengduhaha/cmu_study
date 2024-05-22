#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数的默认参数值
*/

void function(int a=10, double b=2.0, char c='h') {
    cout << a << "," << b << "," << c << endl;
}

int main(int argc, char const *argv[])
{
    function();
    function(12);
    function(12, 2.123);
    function(12, 2.123, 'L');

    // function(, 2.123, 'L'); error: expected primary-expression before ‘,’ token
    
    return 0;
}
