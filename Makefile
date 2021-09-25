
FILE=./main.cpp

.PHONY: run
run: compile
	./a.out < input.txt

.PHONY: arg
arg: compile
	./a.out

.PHONY: compile
compile: clean
	clang++ -std=c++17 $(FILE)

.PHONY: clean
clean:
	rm -rf ./*.out

.PHONY: tmpl
tmpl:
	cp -f ./main.cpp ./bk.cpp
	cp -f ./tmpl.cpp ./main.cpp

.PHONY: test
test:
	bazelisk test --test_output=all //test:lib_test