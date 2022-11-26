
java_binary(
    name = "StanBot",
    srcs = [
      "src/StanBot.java",
      ":client"
    ],
    deps = [
        "@maven//:io_swagger_swagger_models",
        "@maven//:io_swagger_swagger_annotations",

        "@maven//:com_squareup_okhttp3_okhttp",
        "@maven//:com_squareup_okio_okio",
        "@maven//:com_squareup_okio_okio_jvm",
        "@maven//:com_squareup_okhttp3_logging_interceptor",
        "@maven//:com_google_code_gson_gson",
        "@maven//:io_gsonfire_gson_fire",
        "@maven//:org_apache_commons_commons_lang3",
        "@maven//:org_threeten_threetenbp",
        "@maven//:com_google_code_findbugs_jsr305",
        "@maven//:javax_servlet_servlet_api",
        "@maven//:javax_validation_validation_api", 
        "@maven//:javax_xml_bind_jaxb_api", 
        "@maven//:javax_ws_rs_jsr311_api",
        "@maven//:javax_annotation_javax_annotation_api",
    ],
    main_class = "stanbot.StanBot",
)

# Swagger
load("@io_bazel_rules_openapi//openapi:openapi.bzl", "openapi_gen")

# openapi_gen only supports jvm languages. You can get around this with macro's that define the outputs... but its a little messy.
openapi_gen(
  name = "client",
  language = "java",
  spec = "@market_sim//:investorSwagger.yaml",
  system_properties = {
    "apiTests": "false",
    # "apiDocs": "false",
    "modelTests": "false",
    # "modelDocs": "false",
    # "SupportingFiles": "false",
  }
)
