load(
  "@rules_python//python:python.bzl",
  "py_binary", "py_library", "py_test",
)

load("@my_deps//:requirements.bzl", "requirement")

py_binary(
    name = "exampleBot",
    srcs = [
      "TradingBot/trading.py"
    ]
    visibility = ["//visibility:public"]
)
