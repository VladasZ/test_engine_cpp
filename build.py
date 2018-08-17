import os
import sys
sys.path.append('config/utils')
import File
import Args
import Conan
import Cmake
import Shell

Cmake.setup()
Conan.setup()

print(os.environ['CXX'])

build_folder = File.build_folder()

if Args.rmbuild:
	File.rm(build_folder)
	
File.mkdir(build_folder)
File.cd(build_folder)

Conan.run()
Cmake.run()

if Args.make:
	Shell.run(['make'])
