#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::cout;
using std::endl;
using std::string;

/**
 * delegate constructor
 * 委托构造器 初始化不同参数的构造器 简化代码
*/
class Paper
{
private:
    string name_;
    int score;
    bool if_pass_;

public:
    Paper(string name, int score, bool if_pass) : name_(name), score(score), if_pass_(if_pass){
        cout << "3 arguments" << endl;
    };

    Paper(string name, int score) : Paper(name, score, true) {
         cout << "2 arguments" << endl;
    };

    Paper(string name) : Paper(name, 100, true) {
        cout << "1 arguments" << endl;
    };

    /**
     * explicit 关键字用于修饰构造函数，以防止编译器进行隐式类型转换。
     * 默认情况下，单参数构造函数可以用于隐式转换，如果这种行为不希望发生，可以使用 explicit 关键字来禁止这种隐式转换。
    */
    explicit Paper() : Paper("autogeneration", 60, true) {
        cout << "0 arguments" << endl;
    };

    void printArguments() {
        cout << this->name_ << this->score << this->if_pass_ << endl;
    }
};

void createPaper(Paper paper) {
    paper.printArguments();
}


int main(int argc, char const *argv[])
{
    Paper paper1("xiaoming", 80, true);
    Paper paper2("liming", 85);
    Paper paper3("liuli");

    createPaper(Paper("dudu"));
    string name = "jiaojiao";
    createPaper(name); //编译器对函数进行了优化将 name = "jiaojiao" 转换为 Paper("jiaojiao")

    // createPaper(); //由于无参构造方法前面用了explicit修饰，所以编译器无法进行优化自动转换，必须显示的调用无参构造Paper()
    createPaper(Paper());
    return 0;
}
