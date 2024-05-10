#include <iostream>

int function(int arg) {
    std::cout << "hello : " << arg << std::endl;
    return 1;
}

int main() {
    function(100);
    return 0;
}