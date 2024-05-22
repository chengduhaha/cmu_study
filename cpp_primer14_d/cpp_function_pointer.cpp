#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include <cassert> // 确保包含这个头文件以使用assert

using namespace std;
using std::string;
using std::cout;
using std::endl;

/**
 * 函数指针是一种指针，它指向一个函数，而不是数据。
 * 函数指针可以用来调用指向的函数，可以作为函数参数传递，
 * 也可以作为函数的返回类型。函数指针在处理回调函数、动态函数调用等方面非常有用。
 * 
 * 
*/

/**
 * 比较两个string的大小
*/
bool function(const string& s1, const string& s2) {
   return s1.size() > s2.size();
}
//定义函数指针
bool (*pfuction) (const string& s1, const string& s2);

/**
 * 求两个int的和
*/
int add(int a, int b) {
    return a+b;
}
//定义函数指针
int (*padd) (int a, int b);

/**
 * 函数指针数组
*/
int plux(int a, int b) {
    return a+b;
}
int subtract(int a, int b) {
    return a-b;
}
int multiply(int a, int b) {
    return a*b;
}
//定义函数指针类型
typedef int (*Operation) (int a, int b);
//定义函数指针数组
Operation operations[] = {&plux, &subtract, &multiply};
// Operation operations[] = {plux, subtract, multiply};



int main(int argc, char const *argv[]){
    
    /**
     * 初始化函数指针
    */
    pfuction = &function; //初始化方式一
    // pfuction = function; //初始化方式二
    cout << pfuction("abc", "abcd") << endl;

    // padd = add;
    padd = &add;
    cout << padd(1,2) << endl;


    /**
     * 初始化函数指针数组
    */
   int x = 10;
   int y = 9;
   char op;
   std::cout << "Enter operation (+, -, *): ";
   std::cin >> op;
   int result;
   switch (op)
   {
   case '+':
    result = operations[0](x,y);
    break;
   case '-':
    result = operations[1](x,y);
    break;
   case '*':
    result = operations[2](x,y);
    break;
   default:
    cout << "Invalid operation " << endl;
    break;
   }
   cout << "result : " << result << endl;

    return 0;
   
}
