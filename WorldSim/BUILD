cc_library(
    name = "World",
    srcs = [
        "World.h",
        "World.cpp",
    ],
    deps = [
        "//WorldSim/Map:Map",
        "//WorldSim/Capitalism:Capitalism",
        ":NameGenerator",
        "@json//:json",
        "@boost//:asio",
        "@boost//:beast",
    ],
    visibility = ["//:__subpackages__"]
)


cc_library(
    name = "NameGenerator",
    srcs = [
        "NameGenerator.h"
    ]
)