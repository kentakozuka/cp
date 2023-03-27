cc_test(
    name = "bellman_ford",
    size = "small",
    srcs = glob([
        "bellman_ford_test.cpp",
    ]),
    deps = [
        "//lib:bellman_ford",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "mod",
    size = "small",
    srcs = glob([
        "mod_test.cpp",
    ]),
    deps = [
        "//lib:mod",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "pow",
    size = "small",
    srcs = glob([
        "pow_test.cpp",
    ]),
    deps = [
        "//lib:pow",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "prime_number",
    size = "small",
    srcs = glob([
        "prime_number_test.cpp",
    ]),
    deps = [
        "//lib:prime_number",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "union_find",
    size = "small",
    srcs = glob([
        "union_find_test.cpp",
    ]),
    deps = [
        "//lib:union_find",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "kruscal_test",
    size = "small",
    srcs = glob(["kruscal_test.cpp"]),
    deps = [
        "//lib:kruscal",
        "//lib:union_find",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "combination_test",
    size = "small",
    srcs = glob(["combination_test.cpp"]),
    deps = [
        "//lib:combination",
        "@com_google_googletest//:gtest_main",
    ],
)

cc_test(
    name = "segment_tree_test",
    size = "small",
    srcs = glob(["segment_tree_test.cpp"]),
    deps = [
        "//lib:segment_tree",
        "@com_google_googletest//:gtest_main",
    ],
)
