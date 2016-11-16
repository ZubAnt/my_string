#include <iostream>
#include <string.h>

#include "my_string.h"

static void print_error(const std::runtime_error &err){

    std::cout << "ERRORS: " << err.what() << std::endl;
}

void test_my_string(){

    //test constructors
    {
        std::cout<< "==========TEST CONSTRUCTORS==========" << std::endl;

        my_string empty;
        my_string c_string("full_C_sting");
        my_string c_n_string("cut_c_string", 5);
        my_string n_char(5, '$');
        my_string cpy(n_char);

        std::cout << "empty string         = " << empty << std::endl;
        std::cout << "c_string string      = " << c_string << std::endl;
        std::cout << "c_n_string string    = " << c_n_string << std::endl;
        std::cout << "n_char string, n = 5 = " << n_char<< std::endl;
        std::cout << "cpy str from n_char  = " << cpy << std::endl;

        std::cout << "==========END  CONSTRUCTORS==========" << std::endl << std::endl;
    }

    //test operator +
    {
        std::cout<< "===========TEST OPERATOR + ===========" << std::endl;

        my_string hello = "Hello";
        my_string space = " ";
        my_string world = "world";

        const char *c_hello = "Hello";
        const char *c_world = "world";

        my_string hel_world = hello + space + world;
        my_string c_hel_world1 = hello + space + c_world;
        my_string c_hel_world2 = c_hello + space + world;
        my_string c_hel_world3 = c_hello + space + c_world;

        std::cout << "Hello world     = " << hel_world << std::endl;
        std::cout << "c_Hello world1  = " << c_hel_world1 << std::endl;
        std::cout << "c_Hello world2  = " << c_hel_world2 << std::endl;
        std::cout << "c_Hello world3  = " << c_hel_world3 << std::endl;

        std::cout<< "===========END  OPERATOR + ===========" << std::endl << std::endl;
    }

    //test find
    {
        std::cout<< "===========TEST FIND STRING===========" << std::endl;

        my_string test = "This is good test";
        my_string good = "good";

        size_t pos1 = test.find("good",0, strlen("good"));
        size_t pos2 = test.find(good, 2);
        size_t pos3 = test.find("good");

        std::cout << "Find in " << test << " \"good\"" << std::endl
                  << " pos1 = " << pos1 <<std::endl
                  << " pos2 = " << pos2 <<std::endl
                  << " pos3 = " << pos3 <<std::endl;

        std::cout<< "===========END  FIND STRING===========" << std::endl << std::endl;
    }

    //test append
    {
        std::cout<< "===========TEST APPEND STR ===========" << std::endl;

        my_string hello("\"Hello");
        my_string teacher(", techer");

        hello.append(teacher);
        hello.append("! I am student!\"");

        std::cout << "message = " << hello << std::endl;

        std::cout<< "===========END  APPEND STR ===========" << std::endl << std::endl;
    }

    //test operator +=
    {
        std::cout<< "===========TEST OPERATOR+= ===========" << std::endl;

        my_string oper = "oper";
        my_string ator = "ator";

        oper += ator;

        my_string message = "\"test " + oper;

        message += " +=\"";

        std::cout << "message = " << message << std::endl;

        std::cout<< "===========END  OPERATOR+= ===========" << std::endl << std::endl;
    }

    //test sub_str
    {
        std::cout<< "===========  TEST SUB_STR  ===========" << std::endl;

        my_string full_string = "Hello, my fried";
        my_string sub_string = full_string.substr(7, 2);

        std::cout << "sub_str in " << full_string << "; pos = 7, n = 2;" << std::endl
                  << "sub_str = " << sub_string << std::endl;

        std::cout<< "===========  END  SUB_STR  ===========" << std::endl << std::endl;
    }
}

void test_errors()
{
    ///Здесь специально в catch не писал throw
    std::cout<< "===========   TEST ERRORS  ===========" << std::endl;

    //test constructor
    try{
        char *nptr = nullptr;
        my_string ctn(nptr);
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test constructor
    try{
        char *nptr = nullptr;
        my_string ctn(nptr, 15);
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test append
    try{
        char *nptr = nullptr;
        my_string app = "test";
        app.append(nptr, 15);
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test operator +
    try{
        char *nptr = nullptr;
        my_string t = "test+";
        my_string test = t + nptr;
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test operator +=
    try{
        char *nptr = nullptr;
        my_string t = "test+=";
        t += nptr;
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test operator []
    try{
        my_string t = "test+=";
        size_t pos = t[1000];
        std::cout << pos << std::endl;
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test find
    try{
        my_string t = "find";
        t.find(nullptr);
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    //test find
    try{
        my_string t = "find";
        t.find("test", 1000);
    }
    catch(const std::runtime_error &err){
        print_error(err);
    }

    std::cout<< "===========  END  ERRORS   ===========" << std::endl << std::endl;
}
