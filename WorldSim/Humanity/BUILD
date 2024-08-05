cc_library(
    name = "Humanity",
    srcs = [
        "Person.h",
        "Person.cpp",
        "Building.h",
        "Building.cpp",
        "ProductType.h",
    ],
    deps = [
        "//WorldSim/Map:Map",
        "@boost//:asio",
        "@boost//:beast",
    ],
        visibility = ["//:__subpackages__"]
)


cc_test(
  name = "MapTest",
  size = "small",
  srcs = ["MapTest.cpp"],
  deps = [
    ":Humanity",
    "@com_google_googletest//:gtest_main"
    ],
)