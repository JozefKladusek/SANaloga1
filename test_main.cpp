#include <iostream>
#include "main.cpp" 

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

    // Test odstej function
    std::cout << "Testing odstej function:" << std::endl;
    result = odstej(1, 2);
    if (result == -1) {
        std::cout << "1 - 2 = -1 (PASS)" << std::endl;
    } else {
        std::cout << "1 - 2 != -1 (FAIL)" << std::endl;
    }
    
    result = odstej(0, 0);
    if (result == 0) {
        std::cout << "0 - 0 = 0 (PASS)" << std::endl;
    } else {
        std::cout << "0 - 0 != 0 (FAIL)" << std::endl;
    }

    // Test zmnozi function
    std::cout << "Testing zmnozi function:" << std::endl;
    result = zmnozi(1, 2);
    if (result == 2) {
        std::cout << "1 * 2 = 2 (PASS)" << std::endl;
    } else {
        std::cout << "1 * 2 != 2 (FAIL)" << std::endl;
    }
    
    result = zmnozi(0, 0);
    if (result == 0) {
        std::cout << "0 * 0 = 0 (PASS)" << std::endl;
    } else {
        std::cout << "0 * 0 != 0 (FAIL)" << std::endl;
    }
    
    result = zmnozi(1, 0);
    if (result == 0) {
        std::cout << "1 * 0 = 0 (PASS)" << std::endl;
    } else {
        std::cout << "1 * 0 != 0 (FAIL)" << std::endl;
    }
}

    int main() {
   
    runTests();
    return 0;

}
