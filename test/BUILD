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
    "//:InvestorController",
    "//TradingBot:CppClient",
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