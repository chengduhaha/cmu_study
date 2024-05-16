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
 * 单目运算符 双目运算符
 * 重载运算符
*/
int main(int argc, char const *argv[])
{
    /**
     * 运算符根据操作数的数量可以分 ： 单目运算符unary operator，只需要一个操作数） ， 双目运算符（binary operator，需要两个操作数）
    */
    //单目运算符
    //1. 递增/递减运算符: ++ 和 --
    // 前置形式：先进行运算，后返回值
    int x = 5;
    ++x; // x 的值现在是 6
    cout << x << endl;
    //后置形式：先返回原值，后进行运算。注意后置形式在某些编译器中可能会稍微低效，因为它需要保留原值以返回
    int y = 15;  
    y++; // 返回 15，但 y 的值现在是 16
    cout << y << endl;
    
    //2. 负号: -
    // 用于改变数值的符号
    int z = -3; // z 的值为 -3

    //3. 逻辑非: !
    // 用于布尔值，反转其真值
    bool flag = true;
    if (!flag) { // 这里不会执行，因为flag为true
        cout << flag << endl;
    }

    //4. 位取反: ~
    // 对整数每一位进行按位取反操作。
    int num = 5; // 二进制表示为0101
    int result = ~num; // 结果的二进制为1010，十进制为-6（考虑补码表示）
    cout << result << endl;

    //双目运算符（Binary Operators）
    //1. 算术运算符: +, -, *, /, %
    // 加、减、乘、除、取模运算
    int a = 10, b = 5;
    int sum = a + b; // sum 为 15
    int diff = a - b; // diff 为 5
    int product = a * b; // product 为 50
    int quotient = a / b; // quotient 为 2
    int remainder = a % b; // remainder 为 0
    cout << "sum " <<sum << endl;
    cout << "diff " <<diff << endl;
    cout << "product " << product << endl;
    cout << "quotient " << quotient << endl;
    cout <<  "remainder " << remainder << endl;
    
    //2. 关系运算符: <, >, <=, >=, ==, !=
    //用于比较两个操作数的大小或相等性。
    int xx = 100;
    int yy = -101;
    if (xx > yy) { // 不执行，因为a不大于b
        cout <<  "xx > yy" << endl;
    }
    else if (xx == yy) { // 执行，因为a等于b
        cout <<  "xx == yy" << endl;
    }
    else {
        cout <<  "xx < yy" << endl;
    }

    //3. 逻辑运算符: &&, ||
    // 逻辑与、逻辑或，用于组合布尔表达式。
    if (xx > 0 && yy > 0) { // 如果a和b都大于0，则执行
         cout <<  "xx > 0 && yy > 0" << endl;
    }
    if (xx > 0 || yy < 0) { // 如果a大于0或b小于0，则执行
        cout <<  "xx > 0 || yy < 0" << endl;
    }

    //4. 位运算符: &, |, ^, <<, >>
    // 按位与、按位或、按位异或、左移、右移
    int xs = 5; // 二进制0101
    int ys = 3; // 二进制0011
    int andResult = xs & ys; // 二进制0001，十进制1
    int orResult = xs | ys;  // 二进制0111，十进制7
    cout <<  "andResult " << andResult << endl;
    cout <<  "orResult " << orResult << endl;

    /**
     * 重载运算符号 Overloaded operators
     * 运算符重载允许程序员为自定义类型（如类或结构体）提供特定的运算符行为。这意味着，你可以改变或增强运算符对于特定类型的操作方式
    */
   


    return 0;

}
