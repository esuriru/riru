add_requires("glad")
add_requires("glfw")

target("riru")
    set_kind("static")

    add_includedirs("include", { public = true })
    add_files("src/core/*.cpp")
    add_files("src/gfx/*.cpp")

    add_packages("glad", { public = true })
    add_defines("GLFW_INCLUDE_NONE")
    add_packages("glfw", { public = true })

