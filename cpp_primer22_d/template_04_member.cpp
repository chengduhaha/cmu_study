
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
 * member template 成员模板
*/

template <typename T>
class DeleteObject{
public:
    //重载括号操作符()
    void operator()(T* object) {
        cout << "delete object : " << object << endl;
        delete object;
    }
};


class DeleteObject_MemberTemp{
public:
    template <typename T>
    //重载括号操作符()
    void operator()(T* object) {
        cout << "member template delete object : " << object << endl;
        delete object;
    }
};


int main(int argc, char const *argv[])
{   
    string* a1 = new string("asdfw");
    cout << a1 << endl;
    cout << *(a1) << endl;
    DeleteObject<string> d1;
    d1(a1);
    

    cout << "~~~~~~~~~" << endl;

    int* a2 = new int(100);
    cout << a2 << endl;
    cout << *(a2) << endl;
    DeleteObject<int> d2;
    d2(a2); 

    cout << "~~~~~~~~~" << endl;

    string* m1 = new string("asdfw111");
    DeleteObject_MemberTemp mt1;
    mt1(m1);

    int* m2 = new int(192);
    mt1(m2);

    return 0;
} 
