//
// Created by nissan and moshe on 6/3/18.
//

#include "TestCase.hpp"

//int TestCase::total_passed =0;
//
//int TestCase::total_failed =0;

void TestCase::failedTest(std::string desc){
    num_failed++;
//    total_failed++;
    test_err << desc << "\n";
}

void TestCase::passedTest(){
    num_passed++;
//    total_passed++;
}
//Test int operators: 2 failed, 5 passed, 7 total.
void TestCase::print(){
	std::stringstream s1;

	s1 << test_name << ": " << num_failed << " failed, " << num_passed << " passed, " << num_failed + num_passed << " total." << std::endl << "---" << std::endl;
    test_err << s1.str();
}
