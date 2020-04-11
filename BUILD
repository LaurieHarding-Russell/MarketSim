cc_binary(
    name = "Market",
    srcs = [
        "MarketSim.cpp",
        "MarketController.h",
        "World.h",
        "Company.h",
        "Employee.h"
    ],
    deps = [
        "@boost//:system",
        "@boost//:asio",
        "@boost//:date_time",
        "@boost//:uuid",
        "@com_github_served//:served",
    ],
    visibility = ["//visibility:public"]
)