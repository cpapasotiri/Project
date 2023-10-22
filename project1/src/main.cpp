#include <iostream>
#include <string>

using namespace std;

#include "hello.hpp"
#include "add.hpp"

int main(int argc, char *argv[]){
    
    Hello hello;
    hello.sayHello("Christina");
    int a = add(1, 2);
    cout << "1 + 2 = " << a << endl;

    return 0;
}
