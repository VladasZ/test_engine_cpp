
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

auto lala = decltype(cats_age)::is_property;

constexpr auto CatsInfo = new_mapping::ClassInfo(
        std::make_tuple(
                cats_age,
                cats_age
                ));



//constexpr auto gauno = new_mapping::ClassInfo(333);


constexpr std::string_view spes = cats_age.name;

class Spes {

};

constexpr auto classes_info = std::make_tuple(ClassInfoLa<Cat>(), ClassInfoLa<Dog>());

template <class Class, class Check>
constexpr void check(bool& value, ClassInfoLa<Check> info) {
    if constexpr (std::is_same_v<Check, Class>) {
        value = true;
    }
}

template <class T>
constexpr bool exists() {
    bool result = false;
    std::apply([&](auto&&... args) {((
            check<T>(result, args)
    ), ...);}, classes_info);
    return result;
}


int main() {

    auto info = ClassInfoLa<Cat>();

    static_assert(exists<Dog>());

    Log(info.name());

    Log(exists<Cat>());
    Log(exists<Dog>());
    Log(exists<Spes>());

    Log(std::string() + std::string(Cat::class_name()));

    return 0;
}

#endif
