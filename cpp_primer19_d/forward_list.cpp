#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>

#include <fstream>
#include <sstream>

#include <forward_list>

using namespace std;
using std::cout;
using std::endl;
using std::string;

using std::forward_list;

/**
 * forward_list为单链表
 * 
 * e1-->e2-->e3-->e4-->e6
*/

int main(int argc, char const *argv[])
{
    forward_list<int> list = {1,2,3,4,5,6,7,8,9};
    
    // _,    1,   2,   3,  4,   5,   6,   7,   8,   9
    // |     |
    //prev   
            // cur

    
    forward_list<int>::iterator prev = list.before_begin();
    forward_list<int>::iterator cur = list.begin();


    for (auto it = list.begin(); it!=list.end(); ++it)
    {
        cout << *it;
    }

    /**
     * 删除单链表中的偶数
    */
    while (cur != list.end())
    {
        if (*cur % 2 == 0) {
            cur = list.erase_after(prev);
            // prev = cur->next;
        }else {
            prev = cur;
            cur++;
        }
    }

    cout << "\n" << endl;

    for (auto it = list.begin(); it!=list.end(); ++it)
    {
        cout << *it;
    }
    
    

    return 0;
}
