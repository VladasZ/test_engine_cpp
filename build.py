import os
import sys
sys.path.append('config/utils')
import File
import Args
import Conan
import Cmake
import Shell
import System
import Android

Cmake.setup()
Conan.setup()

build_folder = File.build_folder()

if Args.rmbuild:
	File.rm(build_folder)

if Args.android:
	Android.setup()
	
File.mkdir(build_folder)
File.cd(build_folder)

Conan.run()
Cmake.run()

if Args.make:
	Shell.run(['make'])
