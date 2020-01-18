
#ifdef DESKTOP_BUILD

#include "View.hpp"
#include "TestView.hpp"
#include "JsonMapper.hpp"
#include "TestMappingModels.hpp"
#include "TestEngineTest.hpp"

#include "GMMapping.hpp"
#include "UIMapping.hpp"

using namespace ui;
using namespace mapping;

MAKE_CLASS_INFO(Simple,
                MAKE_PROPERTY("a", &Simple::a)
);


MAKE_MAPPER(te_mapper,

            InfoOfSimple,

            gm::InfoOfColor,
            gm::InfoOfPoint,
            gm::InfoOfSize,
            gm::InfoOfRect,

            ui::InfoOfView

);

constexpr auto json_mapper = mapping::JSONMapper<te_mapper>();

int main() {

    ui::View* view = new View();

    ui::View* subview = new ui::View();
    subview->add_subview(new ui::View());
    subview->add_subview(new ui::View());
    subview->add_subview(new ui::View());
    subview->add_subview(new ui::View());

    subview->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->add_subview(new ui::View());

    subview->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->add_subview(new ui::View());

    subview->_subviews.back()->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->_subviews.back()->add_subview(new ui::View());
    subview->_subviews.back()->_subviews.back()->_subviews.back()->add_subview(new ui::View());

    view->add_subview(subview);
    view->add_subview(subview);
    view->add_subview(subview);
    view->add_subview(subview);

    while(true) {
        json_mapper.test(view);
    }

    return 0;
}

#endif
