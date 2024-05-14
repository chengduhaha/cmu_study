#include <iostream>
#include <string>

using namespace std;
using std::string;
using std::cout;
using std::endl;


int main(int argc, char const *argv[])
{
    //初始化string的方法
    string a = "abc"; //copy construction 拷贝构造 
    string b("abc"); //direct construction 直接构造
    string c(10, 'c'); //direct construction 直接构造

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;

    //查看字符串的长度，返回值为size_type size_t,是一个无符号的数。32位，64位
    size_t a_size1 = a.size();
    unsigned int a_size2 = a.size();
    cout << "a_size1 = " << a_size1 << endl;
    cout << "a_size2 = " << a_size2 << endl;

    //查看字符串是否为空 不为空 0， 空 1
    bool a_em =  a.empty();
    cout << "a.empty = " << a_em << endl;

    string ddd("");
    bool d_em =  ddd.empty();
    cout << "d.empty = " << d_em << endl;

    //字符串大小写转换，以及通过引用进行改变
    string test = "helloworld";
    for (size_t i = 0; i < test.size(); i++)
    {
        test[i] = toupper(test[i]);
    }
    
    //for(char& ch : test) 中通过引用char&进行改变 只有char不可以
    // for(char& ch : test) {
    //     ch = toupper(ch);
    // }
    cout << "upper : " << test << endl;

    string inputconsole;
    std::cin >> inputconsole; //终端控制台输入 test aset ss ； cin读到空格就会停止 无法读取一整行
    cout << inputconsole << endl; //输出 test 

    string inputconsole2;
    getline(std::cin, inputconsole2); //使用getline方法能读取一整行,到回车才停止，从std::cin输入读去放入到inputconsole2
    cout << inputconsole2 << endl;


    

    return 0;
}
