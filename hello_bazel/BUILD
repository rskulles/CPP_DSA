cc_library(
	name= "my-lib",
	srcs = ["funcs.cpp"],
	hdrs = ["funcs.hpp"],
)

cc_binary(
	name = "hello-bazel",
	srcs = ["main.cpp"]
)

cc_test(
	name = "hello-test",
	size = "small",
	srcs = ["main_test.cpp"],
	deps = ["@com_google_googletest//:gtest_main", ":my-lib"],
)
