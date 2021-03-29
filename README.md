# TestEngine

### Supported platforms:

| macOS            | Linux            | Windows          | iOS Simulator    | iOS Device       | Android          |
|------------------|------------------|------------------|------------------|------------------|------------------|
|[![MAC][MAC1]][TR]|[![Lin][LIN1]][TR]|[![Win][WB1]][WB2]|[![iOS][IOS1]][TR]|[![iOS][IOS2]][TR]|[![AND][AND1]][TR]|


[WB1]: https://ci.appveyor.com/api/projects/status/ukmv5disdy3x00km?svg=true
[WB2]: https://ci.appveyor.com/project/VladasZ/test-engine

[IOS1]: https://travis-matrix-badges.herokuapp.com/repos/VladasZ/test_engine/branches/master/1
[IOS2]: https://travis-matrix-badges.herokuapp.com/repos/VladasZ/test_engine/branches/master/2
[MAC1]: https://travis-matrix-badges.herokuapp.com/repos/VladasZ/test_engine/branches/master/3
[LIN1]: https://travis-matrix-badges.herokuapp.com/repos/VladasZ/test_engine/branches/master/4
[AND1]: https://travis-matrix-badges.herokuapp.com/repos/VladasZ/test_engine/branches/master/5

[TR]: https://travis-ci.com/VladasZ/test_engine

My attempt to create a cross platform, OpenGL based game engine.

Inspired by Cross++: https://github.com/maxon887/Cross .

#### Scene module:
- Objects hierarchy and subobjects
- Objects manipulation: scale, rotation, translation
- Models import using assimp

![Scene](https://i.imgur.com/wndtmaR.png)
- Rigid body physics support using bullet3

![Physics](https://i.imgur.com/CdYa14K.gif)

#### UI module:
- Subviews and layout sustem
- Cross platform touch system with multitouch support
- Rendering custom fonts using FreeType
- Buttons, Sliders, Stack views, Image views and Switches support
- Scroll view support

![Scroll view](https://i.imgur.com/jjkcViF.gif)
