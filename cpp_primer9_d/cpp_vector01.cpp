#include <iostream>
#include <string>
#include <vector>

using namespace std;
using std::string;
using std::cout;
using std::endl;
using std::vector;



int main(int argc, char const *argv[])
{
    //模版形式创建vector
    vector<int> vec1 = {1,2,3,4,5};
    vector<string> vec2 = {"1","2","3"};
    vector<string> vec3{"1","2","3"};

    /**
     * 遍历vector
    */
    for(int i : vec1) {
        cout << i << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    for(string i : vec2) {
        cout << i << endl;
    }
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    for (size_t i = 0; i < vec1.size(); i++)
    {
       cout << vec1[i] << endl;
    }
    /**
     * 判断是否为空 0为false不空 1为true 空
    */
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << vec1.empty() << endl;

    /**
     * 填充vector的元素 push_back
    */
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    vector<int> vec4;
    for (size_t i = 0; i < 10; i++)
    {
        vec4.push_back(i);
    }
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << vec4.size() << endl;
    for(int i : vec4) {
        cout << i ;
    }
    cout << "" << endl;

    /**
     * 填充vector的元素 emplace_back
    */
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    vector<int> vec5;
    for (size_t i = 9; i < 10; i--)
    {
        vec5.emplace_back(i);
    }
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    cout << vec5.size() << endl;
    for(int i : vec5) {
        cout << i ;
    }
    cout << "" << endl;

    /**
     * 在C++中，std::vector容器提供了push_back和emplace_back两个成员函数来在容器的末尾添加元素，但它们之间存在一些关键差异：

        push_back：

        当使用push_back向vector添加元素时，首先会在堆上创建该元素的一个副本（如果传入的是右值，则可能会移动元素），然后将这个副本（或移动的元素）添加到vector的末尾。
        如果传入的是一个已有对象，这个对象会先被复制或移动（C++11及以后，若对象可移动则使用移动构造），这个过程可能会涉及临时对象的创建和析构，从而影响性能。
        使用场景：当你有一个已经存在的对象，想要将其添加到vector中时。
        
        emplace_back：

        emplace_back则是直接在vector内部构造新元素，它接受构造元素所需的参数，然后使用这些参数在vector的末尾就地构造新元素，从而避免了复制或移动构造临时对象的开销。
        这意味着，与push_back相比，emplace_back可以减少一次拷贝或移动操作，提高效率，特别是在处理大型或复杂对象时更为显著。
        使用场景：当你希望直接根据参数创建新对象并插入到vector末尾，特别是当构造对象的成本较高时。
    */
    std::vector<std::string> vec;

    // 使用push_back
    std::string str = "Hello";
    vec.push_back(str);  // 先构造str，再复制str到vector中

    // 使用emplace_back
    vec.emplace_back("World");  // 直接在vector内部构造一个"World"的string对象

    /**
     * 总结来说，emplace_back在性能上通常优于push_back，特别是在涉及到大量元素插入或元素类型构造成本较高时，
     * 因为它减少了潜在的拷贝和移动操作。不过，选择哪个取决于具体需求，如果已经有了一个对象实例需要放入容器，
     * 那么push_back是自然的选择；如果想要根据参数直接构造新对象并插入，emplace_back则更加高效。
    */

    /**
     * 比较两个vector是否相同,相同返回1 true，不同返回0 false
    */
    cout << "~~~~~~~~~~~~~~~~~~~" << endl;
    vector<int> vec11 = {1, 2, 3};
    vector<int> vec12 = {1, 2, 3};
    // 打印比较结果
    cout << (vec11 == vec12) << endl;
    
    return 0;
}
