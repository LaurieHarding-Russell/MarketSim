load("@npm_deps//http-server:index.bzl", "http_server")
load("@npm_deps//@bazel/rollup:index.bzl", "rollup_bundle")
load("@npm_deps//@bazel/typescript:index.bzl", "ts_project")
load("@npm_deps//html-insert-assets:index.bzl", "html_insert_assets")
load("@build_bazel_rules_nodejs//:index.bzl", "pkg_web")
load("@npm_deps//less:index.bzl", "lessc")



ts_project(
    name = "app",
    srcs = glob(["**/*.ts"]),
    declaration = True,
    deps = [
        "@npm_deps//tslib",
        "@npm_deps//ol",
    ]
)

rollup_bundle(
    name = "bundle",
    entry_point = ":main.ts",
    config_file = "rollup.config.js",
    deps = [":app",
        "@npm_deps//@rollup/plugin-commonjs",
        "@npm_deps//@rollup/plugin-node-resolve",
        "@npm_deps//ol",
        "@npm_deps//tslib",
    ],
)

lessc(
    name = "styles",
    outs = [
        "base.css",
        "base.css.map",
    ],
    args = [
        "$(execpath base.less)",
        "$(execpath base.css)",
        "--silent",
        "--source-map",
    ],
    data = [
        "base.less"
    ],
)


_ASSETS = [
    ":bundle",
     ":styles",
]

html_insert_assets(
    name = "inject_tags",
    outs = ["index.html"],
    args = [
        "--out=$@",
        "--html=$(execpath :index.tmpl.html)",
        "--roots=$(RULEDIR)",
        "--assets",
    ] + ["$(execpaths %s)" % a for a in _ASSETS],
    data = [":index.tmpl.html"] + _ASSETS
)

pkg_web(
    name = "package",
    srcs = [":inject_tags"] + _ASSETS
)

http_server(
    name = "server",
    data = [":package"],
    templated_args = [
        "-p 4200", 
        "-P http://localhost:8080",
        "adminUI/package",
    ],
)