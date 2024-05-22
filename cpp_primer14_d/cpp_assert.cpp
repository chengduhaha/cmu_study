#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include <cassert> // 确保包含这个头文件以使用assert

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * assert: 在测试和debug中使用。用来验证对预期结果的判断，如何预期结果则通过继续向后执行代码，如果不符合则报错
*/
void function(int a) {
    assert(a==100);
}

int main(int argc, char const *argv[])
{
    function(100);
    cout << "ok" << endl;
    function(99);
    cout << "ok" << endl;
}
