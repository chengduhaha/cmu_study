
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
 * 重载输入流输出流
*/

class A {
    friend ostream& operator<<(ostream&, const A&);
 public:
    int a_;
    A(int a) : a_(a) {
        cout << "constructor A" << endl;
    };

    A& operator+(/*this*/ const A& a) {
        cout << "operator+ A" << endl;
        this->a_ += a.a_;
        return *this;
    }
};
//重载输出流
ostream& operator<<(ostream& os, const A& a){
    cout << "operator <<" << endl;  
    os << a.a_ << endl;
    return os;
}


int main(int argc, char const *argv[])
{

    A a(100);
    //cout << os << a.a_ << endl << endl
    cout << a << endl;
    return 0;
   
} 
