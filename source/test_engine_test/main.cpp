
#ifdef DESKTOP_BUILD

#include <tuple>

#include "Log.hpp"
#include "NewMapper.hpp"
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

constexpr auto CatsInfo = mapping::ClassInfo(
        "Cat",
        std::make_tuple(
                mapping::Property("age",    &Cat::age   ),
                mapping::Property("height", &Cat::height)
                ));

//constexpr auto DogsInfo = mapping::ClassInfo(
//        "Dog",
//        std::make_tuple(
//                mapping::Property("height", &Dog::height)
//        ));


//constexpr auto mapper = mapping::Mapper(std::make_tuple(CatsInfo, DogsInfo));
//
//
constexpr auto speec = std::make_tuple(11, 23, 35, 49.4);

constexpr auto get_val() {
    int result = 0;
    cu::iterate_tuple(speec, [&](auto val) {
        if (val > 20 && val < 40) {
            result = val;
        }
    });
    return result;
}

constexpr auto spik = get_val();

int main() {


    static_assert(spik > 20);

//
//    Log(CatsInfo.to_string());
//    Log(mapper.to_string());
//
//    Log(get_val());
//
//
//
//
//    if constexpr (mapper.exists<Cat>()) {
//
//    }

    return 0;
}

#endif
