//
//  DebugInfoView.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 1/25/18.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "DebugInfoView.hpp"
#include "Macro.hpp"

DebugInfoView::DebugInfoView() : View({ 600, 100 }) {


}

void DebugInfoView::setup() {

    fpsLabel = new Label();
#if MEMORY_TRACKING
    allocatedLabel = new Label();
    deletedLabel = new Label();
    existsLabel = new Label();
#endif
    framesDrawnLabel = new Label();
    touchLabel = new Label();

    auto _labels = labels();
    auto labelHeight = _frame.size.height / _labels.size();

    FOR(_labels.size())
        addSubview(
            _labels[i]
            ->setFrame({ 0,
                i * labelHeight,
                _frame.size.width,
                labelHeight
                }));

    _touchID = 1;

    Input::onTouchBegan.subscribe(this, [this](const Point &point, int id) {
        touchLabel->setText("Touch began: "_s + point.x + " " + point.y);
    });

    Input::onTouchMoved.subscribe(this, [this](const Point &point, int id) {
        touchLabel->setText("Touch moved: "_s + point.x + " " + point.y);
    });

    Input::onTouchEnded.subscribe(this, [this](const Point &point, int id) {
        touchLabel->setText("Touch ended: "_s + point.x + " " + point.y);
    });
}

void DebugInfoView::update() {

#if DEBUG

    // MEMORY_MANAGER_INVISIBLE(
    fpsLabel->setText("FPS: "_s + Window::FPS);
    //#if MEMORY_TRACKING
    //     allocatedLabel->setText("Allocated: "_s + MemoryManager::totalObjectsAllocated);
    //     deletedLabel  ->setText("Deleted: "_s   + MemoryManager::totalObjectsDeleted);
    //     existsLabel   ->setText("Exists: "_s    + MemoryManager::totalObjectsExist());
    //#endif
    framesDrawnLabel->setText("Frames drawn: "_s + Window::framesDrawn);
    // );

#endif
}

Array<Label *> DebugInfoView::labels() const {
    return {
        fpsLabel,
#if MEMORY_TRACKING
        allocatedLabel,
        deletedLabel,
        existsLabel,
#endif
        framesDrawnLabel,
        touchLabel
    };
}

void DebugInfoView::setTouchLabelText(const std::string &text) {
#if DEBUG
    MEMORY_MANAGER_INVISIBLE(
        touchLabel->setText(text);
    );
#endif
}
