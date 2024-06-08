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
 * 自定义map的比较器，用来比较自定义类的key的大小比较和hash
*/
class A {
 public:
    int a_;
    A(int a):a_(a) {};
};

bool wanaBigger(const A& a1, const A& a2) {
    return a1.a_ > a2.a_;
}

void func() {
    map<A, int, decltype(wanaBigger)*> map1(wanaBigger);

    map1.insert({A(1), 1});
    map1.insert({A(2), 2});
    map1.insert({A(3), 3});
    map1.insert({A(4), 4});

    for(auto it=map1.begin(); it!=map1.end(); it++) {
        cout << it->second << endl;

    }


    // unordered_map<A, int, decltype(wanaBigger)*> map2(wanaBigger);

    // map2.insert({A(1), 1});
    // map2.insert({A(2), 2});
    // map2.insert({A(3), 3});
    // map2.insert({A(4), 4});

    //  for(auto it=map2.begin(); it!=map2.end(); it++) {
    //     cout << it->second << endl;

    // }
  
}
 
void func2() {
    map<int, int> m1;
    for (int i = 0; i < 10; i++)
    {
        if (m1.count(i) == 0)
        {
            cout << "hello" << endl;
        }
        
    }
    cout << m1.size() << endl;

}

/**
 * lower bound(key) 返回不小于key的pair
 * upper bound(key) 返回大于key的pair
 */
void func3() {
    map<int, int> m1;
    for (int i = 0; i < 10; i++)
    {
        m1.insert({i,i});
    }
     for(auto it=m1.begin(); it!=m1.end(); it++) {
        cout << it->first << " : " << it->second << endl;

    }


    auto it1 = m1.lower_bound(5);
    auto it2 = m1.upper_bound(5);
    for(auto it=it1; ; it++) {
         if (it == it2)
        {
            break;
        }
        cout << it->first << " : " << it->second << endl;
        
    }

    for(auto it=it2; ; it++) {
         if (it == it2)
    
        cout << it->first << " : " << it->second << endl;
        
    }

}

int main(int argc, char const *argv[])
{
    func();
    func2();
    func3();
} 
