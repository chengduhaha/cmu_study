#ifndef HDFSIOUTIL_H
#define HDFSIOUTIL_H

#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include "hdfsioutilv2.h"
#include "hdfsioutilv3.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

class HdfsIoUtil {
    friend class HdfsIoUtilV2; //声明友类 友类可以对该类进行构造 和访问其private变量
    friend void HdfsIoUtilV3::create_hdfsioutilv3(); //声明一个方法为friend 该方法可以对该类进行构造 和访问其private变量
 public:
    HdfsIoUtil(string hdfsurl, string hdfsfilepath, int hdfsfilesize);
    void set_hdfsurl(string &url);
    void set_hdfsfilepath(string &path);
    void set_hdfsfilesize(int &size);
 private:
    string hdfsurl;
    string hdfsfilepath;
    int hdfsfilesize;
};

#endif