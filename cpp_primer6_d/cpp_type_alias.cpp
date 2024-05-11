#include <iostream>
#include <string>
using namespace std;

int function1() {
    return 123;    
}

int main(int argc, char const *argv[]) {
    /**
     * 1. using 可以在文件开头使用using namespace std; 
     *      来简化代码不需要每次打印都是用std::cout << 1 << std::endl;
     *      可以使用简化后的 cout << a << endl;
    */
   int a = 1;
   std::cout << a << std::endl;
   cout << a << endl;
   
   /**
    * 2. auto 编译器自动推断类型，在简单明显的看出来类型的地方可以使用，如果人为看不出来类型，尽量不使用
   */
    // auto x =  function1()
    // cout << x << endl;
    // auto i2 = 0 + 1;
    
    

    /**
     * 3. decltype 自动替换类型
    */
//    int d = 6;
//    decltype(d) e = 123;
//    cout << d << endl;

}

