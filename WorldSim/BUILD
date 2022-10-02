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