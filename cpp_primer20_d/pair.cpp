#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;

/**
 * pair <key,value>
*/
void func() {
    pair<int,int> p1 = {1,3};
    cout << p1.first <<  " : "  << p1.second << endl;

    pair<int, pair<int,int>> p2 = {1,{2,3}};
    cout << p2.first <<  " : "  << p2.second.first << " = " << p2.second.second << endl;
}

int main(int argc, char const *argv[])
{
    func();
}
