outputDir = build
inputDir = src
testOutputDir = build-test
testDir = test

build: create_outputDir main.o read_csv.o
	gcc -o $(outputDir)/app $(outputDir)/main.o $(outputDir)/read_csv.o

create_outputDir:
	mkdir -p $(outputDir)

read_csv.o: src/read_csv.h
	gcc -c $(inputDir)/read_csv.c -o $(outputDir)/read_csv.o

main.o: main.c
	gcc -c main.c -o $(outputDir)/main.o

.PHONY : clean_build
clean_build:
	make clean
	make

.PHONY : clean
clean:
	rm -rf $(outputDir)

.PHONY : run
run: build
	./$(outputDir)/app

#################
# Test commands #
#################
build_test: create_testOutputDir create_outputDir test.o read_csv.o
	gcc -o $(testOutputDir)/app $(testOutputDir)/test.o $(outputDir)/read_csv.o

create_testOutputDir: create_outputDir
	mkdir -p $(testOutputDir)

test.o: test/test.c
	gcc -c $(testDir)/test.c -o $(testOutputDir)/test.o

test: build_test
	./$(testOutputDir)/app

.PHONY : clean_build_test
clean_build_test:
	make clean_test
	make test

.PHONY : clean_test
clean_test:
	rm -rf $(testOutputDir)