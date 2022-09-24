cc_library(
    name = "World",
    srcs = [
        "World.h",
        "World.cpp",
    ],
    deps = [
        ":Capitalism",
        ":NameGenerator",
        "@json//:json",
        "@boost//:asio",
        "@boost//:beast",
    ],
    visibility = ["//:__pkg__"]
)

cc_library(
    name = "Capitalism",
    srcs = [
        "Company.h",
        "Company.cpp",
        "Investor.cpp",
        "Investor.h",
        "Stock.h",
        "Stock.cpp",
    ],
    deps = [
        ":Person",
        "@json//:json",
        "@boost//:asio",
        "@boost//:beast",
    ]
)

cc_library(
    name = "Person",
    srcs = [
        "Person.h",
        "Person.cpp",
    ],
    deps = [
        "@json//:json",
        "@boost//:asio",
        "@boost//:beast",
    ]
)

cc_library(
    name = "NameGenerator",
    srcs = [
        "NameGenerator.h"
    ]
)