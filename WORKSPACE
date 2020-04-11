load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

http_archive(
    name = "com_github_nelhage_rules_boost",
    urls = ["https://github.com/nelhage/rules_boost/archive/6d6fd834281cb8f8e758dd9ad76df86304bf1869.zip"],
    strip_prefix = "rules_boost-6d6fd834281cb8f8e758dd9ad76df86304bf1869",
    sha256 = "b4d498a21e9d90ec65720ee3ae4dcbc2f1ce245b2866242514cebbc189d2fc14"
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