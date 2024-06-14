
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
 * 参数模板
*/
//以自定义比较器为例

template <typename T, typename F = std::less<T>> //可以设置默认的函数
/**
 * F f = F()是一种函数参数的默认值设定方式
 * F 是一个模板参数，代表一个类型，它可以是一个函数对象类型
 * （例如，由std::less<T>给出的比较函数对象类型）或者是任何具有可调用且符合该上下文要求的类型
 * 
 * F() 是对类型F的默认构造调用。也就是说，如果在调用comparator_bigger函数时没有为f参数提供具体的函数对象，
 * 那么就会自动使用F类型的默认构造函数来创建一个默认的函数对象。对于像std::less<T>这样的类型，
 * 它有一个默认构造函数，会创建一个用于比较T类型对象、满足小于关系的函数对象。
 * 
 * F f = F()整体表示：函数comparator_bigger的第三个参数f默认是一个类型为F的对象，通过类型F的默认构造函数初始化。
 * 这使得在不特别指定比较函数时，会默认使用std::less<T>来比较T类型的对象，决定它们之间的大小关系。
 * 用户也可以传入自定义的比较函数对象来覆盖这个默认行为。
*/
int comparator_bigger(const T& l, const T& r, F f = F()) {
    if(f(l,r)) {
        return -1;
    }
    if(f(r,l)) {
        return 1;
    }
    return 0;
}

template <typename T>
bool my_bigger(const T& l, const T& r) {
    return l < r;
}

// 泛型类型也可以设置默认值
template <typename T = int>
class A {
 public:
    T a_;
    A(T a) : a_(a) {};

    void f() {
        cout << a_ << endl;
    }
    
};

int main(int argc, char const *argv[])
{   
    vector<int> v1 = {1,3,0};
    std::sort(v1.begin(), v1.end());
    for(int e: v1) {
        cout << e << " , ";
    }
    cout << "~~~~~~~" << endl;
    std::sort(v1.begin(), v1.end(), std::greater<int>());
    for(int e: v1) {
        cout << e << " , ";
    }

    cout << "~~~~~~~" << endl;
    cout << comparator_bigger<int>(1,2) << endl;
    cout << comparator_bigger<int>(4,1) << endl;
    cout << comparator_bigger<int>(1,1) << endl;
    cout << comparator_bigger<int>(1,1, my_bigger<int>) << endl;
    cout << comparator_bigger<int>(100,1, my_bigger<int>) << endl;

    cout << "~~~~~~~" << endl;
    A<> a1(1); // 泛型类型有默认值，就可以不用指定具体类型 直接使用<>
    a1.f();
    A<double> a2(1.1);
    a2.f();

    return 0;
} 
