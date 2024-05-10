#include <iostream>

int function(int arg) {
    std::cout << "hello : " << arg << std::endl;
    return 1;
}

int main(int argc, char** argv) {
    for (int i = 0; i < argc; i++)
    {
        std::cout << argv[i] << std::endl;
    }
    
    function(100);
    return 0;
}