#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include "hdfsioutil.h"
#include "hdfsioutilv2.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

//不需要实现构造 因为是空构造
// HdfsIoUtilV2::HdfsIoUtil(string hdfsurl, string hdfsfilepath, int hdfsfilesize) : hdfsurl(hdfsurl), hdfsfilepath(hdfsfilepath), hdfsfilesize(hdfsfilesize) {};

HdfsIoUtilV2::HdfsIoUtilV2() {};

void HdfsIoUtilV2::create_hdfsioutil() {
    
    HdfsIoUtil hdfsIoUtil("test", "test", 0);
    string url = "hdfs://v2:8030";
    string path = "/usr/hdp/v2.csv";
    int size = 4096; 
    hdfsIoUtil.set_hdfsurl(url);
    hdfsIoUtil.set_hdfsfilepath(path);
    hdfsIoUtil.set_hdfsfilesize(size);
    
    //该友类可以访问HdfsIoUtil类的私有属性
    cout << "HdfsIoUtilV2::create_hdfsioutil!!!" << hdfsIoUtil.hdfsurl << hdfsIoUtil.hdfsfilepath << hdfsIoUtil.hdfsfilesize << endl;

    
}
