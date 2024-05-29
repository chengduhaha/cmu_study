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

/**
 * 通用算法
 * 比较器
 * 排序
 * 查找
 * 其他的可以自己搜
*/

//自定义比较器
bool want_greater(const int& i1,const int& i2) {
    return i1 > i2;
}

void comparator1() {
    //默认排序 从小到大
    cout << "=========排序 从小到大============" << endl;
    vector<int> v1 = {1,3,4,0,100,2,-1};
    std::sort(v1.begin(), v1.end());
    for(int e: v1) {
        cout << e << " ";
    }
    cout << "\n" << endl;
    
    //排序 从大到小 添加greater比较器
    cout << "=======排序 从大到小===添加greater比较器===========" << endl;
    vector<int> v2 = {1,3,4,0,100,2,-1};
    std::sort(v2.begin(), v2.end(), std::greater<int>());
    for(int e: v2) {
        cout << e << " ";
    }
    cout << "\n" << endl;

    //排序 从小到大 添加less比较器
    cout << "=======排序 从小到大===添加less比较器===========" << endl;
    vector<int> v3 = {1,3,4,0,100,2,-1};
    std::sort(v3.begin(), v3.end(), std::less<int>());
    for(int e: v3) {
        cout << e << " ";
    }
    cout << "\n" << endl;

    //排序 从小到大 添加自定义want_greator比较器
    cout << "=======排序 从小到大===添加自定义want_greator比较器===========" << endl;
    vector<int> v4 = {1,3,4,0,100,2,-1};
    std::sort(v4.begin(), v4.end(), want_greater);
    for(int e: v4) {
        cout << e << " ";
    }
    cout << "\n" << endl;

    //find查找
    cout << "=======find查找===========" << endl;
    vector<int> v5 = {1,3,4,0,100,2,-1};
    vector<int>::iterator res = std::find(v5.begin(), v5.end(), 100);
    if(res == v5.end()) {
        cout << "cannot find " << endl;
    }else {
        cout << "find " << endl;
    }

    



}

int main(int argc, char const *argv[])
{
    comparator1();
    return 0;
}
