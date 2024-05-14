#include <iostream>
#include <string>
using namespace std;

/**
 * namespace 避免变量/函数命名的冲突，通过不同命名空间的相同变量名来进行区分
*/

namespace ns02 {
    void function1() {
        std::cout << "ns02" << std::endl;
    }
}

int main(int argc, char const *argv[]) {
   
}

