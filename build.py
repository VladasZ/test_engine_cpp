import os
import sys
sys.path.append('config')
from utils import Shell
from utils import Setup
from utils import Status

#Setup.reset()

print('start')

if not os.path.exists('build'):
            os.makedirs('build')

#for package in ['conan', 'cmake']:
#	Setup.checkAndInstall(package)

if not Status.conanIsSetUp():
	Setup.setupConan()

Setup.runConan()

os.chdir('build')
Shell.run(['cmake', '..', '-G', Status.compiler()])

print('ok')
