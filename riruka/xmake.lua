target("console")
    set_kind("binary")

    add_deps("riru")

    add_files("src/*.cpp")