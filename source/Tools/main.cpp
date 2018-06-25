
#include <iostream>
#include <memory>
#include "Array.hpp"
#include "Dictionary.hpp"

#include "String.hpp"

#include "Mappable.hpp"

#include "Macro.hpp"
#include "Block.hpp"

using namespace std;


class Cat : public Mappable<Cat> {
public:

    int age = 10;
    string name = "koteiko";

    static auto properties() {
        return make_tuple(
            make_property("age",  &Cat::age),
            make_property("name", &Cat::name)
        );
    }

};

template <class T>
void usingTest() {

    using arr = Array<T>;

    cout << nameOf<arr> << endl;
}

int main() {

    Block arrus = { 1, 2, 3, 4, 5, 6 };


    Block prt = &arrus;


    return 0;
}