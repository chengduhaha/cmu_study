
#include <iostream>
#include <string>
#include <stdexcept>
#include <initializer_list>
#include <fstream>
#include <sstream>
#include <vector>

#include <algorithm>  // 包含std::sort所需的头文件

#include <set> // 添加这行来包含set容器的头文件
#include <map> // 添加这行来包含map容器的头文件
#include <unordered_map> // 添加这行来包含map容器的头文件

//sleep
#include <chrono>
#include <thread>

using namespace std;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::pair;
using std::set;
using std::map;
using std::unordered_map;

/**
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

 

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        
        for(int i=0; i<nums.size(); i++) {
            int need = target - nums[i];
            if(map.find(need) != map.end()) {
                return {map[need], i};
            }else {
                map[nums[i]] = i; 
            }
        }
        return {};
    }
};


int main(int argc, char const *argv[])
{   
    Solution s1;
    std::vector<int> v1 = {3,2,4};
    int target = 6;
    std::vector<int> res = s1.twoSum(v1, target);
    for(auto it=res.begin(); it !=res.end(); ++it) {
        cout << *it << endl;
    }
    return 0;
}