#include <iostream>

int function(int arg) {
    std::cout << "hello : " << arg << std::endl;
    return 1;
}

void function2() {
    /* /n 换行 */
    std::cout << "换行\n";
}

void function3() {
    /* /n 不换行 */
    std::cout << "不换行";
}

// argc : argument count
// argv : argument vector
int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    
    function(100);
    function2();
    function3();
    //返回值表明程序运行的结果 0 成功 1 失败
    /**
     * 可以通过echo $? 来查看上一步运行程序的返回值结果
     * [root@hadoop1 cpp_primer2_d]# ./cpp_primer2 11 22
        ./cpp_primer2
        11
        22
        hello : 100
        [root@hadoop1 cpp_primer2_d]# echo $?
        0
    */

    /*
        literal为常数的意思
        string literal = "abc"
        int literal = 123
    */

   /**
    * sign / unsign
    * 500 / -500
   */
   
    return 0;
}