
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
 * 容器继承
*/
class Base {
 public:
    int a_ = 100;

};

class Deriver: public Base {
 public:
    int b_ = 200;
};


int main(int argc, char const *argv[])
{
    vector<Base> v1;
    Deriver d1;
    v1.push_back(Base());
    v1.push_back(d1);
    Base b2 = Deriver();
    v1.push_back(b2);
    cout << v1[0].a_ << endl;
    cout << v1[1].a_ << endl;
    // cout << v1[1].b_ << endl; 会报错，因为vector定义的类型是Base，会砍掉子类Derviver类是独有属性
    cout << v1[2].a_ << endl;

    /**在容器中使用指针类型可以转换类型访问子类属性*/
    vector<Base*> v2;
    Deriver dd;
    v2.push_back(&dd);
    cout << v2[0]->a_ << endl;

    cout << v2[0] << endl;
    cout << &dd << endl;
    cout << (Deriver*)v2[0] << endl;

    //类型转换拿到子类指针 获取子类属性
    Deriver* ddd = (Deriver*)v2[0];
    cout << ddd->b_ << endl;
    cout << &ddd << endl;
    // cout << (Deriver*)(v2[0])->b_ << endl; 会报错，没有拿到子类指针的对象

    return 0;
   
} 
