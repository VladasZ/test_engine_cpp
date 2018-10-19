import os
import shutil

def rm(path):
    if os.path.exists(path):
        shutil.rmtree(path)

import git


if not os.path.exists("utils"):
        git.Git(".").clone("https://github.com/vladasz/utils")

import sys
sys.path.append('utils')
import Args
import Build

# Build.cpp()
