#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

using namespace std;
using std::cout;
using std::endl;
using std::string;

class Teacher
{
public:
    string teacher_name_;
    Teacher(string teacher_name) : teacher_name_(teacher_name){};
    Teacher() = default;
};

class Student {
 public:
    int student_id_;
    Student(int student_id) : student_id_(student_id) {};

    // Student() = delete;
};
/**
 * 类的默认构造 default constructor
*/
class Paper
{
private:
    string name_;
    int score;
    bool if_pass_;
    Student student1_ = Student(1); /**
                                    如果Student类中没有设置默认构造，则在引用Student类时要进行预先初始化实例，
                                    因为编译器自动认为Studnent的默认构造是删除的Student() = delete;

                                    */
    Teacher teacher1_; //Teacher中显示声明了默认构造 Teacher() = default; 则编译器就会调用该行

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
     * default initializatino 默认构造, 调用此构造时，类的所有属性都会赋默认值初始化
     * 比如int为0，bool为false等，但是如果属性为一个Student类，则编译器会调用该类的默认构造器，或者你在参数里初始化好
     * 如果没有回周报
     * 
     * 使用 = default 时，编译器生成的默认构造函数不会执行任何额外的初始化，
     * 而是使用成员变量的默认值（对于基本类型是未定义值，对于类类型是调用它们的默认构造函数）
    */
    Paper() = default;

    /**
     * 手动定义无参数构造函数时，你可以在构造函数体内添加自定义的初始化代码
     * 
     * 
     * 使用手动定义的无参数构造函数可以确保成员变量被明确初始化，
     * 而使用 = default 则依赖于编译器生成的默认行为，这在某些情况下可能导致未初始化的成员变量。根据实际需求选择合适的方法
    */
    // Paper () {
    //     score = 10;
    //     name_ = "Paper";
    //     if_pass_ = false;
    //     cout << "0 arguments" << endl; //
    // };

    void printArguments() {
        cout << this->name_ << " + " << this->score << " +  " << this->if_pass_ << endl;
    }
};

void createPaper(Paper paper) {
    paper.printArguments();
}


int main(int argc, char const *argv[])
{
    Paper paper;
    paper.printArguments();

    return 0;
}
