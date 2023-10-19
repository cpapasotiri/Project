#include "hello.hpp"

Hello::Hello(){



}

Hello::~Hello(){

}

void Hello::sayHello(string name){
    string hello = "Hello, " + name + "!";
    cout << hello << endl;
}