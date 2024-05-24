#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include "hdfsioutil.cpp"
#include "hdfsioutilv2.cpp"
#include "hdfsioutilv3.cpp"

using namespace std;
using std::string;
using std::cout;
using std::endl;


/**
 * 类的引用 main.cpp引用hdfsioutil.cpp，  hdfsioutil.cpp 引用 hdfsioutil.h
 * hdfsioutil.h 为头文件进行类和函数的声明，hdfsioutil.cpp对 hdfsioutil.h声明的东西进行具体实现
*/
int main(int argc, char const *argv[])
{
    HdfsIoUtil hdfsIoUtil("hdfs://dev1:8030","/usr/hdp/test.csv", 1024);
    string url = "hdfs://dev2:8030";
    string path = "/usr/hdp/test2.csv";
    int size = 4096; 

    hdfsIoUtil.set_hdfsurl(url);
    hdfsIoUtil.set_hdfsfilepath(path);
    hdfsIoUtil.set_hdfsfilesize(size);

    //HdfsIoUtilV2 hdfsIoUtilV2();
    /**
     * 这一行实际上不是在声明一个 HdfsIoUtilV2 对象，而是在声明一个返回 HdfsIoUtilV2 类型的函数 hdfsIoUtilV2，
     * 该函数没有参数。这被称为最令人困惑的解析（Most Vexing Parse）问题。要正确地声明并构造一个 HdfsIoUtilV2 对象，应该去掉函数声明的括号
    */
    HdfsIoUtilV2 hdfsIoUtilV2; //无参构造类应该如此声明
    hdfsIoUtilV2.create_hdfsioutil();

    HdfsIoUtilV3 hdfsIoUtilV3; //无参构造类应该如此声明
    hdfsIoUtilV3.create_hdfsioutilv3();


    return 0;
}
