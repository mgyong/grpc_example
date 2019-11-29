workspace(name = "grpc_test")

load("@bazel_tools//tools/build_defs/repo:git.bzl", "git_repository")
load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

git_repository(
name = "com_github_grpc_grpc",
remote = "https://github.com/grpc/grpc",
commit = "bd0aa9a600a13cc988c6ebfd12deab8d1abcf171",
)

http_archive(
     name = "com_google_protobuf",
     strip_prefix = "protobuf-master",
     urls = ["https://github.com/protocolbuffers/protobuf/archive/master.zip"],
)

load("@com_github_grpc_grpc//bazel:grpc_deps.bzl", "grpc_deps")
grpc_deps()

load("@com_github_grpc_grpc//bazel:grpc_extra_deps.bzl", "grpc_extra_deps")
grpc_extra_deps()

load("@com_google_protobuf//:protobuf_deps.bzl", "protobuf_deps")
protobuf_deps()