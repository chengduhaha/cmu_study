#include <iostream>
#include <string>
#include <vector>
#include <set> // 添加这行来包含set容器的头文件
#include <map> // 添加这行来包含map容器的头文件

using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::vector;
using std::set;
using std::map;


/**
 * iterators 迭代器
 * 
 * set map 与vector不同无法获取到索引，因为它们的内存空间不是连续的，可能它们的元素分配在不同的元素空间中，
 * 迭代器就是一种抽象，来对集合进行遍历
 * 
 * begin -> 集合的第一个元素
 * end ->   集合的最后一个元素+1
 * ++it -> 遍历集合下一位元素
*/
int main(int argc, char const *argv[])
{
    // vector
    cout << "使用迭代器遍历vector" << endl;
    vector<string> vector1 = {"hello", "world"};
    for(auto it = vector1.begin(); it != vector1.end(); ++it) {
        cout << *it << endl;
    }
    for(vector<string>::iterator it = vector1.begin(); it != vector1.end(); ++it) {
        cout << *it << endl;
        cout << (*it).size() << endl;
        cout << it->size() << endl;
    }

    //set 
    cout << "使用迭代器遍历set" << endl;
    set<int> set1 = {1,2,3,4,5};
    for(auto it = set1.begin(); it != set1.end(); ++it) {
        cout << *it << endl;
    }
    for(set<int>::iterator it = set1.begin(); it != set1.end(); ++it) {
        cout << *it << endl;
    }

    

    //map
    cout << "使用迭代器遍历map" << endl;
    map<string, int> map1;
    map1["aa"] = 11;
    map1["bb"] = 22;
    map1["cc"] = 33;
    for(auto it = map1.begin(); it != map1.end(); ++it) {
        cout << "key : " << it->first << " value : " << it->second << endl;
    }
    for(map<string, int>::iterator it = map1.begin(); it != map1.end(); ++it) {
        cout << "key : " << it->first << " value : " << it->second << endl;
    }



    return 0;
}
