#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 抛异常表达式
*/

void function() {
    throw std::invalid_argument("require 100 arguments");
}

int main(int argc, char const *argv[])
{
    // cout << 123 << endl;
    // function();
    // cout << 456 << endl;


    cout << 123 << endl;
    try {
        function();
    } catch(const std::invalid_argument e) {
        cout << "catch the err:  " << e.what() << endl;
        // cout << e.what() << endl;
    }
    cout << 456 << endl;

    return 0;
}
