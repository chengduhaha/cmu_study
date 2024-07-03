#include <iostream>
#include <sstream>
#include <vector>
#include <string>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
    
};

ListNode* buildListNode(std::vector<int>& array1) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;
    for(int i=0; i<array1.size(); i++) {
        ListNode* newListNode = new ListNode(array1[i]);
        if(head == nullptr) {
            head = newListNode;
            tail = newListNode;
        }
        tail->next = newListNode;
        tail = tail->next;
    }
    return head;
}

void printListNode(ListNode* listNode) {
    std::string output;
    while(listNode != nullptr) {
        output += std::to_string(listNode->val) + " -> ";
        listNode = listNode->next;
    }
    std::cout << output << std::endl;
}

int main() {
    std::string line;
    std::getline(std::cin, line);

    if(line.empty()) {
        return 0;
    }

    std::istringstream iss(line);
    std::string tmp;
    std::vector<int> array;
    while(getline(iss, tmp, ',')) {
        array.push_back(std::stoi(tmp));
    }
    ListNode* listNode = buildListNode(array);
    printListNode(listNode);

    return 0;
}