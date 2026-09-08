target("riru")
    set_kind("static")

    add_includedirs("include", { public = true })
    add_files("src/core/*.cpp")
