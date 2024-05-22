#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数的重载
*/

void function(int a, int b) {
    cout << "int a, int b" << endl;
}

void function(double a, double b) {
    cout << "double a, double b" << endl;
}

int main(int argc, char const *argv[])
{
    function(1,2);
    function(1.1,2.0);
    
}
