#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include "hdfsioutil.h"
#include "hdfsioutilv3.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

//不需要实现构造 因为是空构造
// HdfsIoUtilV2::HdfsIoUtil(string hdfsurl, string hdfsfilepath, int hdfsfilesize) : hdfsurl(hdfsurl), hdfsfilepath(hdfsfilepath), hdfsfilesize(hdfsfilesize) {};

HdfsIoUtilV3::HdfsIoUtilV3() {};

void HdfsIoUtilV3::create_hdfsioutilv3() {
    
    HdfsIoUtil hdfsIoUtil("test", "test", 0);
    string url = "hdfs://v3:8030";
    string path = "/usr/hdp/v3.csv";
    int size = 8192; 
    hdfsIoUtil.set_hdfsurl(url);
    hdfsIoUtil.set_hdfsfilepath(path);
    hdfsIoUtil.set_hdfsfilesize(size);
    
    //该友类可以访问HdfsIoUtil类的私有属性
    cout << "HdfsIoUtilV3::create_hdfsioutil!!! " << hdfsIoUtil.hdfsurl << hdfsIoUtil.hdfsfilepath << hdfsIoUtil.hdfsfilesize << endl;

    
}
