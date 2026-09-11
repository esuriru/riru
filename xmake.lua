set_project("riru")

set_languages("c++20")
add_rules("mode.debug")
add_rules("plugin.compile_commands.autoupdate", {outputdir = "build"})

includes("riru")
includes("riruka")

set_toolchains("llvm")
