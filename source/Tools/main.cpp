
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"

//#include "gl"

using namespace std;

template <class T>
class ObjectsCounter {

public:

    static inline int created = 0;
    static inline int deleted = 0;

    static int exists() { return created - deleted; }


    ObjectsCounter() {
        created++;
    }

    virtual ~ObjectsCounter() {
        deleted++;
    }
};


int main() {

    int a, b;
    auto summ = [&] { return a + b; };
    a = 10;
    b = 29;
    cout << summ() << endl;

    String spes = "4242";


    cout << spes << endl;


    Array<int> test;

//    test.append(1, 2, 3, 4, 5, 6);


//    for (auto a : test)
//        cout << a << endl;

    cout << "hello" << endl;

    return 0;
}
