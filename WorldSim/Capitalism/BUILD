cc_library(
    name = "Capitalism",
    srcs = [
        "Company.h",
        "Company.cpp",
        "Investor.cpp",
        "Investor.h",
        "Stock.h",
        "Stock.cpp",
        "Consumer.h",
        "Consumer.cpp"
    ],
    deps = [
        "//WorldSim/Humanity:Humanity",
        "//WorldSim/Deserializable:Deserializable",
        "@boost//:asio",
        "@boost//:beast",
    ],
    visibility = ["//:__subpackages__"]
)