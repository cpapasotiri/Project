#ifndef HELLO_HPP
#define HELLO_HPP

#include <iostream>
#include <string>

using namespace std;

class Hello;

class Hello{
    private:
    
    public:
        Hello();
        ~Hello();
        void sayHello(string name);
};


#endif