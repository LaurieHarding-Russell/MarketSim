load(
  "@rules_python//python:python.bzl",
  "py_binary", "py_library", "py_test",
)

load("@my_deps//:requirements.bzl", "requirement")

py_library(
  name = "PythonClient",
  srcs = [
    "PythonClient.py"
  ],
  deps = [
    "requests"
  ],
  visibility = ["//visibility:public"]
)

py_binary(
    name = "exampleBot",
    srcs = [
      "trading.py"
    ],
    deps = [
      ":PythonClient"
    ],
    visibility = ["//visibility:public"]
)
