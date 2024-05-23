#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include "hdfsioutil.h"

using namespace std;
using std::string;
using std::cout;
using std::endl;

HdfsIoUtil::HdfsIoUtil(string hdfsurl, string hdfsfilepath, int hdfsfilesize) : hdfsurl(hdfsurl), hdfsfilepath(hdfsfilepath), hdfsfilesize(hdfsfilesize) {};


void HdfsIoUtil::set_hdfsurl(string &url) {
    cout << "set hdfsurl = " << url << endl;
    this->hdfsurl = url;
}
void HdfsIoUtil::set_hdfsfilepath(string &path) {
    cout << "set hdfsfilepath = " << path << endl;
    this->hdfsfilepath = path;
}
void HdfsIoUtil::set_hdfsfilesize(int &size) {
    cout << "set hdfsfilesize = " << hdfsfilesize << endl;
    this->hdfsfilesize = size;
}
