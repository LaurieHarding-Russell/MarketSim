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
    requirement("requests")
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

# Swagger
load("@io_bazel_rules_openapi//openapi:openapi.bzl", "openapi_gen")

openapi_gen(
  name = "investor-client-src",
  language = "python",
  spec = "market_sim:investorSwagger",
  visibility = ["//visibility:public"]
)