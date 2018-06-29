
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
#include "Property.hpp"

using namespace std;

class Paw {
public:

    int size;
};

class Cat : public Mappable<Cat> {
public:

    int age = 10;
    string name = "koteiko";
    Paw paw;

    static auto properties() {
        return make_tuple(
            PROPERTY(age, Cat),
            PROPERTY(name, Cat)
        );
    }
};


int main() {


    cout << Cat::toString(Cat()) << endl;

    return 0;
}