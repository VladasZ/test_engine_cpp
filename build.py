import os
import shutil

def rm(path):
    if os.path.exists(path):
        shutil.rmtree(path)

import sys
sys.path.append('utils')
import Args
import Build

# Build.cpp()
