
FILE=./main.cpp

.PHONY: run
run: compile
	./a.out < input.txt

.PHONY: arg
arg: compile
	./a.out

.PHONY: compile
compile: clean
	/usr/local/bin/g++-11 \
		-std=gnu++17 \
		-D_GLIBCXX_DEBUG \
		$(FILE)

.PHONY: clean
clean:
	rm -rf ./*.out

.PHONY: tmpl
tmpl:
	cp -f ./main.cpp ./bk.cpp
	cp -f ./tmpl.cpp ./main.cpp

.PHONY: test
test:
	BAZEL_USE_CPP_ONLY_TOOLCHAIN=1
	BAZEL_CXXOPTS="-std=gnu++17"
	bazelisk test \
		--action_env \
		CC=/usr/local/bin/g++-11 \
		--test_output=all \
		//test/...