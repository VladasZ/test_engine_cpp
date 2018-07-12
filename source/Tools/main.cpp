
#include <iostream>
#include <functional>
#include <type_traits>

#include "RegistryKey.hpp"

#include "String.hpp"
#include "Log.hpp"

#include "Block.hpp"

using namespace std;


template<class T>
struct ArrTest {


    static T array;

    using type = decltype(array[0]);

};

class NotString {

};

int main() {

    try
    {

        NotString ns;

        Block spes(true);
        Block spes2(5);
        Block spes3("sss"_s);
        Block spes4("rglica");
        Block spes5(ns);
    }
    catch (String err)
    {
        Log(err);
    }



    return 0;
}