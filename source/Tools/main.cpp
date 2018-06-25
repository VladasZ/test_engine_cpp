
#include <iostream>
#include <memory>
#include "Array.hpp"

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


int main() {

    Array<pair<String, any>> riglak = { { "spes" , "grex" },{ "mres", "gres" } };

   // Block spes = { {"spes" , "grex" }, {"mres", "gres"} };

    return 0;
}