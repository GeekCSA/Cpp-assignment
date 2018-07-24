//
// Created by nissan on 6/3/18.
//

#ifndef EXERCISE9_0_TESTCASE_H
#define EXERCISE9_0_TESTCASE_H
#include <iostream>
#include <sstream>

// #include "TestException.hpp"


class TestCase {
    std::string test_name;
    std::ostream& test_err;

    void failedTest(std::string desc);

    void passedTest();

public:

    int num_passed;
//    int total_passed;

    int num_failed;
//    int total_failed;

    TestCase(std::string str,std::ostream& cerr ) :test_name(str),test_err(cerr),num_passed(0),num_failed(0){}

    template<typename T> TestCase& check_equal(T a, T b){
        if (a==b){
            passedTest();
        }else{
            std::stringstream s1;
            s1 << test_name << ": Failure in test #" << num_passed+num_failed+1 << ": " << b << " should equal " << a << "!";
            failedTest(s1.str());
        }
        return *this;
    }

    template<typename T> TestCase& check_different(T a, T b){
        if (a==b){
            std::stringstream s1;
            s1 << test_name << ": Failure in test #" << num_passed+num_failed+1 << ": " << b << " should not equal " << a << "!";
            failedTest(s1.str());
//             failedTest("the objects are equal");
        }else{
            passedTest();
        }
        return *this;
    }

    template<typename Function, typename T, typename S> TestCase& check_function(Function f,T a, S b) {
        if(f(a)==b){
            passedTest();
        }
        else{
            std::stringstream s1;
            s1 << test_name << ": Failure in test #" << (num_passed+num_failed+1) << ": " << "Function should return "<< b << " but returned " << f(a) << "!";
            failedTest(s1.str());
        }

        return *this;

    }

    template<typename T> TestCase& check_output(T a, std::string b) {
    	std::stringstream s;
    	s << a;

        if(s.str()==b){
            passedTest();
        }
        else{
            std::stringstream s1;
            s1 << test_name << ": Failure in test #" << (num_passed+num_failed+1) << ": " << "string value should be "<< b << " but is " << s.str() << "!";
            failedTest(s1.str());
        }

        return *this;

    }

    void print();

};


#endif //EXERCISE9_0_TESTCASE_H
