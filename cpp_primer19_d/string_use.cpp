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

void function1() {
    string s1('c',10);
    cout << "s1 ==> " << s1 << endl;

    string s2(10,'c');
    cout << "s2 ==> " << s2 << endl;

    cout << "s2 ==> " + s2 << endl; //也可以使用+号连接字符串

    string s3("abcd");
    cout << "s3 ==> " + s3 << endl;
    cout << "s3[0] ==> " << s3[0] << endl;
    cout << s3[0] << endl;
    cout << s3.substr(0,2) << endl;
    cout << s3.find("abc") << endl;
    size_t pos = s3.find("cd");
    cout << pos << endl;
    cout << string::npos << endl; //如果pos = 18446744073709551615，说明没有找到该str
    cout << s3.find("12") << endl;
}

int main(int argc, char const *argv[])
{
    function1();
    return 0;
}
