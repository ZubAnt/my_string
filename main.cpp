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
    catch(std::runtime_error &err){
        cout << err.what() << endl;
    }
    catch(std::bad_alloc &err){
        cout << err.what() << endl;
    }

    return 0;
}
