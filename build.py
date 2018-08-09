import os
import sys
sys.path.append('config')
from utils import Shell
from utils import Setup
from utils import Status
from utils import Arguments

make = Arguments.has('--make')

build_folder = 'make' if make else 'build'

Setup.setupConan()

if not os.path.exists(build_folder):
    os.makedirs(build_folder)

os.chdir(build_folder)

if make:
	Shell.run([
	'conan', 'install', '..', 
	'-scompiler=gcc', 
	'-scompiler.version=6.3gdf', 
	'-scompiler.libcxx=libstdc++', 
	'-bmissing'
	])	
	Shell.run(['cmake', '..', '-G', 'Unix Makefiles'])
else:
	Shell.run(['conan', 'install', '..'])
	Shell.run(['cmake', '..', '-G', Status.compiler()])


