#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include <fstream>
#include <sstream>

using namespace std;
using std::cout;
using std::endl;
using std::string;


int count_words_number(string words) {
    std::stringstream ss(words);
    int count = 0;
    string word;
    while(ss >> word) {
        count ++;
    }
    return count;
}

int main(int argc, char const *argv[])
{
    std::ofstream os("test.txt", std::ios::app);
    os << "hello world\n";
    os << "how are you\n";

    //buffer
    os.flush();
    os.close();    

    std::ifstream is("test.txt");

    string content;
    getline(is, content);
    cout << content << endl;

    cout << count_words_number("hello who are you") << endl;
    return 0;
}
