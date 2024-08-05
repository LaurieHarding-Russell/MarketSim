cc_library(
    name = "Map",
    srcs = [
        "Map.h",
        "Map.cpp",
        "Coordinate.cpp",
        "Coordinate.h",
        "Tangible.h",
        "MapUtil.h",
    ],
    visibility = ["//:__subpackages__"]
)

cc_test(
  name = "MapTest",
  size = "small",
  srcs = ["MapTest.cpp"],
  deps = [
    ":Map",
    "@com_google_googletest//:gtest_main"
    ],
)