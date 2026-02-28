target("ui_lib")
    set_kind("static")
    -- add_packages("rapidfuzz", "glaze", "cli11")
    add_includedirs(
        ".",
        "./input",
        "./basic/text",
        "../cpp_utils/",
        "../cpp_utils/logs",
        "../cpp_utils/system",
        "../cpp_utils/stl",
        "../cpp_utils/meta",
        "../cpp_utils/filesystem",
        "../cpp_utils/misc"
    )
    add_deps("cpp_utils_lib")
    add_files("**.cpp|Main.cpp")
    add_headerfiles("**.hpp")
