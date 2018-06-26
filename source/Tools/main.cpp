
#include <iostream>
#include <memory>
#include <optional>

#include "Array.hpp"
#include "Dictionary.hpp"

#include "String.hpp"

#include "Mappable.hpp"

#include "Macro.hpp"
#include "Block.hpp"

#include "ExceptionCatch.hpp"
#include "Log.hpp"

using namespace std;


class Cat : public Mappable<Cat> {
public:

    int age = 10;
    string name = "koteiko";

    static auto properties() {
        return make_tuple(
            make_property("age", &Cat::age),
            make_property("name", &Cat::name)
        );
    }
};

template <class T>
void usingTest() {

    using arr = Array<T>;

    cout << nameOf<arr> << endl;
}

optional<int> getSmershc() {

    return nullopt;
}

void test() {

    Block array = { "spialgok" , "spes" };


    for (auto n : array.array<string>())
        cout << n << endl;
}

int main() {

    try {
        test();
    }
    catch (...) {
        Log(what());
    }


    return 0;
}