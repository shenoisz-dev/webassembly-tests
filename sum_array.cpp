#include <stdint.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <random>

class MyClass {
public:
    MyClass() {}
    int my_method() {
        //std::cout << "Hello from C++!" << std::endl;
        //printf("Hello from C++!\n");
        return 42;
    }
};

MyClass* my_class = new MyClass();

std::string str = "Hello from C++!";

extern "C" {

    extern int state = 25; // export C++ variable
    extern void print_int(int); // import JS function
    extern void print_str(const char*, int len); // import JS function
    
    int sum_array(uint32_t* arr, int len) {
        uint32_t sum = 0;

        for (int i = 0; i < len; i++) {
            sum += arr[i];
        }

        print_int(sum); // call JS log instead of printf

        std::vector<uint32_t> vec = {1, 2, 3, 4, 5};
        vec.push_back(6);

        my_class->my_method();
        state = 17;

        return sum;
    }

    int get_random_number() {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100);
        return dis(gen);
    }

    
    const char* get_str() {
        return "Hello from C++!";
    }

    void print_test() {
        const char* msg = "testing!";
        print_str(msg, sizeof("testing!"));
    }
}