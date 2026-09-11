set_project("riru")

set_languages("c++20")
add_rules("mode.debug")

includes("riru")
includes("riruka")

set_toolchains("llvm")
