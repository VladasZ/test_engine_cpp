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

World world;

static Sprite *test;

World::World() {
    Events::everyFrame.subscribe([this]() {
        this->update();
    });
}

void World::addSprite(Sprite *sprite) {
    objects.push_back(sprite);
}

void World::update() {
    
    test->setPosition(test->position() + Point(0.1, 0.1));
    
    for (auto movable : movableObjects) movable->update();
    for (auto sprite  : objects)        sprite->draw();
}


void World::setup() {
    test = new Sprite(Image::cat);
    addSprite(test);
    
    test->setSize(Size(200, 200));
}
