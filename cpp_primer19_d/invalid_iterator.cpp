#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include <fstream>
#include <sstream>

#include <vector>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;

/**
 * 不可以在iterator中改变原容器 会导致原容器失效。
 * vector在内存中一段连续的内存空间，扩容时也按照原vector的空间成倍数扩容, 
 * 实际上扩容是2^n (n=capacity),复杂度是O(1)
 * 
 * Vector的capacity和size不同，capacity是vector一共申请到的内存容量大小，size是实际存储数据的大小
*/
int main(int argc, char const *argv[])
{
    vector<int> v1 = {1,2,3,4,5};
    for(auto it=v1.begin(); it!=v1.end(); ++it) {
        cout << *it << endl;
        if((*it) == 4) {
            v1.push_back(100);
        }
        cout << "capacity : " << v1.capacity() << endl;
    }


    /**
     * capacity , size
    */
    cout << "capacity & size" << endl;
    vector<int> v2 = {1,2,3,4,5};
    v2.reserve(10);
    cout << v2.capacity() << endl;
    cout << v2.size() << endl;

    //vector扩容 2^n
    cout << "vector扩容 2^n" << endl;
    vector<int> v3;
    int pre_capacity = 0;
    for(int i=0; i<10000; i++) {
        if(pre_capacity != v3.capacity()) {
            cout << "capacity changed to => " << v3.capacity() << endl;
            pre_capacity = v3.capacity();
        }
        v3.push_back(i);
    }





    return 0;
}
