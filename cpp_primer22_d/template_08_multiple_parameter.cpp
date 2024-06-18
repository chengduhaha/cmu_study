
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

#include <set> // 添加这行来包含set容器的头文件
#include <map> // 添加这行来包含map容器的头文件
#include <unordered_map> // 添加这行来包含map容器的头文件

//sleep
#include <chrono>
#include <thread>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::set;
using std::map;
using std::unordered_map;

/**
 * 可变长参数模板
 * 
 * 
*/
template <typename T>
ostream& print1(ostream& os, const T& t) {
    os << t << endl;
    return os;
}

//chain 
/**
 * 直接使用标准的C++ for循环来遍历变长模板参数包（如Args... args）是不可能的，
 * 因为编译时期参数包的具体内容是未知的，无法直接迭代
*/
template <typename T, typename... Args>
ostream& print1(ostream& os, const T& t, Args... args) {
    os << t << " ";
    print1(os, args...);
    return os;
}

int main(int argc, char const *argv[])
{   
    print1(cout, 1,2,"ss");


    return 0;
} 
