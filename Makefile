
FILE=./main.cpp

.PHONY: compile
compile: clean
	g++ -std=c++17 $(FILE)

.PHONY: run
run: compile
	./a.out

.PHONY: clean
clean:
	rm -rf ./*.out

.PHONY: tmpl
tmpl:
	cp -f ./main.cpp ./bk.cpp
	cp -f ./tmpl.cpp ./main.cpp