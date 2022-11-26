## Creating a trading bot

### Creating a trading bot (using bazel).
The market sim exports a swagger controller.yaml.


To generate a client from the code you can use the open ai rules by adding this to your WORKSPACE
```
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
```

and




### API
See the swagger.yaml file for the api.
vscode has a tool for viewing it.

### That your aloud to use. Reseting the world is cheating ;)