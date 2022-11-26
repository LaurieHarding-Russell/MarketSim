cc_test(
  name = "WorldTest",
  size = "small",
  srcs = ["WorldTest.cpp"],
  deps = [
    "//WorldSim:World",
    "@com_google_googletest//:gtest_main"
    ],
)

cc_test(
  name = "InvestorControllerTest",
  size = "small",
  srcs = ["InvestorControllerTest.cpp"],
  deps = [
    "//:MarketController",
    ":CppClient",
    "@com_google_googletest//:gtest_main"
    ],
)

cc_binary(
  name = "mapLook",
  srcs = ["PrettyMapPicture.cpp"],
  deps = [
    "//WorldSim:World"
    ],
)

cc_library(
  name = "CppClient",
  srcs = [
    "CppClient.h"
  ],
  deps = [
    "//Api:api",
    "@boost//:system",
    "@boost//:asio",
    "@boost//:date_time",
  ],
  visibility = ["//visibility:public"]
)
