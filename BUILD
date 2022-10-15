cc_binary(
    name = "Market",
    srcs = [
        "MarketSim.cpp"
    ],
    deps = [
        ":MarketController",
    ],
    visibility = ["//visibility:public"]
)

cc_library(
    name = "MarketController",
    srcs = [
        "InvestorController.h",
        "MarketController.h",
        "Transformers.h",
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


# Other
load("@rules_python//python:pip.bzl", "compile_pip_requirements")

compile_pip_requirements(
    name = "requirements",
    extra_args = ["--allow-unsafe"],
    requirements_in = "requirements.in",
    requirements_txt = "requirements_lock.txt",
)