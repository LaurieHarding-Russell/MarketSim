cc_binary(
    name = "Market",
    srcs = [
        "MarketSim.cpp",
        "MarketController.h",
    ],
    deps = [
        "World",
        "@boost//:system",
        "@boost//:asio",
        "@boost//:date_time",
        "@boost//:uuid",
        "@com_github_served//:served"
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "World",
    srcs = [
        "MarketController.h",
        "World.h",
        "World.cpp",
        "Company.h",
        "Employee.h"
    ],
    deps = [
        "@json//:json"
    ]
)