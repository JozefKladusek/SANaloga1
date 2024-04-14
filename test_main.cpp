#include <iostream>
#include "main.h" 

void runTests() {
    // Test sestej function
    std::cout << "Testing sestej function:" << std::endl;
    int result = sestej(1, 2);
    if (result == 3) {
        std::cout << "1 + 2 = 3 (PASS)" << std::endl;
    } else {
        std::cout << "1 + 2 != 3 (FAIL)" << std::endl;
    }
    
    result = sestej(0, 0);
    if (result == 0) {
        std::cout << "0 + 0 = 0 (PASS)" << std::endl;
    } else {
        std::cout << "0 + 0 != 0 (FAIL)" << std::endl;
    }

}

int main() {
    runTests();
    return 0;
}
