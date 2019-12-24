
#ifdef DESKTOP_BUILD

#include <tuple>

#include "Log.hpp"
#include "Property.hpp"
#include "ClassInfo.hpp"
#include "IterateTuple.hpp"
#include "TestEngineTest.hpp"

template <class T>
class ClassInfoLa {
public:
    using Type = T;
    constexpr std::string_view name() {
        return T::class_name();
    }
};

class Dog {
public:

    int height;

    static constexpr std::string_view class_name() {
        return "Dog";
    }
};

class Cat {
public:
    static constexpr std::string_view class_name() {
        return "Cat";
    }

    int age;
    int height;

};

constexpr auto cats_age = mapping::Property("age", &Cat::height);

constexpr auto CatsInfo = new_mapping::ClassInfo(
        "Cat",
        std::make_tuple(
                mapping::Property("age",    &Cat::age   ),
                mapping::Property("height", &Cat::height)
                ));

constexpr auto DogsInfo = new_mapping::ClassInfo(
        "Dog",
        std::make_tuple(
                mapping::Property("height", &Dog::height)
        ));

//constexpr auto gauno = new_mapping::ClassInfo(333);

int main() {

    Log(CatsInfo.to_string());


    return 0;
}

#endif
