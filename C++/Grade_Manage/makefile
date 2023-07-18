# use g++ compiler
cc = clang++
# use parent directory for include directives and style
path = ..

# compile with C++ 17 standard
flags = -std=c++17
# compile with all warnings
flags += -Wall
# add to include path
flags += -I $(path)
# instrument for gdb
flags += -g

# build binary executable
link = $(cc) $(flags) -o

# build intermediary .o files
compile = $(cc) $(flags) -c


# test-all: test-all-style test-all-correct
# 	@echo 'ALL PROVIDED TESTS PASSED'

test-all-correct: test-grade test-gradebook
	@echo 'ALL CORRECTNESS TESTS PASSED'

# test-all-style: test-grade-style test-gradebook-style
# 	@echo 'ALL STYLE TESTS PASSED'


test-grade: test-grade-constructor \
            test-grade-toDouble \
            test-grade-toString \
            test-grade-toLetter \
            test-grade-equals \
            test-grade-dividedBy \
            test-grade-plus
	@echo 'TESTING src/grade.cpp:Grade CLASS' \
	&& ./test-grade-constructor \
	&& ./test-grade-toDouble \
	&& ./test-grade-toString \
	&& ./test-grade-toLetter \
	&& ./test-grade-equals \
	&& ./test-grade-dividedBy \
	&& ./test-grade-plus


# test-grade-style : src/grade.cpp inc/grade.h
# 	cpplint --root=$(path) $^


test-gradebook: test-gradebook-add-and-get \
                test-gradebook-add \
                test-gradebook-calcAverage
	@echo 'TESTING src/gradebook.cpp:GradeBook CLASS' \
	&& ./test-gradebook-add-and-get \
	&& ./test-gradebook-add \
	&& ./test-gradebook-calcAverage


# test-gradebook-style : src/gradebook.cpp inc/gradebook.h
# 	cpplint --root=$(path) $^


test-gradebook-add-and-get : bin/test-gradebook-add-and-get.o \
                             bin/gradebook.o \
                             bin/grade.o
	$(link) $@ $^

bin/test-gradebook-add-and-get.o : src/test_gradebook_add_and_get.cpp \
                                   inc/test_gradebook.h
	$(compile) $< -o $@


test-gradebook-add : bin/test-gradebook-add.o \
                     bin/gradebook.o \
                     bin/grade.o
	$(link) $@ $^

bin/test-gradebook-add.o : src/test_gradebook_add.cpp \
                           inc/test_gradebook.h
	$(compile) $< -o $@


test-gradebook-calcAverage : bin/test-gradebook-calcAverage.o \
                             bin/gradebook.o \
                             bin/grade.o
	$(link) $@ $^

bin/test-gradebook-calcAverage.o : src/test_gradebook_calcAverage.cpp \
                                   inc/test_gradebook.h
	$(compile) $< -o $@


test-grade-constructor: src/test_grade_constructor.cpp bin/grade.o
	$(link) $@ $^

test-grade-toDouble: src/test_grade_toDouble.cpp bin/grade.o
	$(link) $@ $^

test-grade-toString: src/test_grade_toString.cpp bin/grade.o
	$(link) $@ $^

test-grade-toLetter: src/test_grade_toLetter.cpp bin/grade.o
	$(link) $@ $^

test-grade-equals: src/test_grade_equals.cpp bin/grade.o
	$(link) $@ $^

test-grade-dividedBy: src/test_grade_dividedBy.cpp bin/grade.o
	$(link) $@ $^

test-grade-plus: src/test_grade_plus.cpp bin/grade.o
	$(link) $@ $^

bin/gradebook.o : src/gradebook.cpp inc/gradebook.h
	$(compile) $< -o $@

bin/grade.o : src/grade.cpp inc/grade.h
	$(compile) $< -o $@

clean:
	rm -f bin/* test-*
