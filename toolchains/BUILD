# FIXME, eager fetching all. Should fix. Copied from
# https://github.com/bazelbuild/rules_nodejs/blob/stable/examples/vendored_node_and_yarn/toolchains/BUILD.bazel
load("@rules_nodejs//nodejs:toolchain.bzl", "node_toolchain")

[
    toolchain(
        name = "node15_%s_toolchain" % os,
        exec_compatible_with = [
            "@platforms//os:" + os,
            "@platforms//cpu:x86_64",
        ],
        toolchain = ":node_" + os,
        toolchain_type = "@rules_nodejs//nodejs:toolchain_type",
    )
    for os in [
        "linux",
        "macos"
    ]
]

node_toolchain(
    name = "node_linux",
    target_tool = "@vendored_node_linux_amd64//:bin/node",
)

node_toolchain(
    name = "node_macos",
    target_tool = "@vendored_node_darwin_amd64//:bin/node",
)