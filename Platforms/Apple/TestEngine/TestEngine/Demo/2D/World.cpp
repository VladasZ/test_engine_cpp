//
//  World.cpp
//  TestEngine
//
//  Created by Vladas Zakrevskis on 11/03/2018.
//  Copyright © 2018 VladasZ. All rights reserved.
//

#include "World.hpp"
#include "Movable.hpp"
#include "Sprite.hpp"
#include "Image.hpp"
#include "Events.hpp"
#include "GL.hpp"

World world;

static Movable *test;

World::World() { }

void World::addSprite(Sprite *sprite) {
    objects.push_back(sprite);
}

void World::update() {
    for (auto sprite  : objects) {
        if (Movable *movable = dynamic_cast<Movable *>(sprite)) movable->update();
        sprite->draw();
    }
}


void World::setup() {
    test = new Movable(Image::cat);
    addSprite(test);
    
    test->setPosition(Point(150, 150));
    test->setSize(Size(200, 260));
        
    Events::onRotation.subscribe(this, [this](const Point &point){
        test->rotation = point.angle();
    });
    
    Events::onMove.subscribe(this, [this](const Point &point){
        test->velocity = point;
    });
}
