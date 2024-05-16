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
 * express 表达式 : 包含一个或多个操作符进行计算并获取到结果
 * 重载运算符
*/

class Complex {
public:
    double real, imag;
    //构造函数 参数有默认值
    Complex(double r = 0.0, double i = 0.0) : real(r), imag(i) {}
    // 重载加法运算符 Complex& 为 other的引用，而不是一个独立的副本。这样可以避免为运算创建对象的临时副本，从而节省内存和提高效率。
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

};


class Vector {
private:
    int size;
    int* data; //一个指向整数数组的指针，实现一个可以动态调整大小的整数数组，，提供存储和访问一系列整数的能力，这是基本数据类型int无法实现的。
public:
    Vector(int s) : size(s) {
        data = new int[s]; //通过使用new[]操作符，你可以在类构造函数中根据给定的大小s动态地分配一个整数数组给data
    }
    /**
     * ~Vector() 是 Vector 类的析构函数
     * 析构函数是一种特殊的成员函数，其名称以波浪线 ~ 开头，
     * 用于在对象生命周期结束时自动释放对象所占用的资源。当一个对象超出其作用域或者被显式删除（例如，通过删除动态分配的对象）时，析构函数会被自动调用。
    */
    ~Vector() { 
        /**
         * delete[] data 用于释放之前通过 new[] 分配的动态数组的内存。
         * 删除数组本身所占用的内存空间，这块内存被返回给操作系统，使其可以重新分配给其他程序或后续的内存请求。
         * 使用 delete[] 而不是 delete 是非常重要的，特别是在处理数组时。这是因为 delete 仅用于释放单个对象的内存，
         * 而 delete[] 专门用于处理数组，能够正确地遍历并析构数组中的每个元素（如果适用），然后释放整个数组块的内存。
        */
        delete[] data;
    }
    // 重载下标运算符
    /**
     * operator[] 方法返回类型是 int&，
     * 这意味着它返回的是数组中对应元素的引用，允许用户直接修改该数组元素的值。
     * 如果返回类型是 int，则只会返回一个整数值的拷贝，对返回值的修改不会影响原数组。
    */
    int& operator[](int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Index out of range");
        }
        /**
         * 在表达式 data[index] 中，data 是一个指向整数数组的指针，
         * 而 data[index] 实际上不是一个指针，而是一个整数值。
         * 当你使用数组下标运算符 [] 访问指针所指向的数组元素时，
         * 它会解引用指针并偏移 index 个元素的位置，然后返回那个位置上的元素值。
        */
        return data[index];
    }
};

class Box {
public:
    int length;
    int width;
    Box(int length, int width) : length(length), width(width) {}

    Box operator+(const Box& other) {
        this->length = this->length + other.length;
        this->width = this->width + other.width;
        return *this;
        /**
         * return *this; 和 return this; 在语义上有本质的区别，尤其是在涉及类成员函数和操作符重载的上下文中。
         * return *this;：这里，星号(*)用于解引用，意味着返回的是当前对象的实例（即调用该成员函数的对象本身）。
         * 当你在类的成员函数内部这样返回时，你实际上是返回了一个对象的拷贝（或者如果是按引用返回，则是对象的引用）。
         * 在操作符重载的情境下，这种做法常见于实现链式调用或构建流式接口，因为它允许连续调用操作符。例如，你的Box类如果支持链式赋值或类似操作，这样的返回就非常有用。
         * 
         * return this;：如果直接返回this，你实际上返回的是一个指向当前对象的指针。这在某些情境下是有用的，
         * 比如工厂模式或需要返回对象的指针给其他部分的代码处理。但在你的场景中，operator+期望返回一个Box对象（而不是指向Box的指针），
         * 所以返回this会导致类型不匹配，违反了操作符重载函数的声明。
         * 
         * 总结来说，return *this;适合于你的场景，因为它正确地返回了一个Box类型的对象，符合你的成员函数Box operator+(const Box& other)的返回类型声明。
         * 而return this;则不适用于此情况，除非你的函数声明为返回Box*或Box&，且有合理的理由需要返回对象指针或引用。
         * 
        */
    }
};


int main(int argc, char const *argv[])
{
    /**
     * 重载运算符号 Overloaded operators
     * 运算符重载允许程序员为自定义类型（如类或结构体）提供特定的运算符行为。这意味着，你可以改变或增强运算符对于特定类型的操作方式
    */
    //1. 重载加法运算符 (+)
    Complex c1(1,2);
    Complex c2(3,4);
    Complex c3 = c1 + c2;
    std::cout << "Sum: " << c3.real << " + " << c3.imag << "i" << std::endl;
   
    //2. 重载下标运算符 []
    // 我们可以为一个类重载[]运算符，使其像数组一样访问元素。下面是一个简单的Vector类示例，模拟动态数组。
    cout << "重载下标运算符 []" << endl;
    Vector v1(5);
    for(int i=0; i < 5; i++) {
        // cout << i << endl;
        // cout << "~~~~~~~~~~~~~~~" << endl;
        v1[i] = i * 100;
        cout << v1[i] << endl;
    }

    //Box
    Box b1(1,2);
    Box b2(3,4);
    Box b3 = b1+b2;
    cout << b3.length << " : "<< b3.width << endl;

    return 0;

}
