
#ifdef DESKTOP_BUILD

#include "View.hpp"
#include "JsonMapper.hpp"
#include "TestEngineTest.hpp"

using namespace ui;


namespace gm {

    MAKE_CLASS_INFO(Color, std::tuple(
            MAKE_PROPERTY("r", &Color::r),
            MAKE_PROPERTY("g", &Color::g),
            MAKE_PROPERTY("b", &Color::b),
            MAKE_PROPERTY("a", &Color::a)
    ));

    MAKE_CLASS_INFO(Point, std::tuple(
            MAKE_PROPERTY("x", &Point::x),
            MAKE_PROPERTY("y", &Point::y)
    ));

    MAKE_CLASS_INFO(Size, std::tuple(
            MAKE_PROPERTY("width", &Size::width),
            MAKE_PROPERTY("height", &Size::height)
    ));

    MAKE_CLASS_INFO(Rect, std::tuple(
            MAKE_PROPERTY("origin", &Rect::origin),
            MAKE_PROPERTY("size", &Rect::size)
    ));

}

namespace ui {

    MAKE_CLASS_INFO(View, std::tuple(
            MAKE_PROPERTY("color",    &View::background_color)
            , MAKE_PROPERTY("frame",    &View::_frame)
            //  , MAKE_PROPERTY("subviews", &View::_subviews)
    ));

}


class TestMember { public:
    int c = 0, d = 0;
    std::string to_string() const { return std::string() + VarString(c) + " " + VarString(d); }
};

class TestClass {
public:

    int a = 1;
    int b = 1;
    char lett = 1;

    std::vector<int> int_vector;

    std::vector<TestMember> members;
    std::vector<TestMember*> members_pointers;

    TestMember* member_pointer = nullptr;

    TestClass() = default;
    ~TestClass() {
        if (member_pointer != nullptr) {
            delete member_pointer;
        }
        for (auto mem : members_pointers) {
            delete mem;
        }
    }

    std::string to_string() const { return VarString(a) + " " + VarString(b) + " " + VarString(lett) + " " + VarString(member_pointer->to_string());
    }
};

MAKE_CLASS_INFO(TestMember, std::tuple(
        MAKE_PROPERTY("a", &TestMember::c)
        , MAKE_PROPERTY("b", &TestMember::d)
));

MAKE_CLASS_INFO(TestClass, std::tuple(
          MAKE_PROPERTY("a",                &TestClass::a)
          //,
        , MAKE_PROPERTY("b",                &TestClass::b)
        , MAKE_PROPERTY("lett",             &TestClass::lett)
        , MAKE_PROPERTY("int_vector",       &TestClass::int_vector)
        //,
        , MAKE_PROPERTY("member_pointer",   &TestClass::member_pointer)
        , MAKE_PROPERTY("members",          &TestClass::members)
        ,
        MAKE_PROPERTY("members_pointers", &TestClass::members_pointers)
));

MAKE_MAPPER(

//          gm::InfoOfColor
//        , gm::InfoOfPoint
//        , gm::InfoOfSize
//        , gm::InfoOfRect
//
//        , ui::InfoOfView

        InfoOfTestMember,
        InfoOfTestClass

);

constexpr auto json_mapper = mapping::JSONMapper<mapper>();

TestClass cl;

template <class T, class ValueType = typename T::value_type>
constexpr bool is_array() {
    return true;
}

template <class T>
constexpr bool is_array(std::enable_if_t<std::is_integral_v<T>> = nullptr) {
    return false;
}

using ValueType = std::vector<int>::value_type;

//static_assert(is_defined<std::vector<int>>);
//
//static_assert(is_defined<int::value_type>);

int main() {


    cl.a = 10;
    cl.b = 20;
    cl.lett = 'A';
    cl.member_pointer = new TestMember();
    cl.member_pointer->c = 30;
    cl.member_pointer->d = 40;

    cl.int_vector = { 44, 55, 66 };

    cl.members.push_back({ 1, 2 });
    cl.members.push_back({ 3, 4 });

    cl.members_pointers.push_back(new TestMember { 5, 6 });
    cl.members_pointers.push_back(new TestMember { 7, 8 });
    cl.members_pointers.push_back(new TestMember { 7, 8 });
    cl.members_pointers.push_back(new TestMember { 7, 8 });

//    mapper.get_property(&TestClass::int_vector, [&](const auto& property) {
//        Log(property.to_string());
//    });
//
//    mapper.get_property(&TestClass::members, [&](const auto& property) {
//        Log(property.to_string());
//    });
//
//    mapper.get_property(&TestClass::members_pointers, [&](const auto& property) {
//       Log(property.to_string());
//    });


    Log("hello");

   // std::string json_string = "{\"members_pointers\":[{\"a\":5,\"b\":6}]}";


//    auto parsed = json_mapper.parse<TestClass>(json_string);


    //auto parsed = json_mapper.parse<TestClass>(json_string);

      while (true) {
          json_mapper.test(cl);
      }


    return 0;
}

#endif
