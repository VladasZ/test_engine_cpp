set_project("Test Engine")
set_version("1.0.0")

set_languages("c++23")

if is_plat("windows") then
    add_defines("NOMINMAX")
    add_defines("WIN32_LEAN_AND_MEAN")
    add_syslinks("advapi32")
end

-- add_requires("rapidfuzz", "cli11", "doctest", "cpr", "glaze")
add_rules("plugin.compile_commands.autoupdate", { outputdir = "build" })

includes("source/cpp_utils")
includes("source/ui")
includes("source/scene")
includes("source/test_engine")
includes("source/test_engine_test")
