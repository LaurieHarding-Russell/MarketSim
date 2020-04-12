load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_nelhage_rules_boost",
    urls = ["https://github.com/nelhage/rules_boost/archive/f32cc980e4dba651594fe364696ceb8b931fcb2d.zip"],
    strip_prefix = "rules_boost-f32cc980e4dba651594fe364696ceb8b931fcb2d",
    sha256 = "b320a69fa414fa5bd6ea9291e8ff5aa7e1bbb9aad6a5c6f23b72c2d7a8ae8fd5"
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
    strip_prefix = "json-456478b3c50d60100dbb1fb9bc931f370a2c1c28",
    urls = [
        "https://github.com/nlohmann/json/archive/456478b3c50d60100dbb1fb9bc931f370a2c1c28.tar.gz",
    ],
    build_file_content = """
cc_library(
    name = "json",
    hdrs = ["single_include/nlohmann/json.hpp"],
    visibility = ["//visibility:public"],
)
"""
)


# Trading bot dependencies
load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")

git_repository(
    name = "rules_python",
    remote = "https://github.com/bazelbuild/rules_python.git",
    commit = "9d68f24659e8ce8b736590ba1e4418af06ec2552",
)


load("@rules_python//python:pip.bzl", "pip_repositories")
pip_repositories()

load("@rules_python//python:pip.bzl", "pip_import")
pip_import(
   name = "my_deps",
   requirements = "//TradingBot:requirements.txt",
)