#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数的返回引用 
*/
class Cache {
 private:
    int number_;
 public:
    Cache(int number) : number_(number) {};
    
    //返回值是Cache& return *this 返回的是对象本身 
    Cache& plus(int plus) {
        this->number_ += plus;
        return *this;
    }

    Cache& subtract(int subtraction) {
        this->number_ -= subtraction;
        return *this;
    }

    //返回的对象的拷贝 不是对象本身
    Cache multiply(int multiply) {
        this->number_ *= multiply;
        return *this;
    }

    int getNumber() {
        return this->number_;
    }
};

int main(int argc, char const *argv[])
{
    Cache c1 = Cache(100);
    c1.plus(100).subtract(20);
    cout << c1.getNumber() << endl;

    Cache c2 = Cache(100);
    /**
     * 由于multiply方法返回的是Cache的副本，所以是一个tmp临时类实例的修改，本不是c2本身。
     * Cache tmp = c2.multiply(2); 此时修改了c2本身的number值，但是返回一个临时的tmp实例
     * tmp = tmp.plus(1);
    */
    Cache c3 = c2.multiply(2).plus(1);
    cout << c3.getNumber() << endl; //结果是 201 = 100 * 2 + 1
    cout << c2.getNumber() << endl;//结果是 200 不是预期的 100 * 2 + 1, 
    return 0;
}
