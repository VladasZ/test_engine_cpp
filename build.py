import os
import sys
sys.path.append('config/utils')
import File
import Args
import Conan
import Cmake
import Shell
import Compiler

Conan.setup()

make = Args.has('--make')

build_folder = File.build_folder()

File.rm(build_folder)
File.mkdir(build_folder)
File.cd(build_folder)

Conan.run(Compiler.get())
Cmake.run(Cmake.make)

if make:
	Shell.run(['make'])
