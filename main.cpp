#include <iostream>
#include <string>
#include <map>
#include "./lib/test_my_string.h"
#include "./lib/my_string.h"

using namespace std;

int main()
{

    try{
        test_my_string();
        test_errors();
    }
    catch(std::runtime_error &s){
        cout << s.what() << endl;
    }

//    my_string Hello = "Hello";
//    my_string World = "World";
//    my_string HW;

//    cout << "Hello = " << Hello << "; World = " << World << endl;

//    HW =Hello + " World";
//    cout << "Hello World = " << HW << endl;

//    World = Hello;
//    cout << "Hello = " << Hello << "; World = " << World << endl;



    return 0;
}
