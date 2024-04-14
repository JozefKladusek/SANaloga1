#include <iostream>
#include <cassert>
#include "main.cpp" 

void test_inputText() {
    std::string input_file = "test_input.txt"; // Create a test input file
    std::ofstream file(input_file);
    file << "Test input text";
    file.close();

    std::string result = inputText(input_file);
    assert(result == "Test input text");
    std::cout << "Test inputText passed" << std::endl;
}

void test_reverseString() {
    std::string str = "Test string";
    std::string result = reverseString(str);
    assert(result == "gnirts tseT");
    std::cout << "Test reverseString passed" << std::endl;
}

// Add more test functions for other functions in your code

int main() {
    test_inputText();
    test_reverseString();
    // Call other test functions here

    return 0;
}
