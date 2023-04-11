load("@bazel_tools//tools/build_defs/repo:http.bzl", "http_archive")

# Google Tests
# https://github.com/google/googletest

http_archive(
	name = "com_google_googletest",
	urls = ["https://github.com/google/googletest/archive/8fa9461cc28e053d66f17132808d287ae51575e2.zip"],
	strip_prefix = "googletest-8fa9461cc28e053d66f17132808d287ae51575e2",
)

# Hedron's Compile Commands Extractor for Bazel
# https://github.com/hedronvision/bazel-compile-commands-extractor
# For easy mode usage bazel(isk) run @hedron_compile_commands//refresh_all
http_archive(
    name = "hedron_compile_commands",

    # Replace the commit hash in both places (below) with the latest, rather than using the stale one here.
    # Even better, set up Renovate and let it do the work for you (see "Suggestion: Updates" in the README).
    url = "https://github.com/hedronvision/bazel-compile-commands-extractor/archive/26cf0a8a2d117ec2f92e01ed1b7ece4dd8940fcd.tar.gz",
    strip_prefix = "bazel-compile-commands-extractor-26cf0a8a2d117ec2f92e01ed1b7ece4dd8940fcd",
	sha256 = "be914b31eaf772ad99455b749e88b2326b45b4337d803c85fd211be001c951d6",
    # When you first run this tool, it'll recommend a sha256 hash to put here with a message like: "DEBUG: Rule 'hedron_compile_commands' indicated that a canonical reproducible form can be obtained by modifying arguments sha256 = ..."
)

load("@hedron_compile_commands//:workspace_setup.bzl", "hedron_compile_commands_setup")
hedron_compile_commands_setup()