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

os.chdir('build')

Shell.run(['conan', 'install', '..'])
Shell.run(['cmake', '..', '-G', Status.compiler()])

print('ok')
