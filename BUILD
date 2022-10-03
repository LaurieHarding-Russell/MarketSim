cc_binary(
    name = "Market",
    srcs = [
        "MarketSim.cpp"
    ],
    deps = [
        ":MarketController",
        ":InvestorController",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "InvestorController",
    srcs = [
        "InvestorController.h",
    ],
    deps = [
        "//Api:api",
        "//WorldSim:World",
        "@boost//:system",
        "@boost//:asio",
        "@boost//:date_time",
        "@boost//:uuid",
        "@com_github_served//:served"
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "MarketController",
    srcs = [
        "MarketController.h",
    ],
    deps = [
        "//Api:api",
        "//WorldSim:World",
        "@boost//:system",
        "@boost//:asio",
        "@boost//:date_time",
        "@boost//:uuid  ",
        "@com_github_served//:served"
    ],
    visibility = ["//visibility:public"]
)

load("@rules_python//python:pip.bzl", "compile_pip_requirements")

compile_pip_requirements(
    name = "requirements",
    extra_args = ["--allow-unsafe"],
    requirements_in = "requirements.in",
    requirements_txt = "requirements_lock.txt",
)