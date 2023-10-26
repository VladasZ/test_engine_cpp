# [DEPRECATED]
In favor of Rust:crab: : https://github.com/vlasdasz/test_engine


# TestEngine

### Supported platforms:

[MAC1]: https://github.com/vladasz/test_engine/actions/workflows/mac.yml/badge.svg
[LIN1]: https://github.com/vladasz/test_engine/actions/workflows/linux.yml/badge.svg
[WIN1]: https://github.com/vladasz/test_engine/actions/workflows/windows.yml/badge.svg
[IOSS1]: https://github.com/vladasz/test_engine/actions/workflows/ios_sim.yml/badge.svg
[IOSD1]: https://github.com/vladasz/test_engine/actions/workflows/ios_dev.yml/badge.svg

[LMAC]: https://github.com/VladasZ/test_engine/actions/workflows/mac.yml
[LLIN]: https://github.com/VladasZ/test_engine/actions/workflows/linux.yml
[LWIN]: https://github.com/VladasZ/test_engine/actions/workflows/windows.yml
[LIOSS]: https://github.com/VladasZ/test_engine/actions/workflows/ios_sim.yml
[LIOSD]: https://github.com/VladasZ/test_engine/actions/workflows/ios_dev.yml

[![MAC][MAC1]][LMAC]
[![Lin][LIN1]][LLIN]
[![Win][WIN1]][LWIN]
[![IOSS][IOSS1]][LIOSS]
[![IOSD][IOSD1]][LIOSD]



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
