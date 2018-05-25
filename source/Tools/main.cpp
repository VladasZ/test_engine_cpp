
#include <iostream>

#include "Log.hpp"

#include "TestObject.hpp"

using namespace std;

class TestClass : public TestObject<TestClass> {

public:


};


int main() {
 
    TestClass::Array arr;
    TestClass::Ptr pointer;

    TestClass aarere;
    TestClass aarere2;
    TestClass aarere3;
    TestClass aarere4;
    TestClass aarere5;
    TestClass aarere6;
    TestClass aarere8;

    return 0;
}