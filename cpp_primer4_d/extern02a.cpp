/**
 * reference引用； bind to a local variable
 *                 can not bind literal and const
 * 
*/
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char const *argv[])
{
    int local_price = 12;
    
    // replace_price 为 local_price 的引用，没有真是的内存地址
    int &replace_price = local_price;

    std::cout << "replace_price 地址： "  <<  &replace_price << std::endl;
    std::cout << "local_price 地址： " <<  &local_price << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~" << std::endl;

    

    for (int i = 0; i < 10; i++)
    {
        local_price = i;
        std::cout << replace_price << std::endl;
    }

    /**改变引用的值 也会改变被引用的变量的值 */
    std::cout << "The value of local_price is: " << local_price << std::endl;
    replace_price = 0;
    std::cout << "The value of local_price is: " << local_price << std::endl;
    std::cout << "The value of replace_price is: " << replace_price << std::endl;


    /**
     * string& cc = aa;：这一行声明了一个std::string的引用变量cc，并让它引用aa。引用可以被视为某个变量的别名，
     * 因此cc和aa现在都指向同一个字符串对象（即内容为hello的字符串）。
     * 对cc所做的任何修改都会直接影响到aa，反之亦然，因为它们实际上是同一个对象的不同名称。
    */
    string aa  = "hello";
    // string& bb = "hello";
    string& cc = aa;
    
    std::cout << "The value of aa is: " << aa << std::endl;
    std::cout << "The value of cc is: " << cc << std::endl;

    // int& ddd = 12;
    /**
     * 这段代码会导致编译错误。你试图声明一个整型引用ddd，并使其引用一个立即数12。
     * 在C++中，引用必须被初始化为一个已存在的变量的地址，而不能直接绑定到字面值或临时对象上。
     * 这是因为引用的本质是一个别名，它需要指向一块实际存在的内存，
     * 而字面值如12并不对应于内存中的一个可寻址位置。正确的做法是首先将字面值赋给一个变量，然后声明引用指向那个变量，如下所示：
     * int temp = 12; // 创建一个实际的int变量
     * int& ddd = temp; // 现在ddd是一个引用，引用temp
    */
   int temp = 11;
   int& dd = temp;
   std::cout << "The value of dd is: " << dd << std::endl;


    const int& ddd = 12;
    /**
     * 代码就是合法的。这里，你声明了一个指向常量整数的引用 ddd，并将其绑定到字面值 12 上。
     * 在C++中，允许将引用绑定到字面值或临时对象上，只要引用是 const 且指向 const 的类型，
     * 因为这样做不会改变字面值或临时对象的内容。
    */
    std::cout << "The value of ddd is: " << ddd << std::endl;

    return 0; 
}
