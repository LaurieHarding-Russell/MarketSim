cc_binary(
    name = "Market",
    srcs = [
        "MarketSim.cpp",
        "MarketController.h",
        "InvestorController.h",
    ],
    deps = [
        "//WorldSim:World",
        "@boost//:system",
        "@boost//:asio",
        "@boost//:date_time",
        "@boost//:uuid",
        "@com_github_served//:served"
    ],
    visibility = ["//visibility:public"]
)