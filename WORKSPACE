load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

_RULES_BOOST_COMMIT = "652b21e35e4eeed5579e696da0facbe8dba52b1f"
http_archive(
    name = "com_github_nelhage_rules_boost",
    sha256 = "c1b8b2adc3b4201683cf94dda7eef3fc0f4f4c0ea5caa3ed3feffe07e1fb5b15",
    strip_prefix = "rules_boost-%s" % _RULES_BOOST_COMMIT,
    urls = [
        "https://github.com/nelhage/rules_boost/archive/%s.tar.gz" % _RULES_BOOST_COMMIT,
    ],
)

load("@com_github_nelhage_rules_boost//:boost/boost.bzl", "boost_deps")
boost_deps()


http_archive(
    name = "com_github_served",
    urls = ["https://github.com/meltwater/served/archive/8ef95d72692ef1f392fc0a44a6dad4235386ac9d.zip"],
    strip_prefix = "served-8ef95d72692ef1f392fc0a44a6dad4235386ac9d",
    sha256 = "fb97bba7b99125bd12e821ad499cc939d25ccd19614b7ea3a8bb8392b5fbb115"
)

http_archive(
    name = "json",
    strip_prefix = "json-3.11.2",
    urls = [
        "https://github.com/nlohmann/json/archive/refs/tags/v3.11.2.tar.gz",
    ],
    sha256 = "d69f9deb6a75e2580465c6c4c5111b89c4dc2fa94e3a85fcd2ffcd9a143d9273",
    build_file_content = """
cc_library(
    name = "json",
    hdrs = ["single_include/nlohmann/json.hpp"],
    visibility = ["//visibility:public"],
)
"""
)

load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

RULES_OPEN_API_COMMIT = "f48152c4a204b1b9c59d726579ce416aa5d08732"
RULES_OPEN_API_SHA256 = "1d6bdad4608e99708cc7818ffdca9d5ae4c74857d002f19330ae8a028868f258"

http_archive(
    name = "io_bazel_rules_openapi",
    strip_prefix = "rules_openapi-%s" % RULES_OPEN_API_COMMIT,
    url = "https://github.com/meetup/rules_openapi/archive/%s.tar.gz" % RULES_OPEN_API_COMMIT,
    sha256 = RULES_OPEN_API_SHA256
)

load("@io_bazel_rules_openapi//openapi:openapi.bzl", "openapi_repositories")
openapi_repositories(
    codegen_cli_version = "5.0.0",
    codegen_cli_sha256 = "839fade01e54ce1eecf012b8c33adb1413cff0cf2e76e23bc8d7673f09626f8e",
    codegen_cli_provider = "openapi"
)

# Tests
http_archive(
  name = "com_google_googletest",
  urls = ["https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip"],
  strip_prefix = "googletest-609281088cfefc76f9d0ce82e1ff6c30cc3591e5",
  sha256 = "5cf189eb6847b4f8fc603a3ffff3b0771c08eec7dd4bd961bfd45477dd13eb73"
)






# UI Dependencies
http_archive(
    name = "build_bazel_rules_nodejs",
    sha256 = "c29944ba9b0b430aadcaf3bf2570fece6fc5ebfb76df145c6cdad40d65c20811",
    urls = ["https://github.com/bazelbuild/rules_nodejs/releases/download/5.7.0/rules_nodejs-5.7.0.tar.gz"],
)
load("@build_bazel_rules_nodejs//:repositories.bzl", "build_bazel_rules_nodejs_dependencies")

#Vendoring Node and Yarn.
http_archive(
    name = "vendored_node_linux_amd64",
    build_file_content = """exports_files(["bin/node"])""",
    sha256 = "cc9c3eed21755b490e5333ccab208ce15b539c35f64a764eeeae77c58746a7ff",
    strip_prefix = "node-v15.0.1-linux-x64",
    urls = ["https://nodejs.org/dist/v15.0.1/node-v15.0.1-linux-x64.tar.xz"],
)

http_archive(
    name = "vendored_node_darwin_amd64",
    build_file_content = """exports_files(["bin/node"])""",
    sha256 = "78571df5b35d3ec73d7543332776bcb8cab3bc0e3abd12b1440fbcd01c74c055",
    strip_prefix = "node-v15.0.1-darwin-x64",
    urls = ["https://nodejs.org/dist/v15.0.1/node-v15.0.1-darwin-x64.tar.xz"],
)


register_toolchains("//toolchains:all")

build_bazel_rules_nodejs_dependencies()

load("@build_bazel_rules_nodejs//:index.bzl", "npm_install")

# fixme pnpm with rules_jsload("@io_bazel_rules_openapi//openapi:openapi.bzl", "openapi_repositories")
openapi_repositories(
    codegen_cli_version = "5.0.0",
    codegen_cli_sha256 = "839fade01e54ce1eecf012b8c33adb1413cff0cf2e76e23bc8d7673f09626f8e",
    codegen_cli_provider = "openapi"
)
npm_install(
    name = "npm_deps",
    package_json = "//:package.json",
    package_lock_json = "//:package-lock.json",
)