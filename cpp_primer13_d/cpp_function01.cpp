#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数基础
*/

void function0() {
    int i = 0;
    cout << "i == " << ++i << endl; 
    /**
     * 结果：
     *  i == 1
        i == 1
        i == 1
        i == 1
        i == 1
        i == 1
        i == 1
        i == 1
        i == 1
        i == 1
    */
}

//static 只在函数运行第一次时执行，之后调用函数就不再执行，直到main程序结束后才销毁
void function() {
    static int i = 0;
    cout << "i == " << ++i << endl; 
    /**
     * 结果：
     *  i == 1
        i == 2
        i == 3
        i == 4
        i == 5
        i == 6
        i == 7
        i == 8
        i == 9
        i == 10
    */
}

int main(int argc, char const *argv[])
{
    int count = 10;
    for (size_t i = 0; i < count; i++)
    {
        function0();
    }
    cout << "======================" << endl;
    for (size_t i = 0; i < count; i++)
    {
        function();
    }
    
    return 0;
}


