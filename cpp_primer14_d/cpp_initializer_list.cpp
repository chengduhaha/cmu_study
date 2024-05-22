#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 可变长度参数
*/

void function(std::initializer_list<int> initializer_list) {
    for(int em : initializer_list) {
        cout << em << endl;
    }
    
}

int main(int argc, char const *argv[])
{
    function({1,2,3,4});
    
    return 0;
}
