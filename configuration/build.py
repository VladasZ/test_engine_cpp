import os
from utils import Guide
from utils import Config
from utils import Executor
from CmakeHelper import CmakeHelper

if not os.path.exists("build"):
    os.makedirs("build")

CmakeHelper.createIncludeDirsFile("build\\Include.cmake", ".\\source")
CmakeHelper.createIncludeDirsFile("build\\EngineInclude.cmake", ".\\source\\Engine", "../../")
CmakeHelper.createIncludeDirsFile("build\\ToolsInclude.cmake", ".\\source\\Tools", "../../")

guide = Guide('..','build')
guide.make_build()
guide.cd_build()

cfg = Config()
ide = cfg.get_ide()

Executor.run(['conan', 'install', '-g', 'cmake_multi', guide.root_dir ,'--build=outdated', '-s', 'build_type=Debug'])
Executor.run(['conan', 'install', '-g', 'cmake_multi', guide.root_dir ,'--build=outdated', '-s', 'build_type=Release'])
Executor.run(['cmake', guide.root_dir, '-G', ide])