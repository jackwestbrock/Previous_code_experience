cc = g++  # use g++ compiler

root = ..

flags = -std=c++17  # compile with C++ 17 standard
flags += -Wall      # compile with all warnings
flags += -g         # compile with debugger instrumentation
flags += -I $(root) #add search path to header files

link = $(cc) $(flags) -o  # final linked build to binary executable

compile = $(cc) $(flags) -c  # compilation to intermediary .o files


parse-scores.o : parse_scores.cpp parse_scores.h
	$(compile) $< -o $@

parse-scores-style : parse_scores.cpp parse_scores.h
	cpplint --root=$(root) $^

test-get-id : test_get_id.cpp parse-scores.o
	$(link) $@ $^

test-get-grade : test_get_grade.cpp parse-scores.o
	$(link) $@ $^

test-get-grade-count : test_get_grade_count.cpp parse-scores.o
	$(link) $@ $^

test-get-max-grade : test_get_max_grade.cpp parse-scores.o
	$(link) $@ $^

test : test-get-id test-get-grade test-get-grade-count test-get-max-grade
	./test-get-id
	./test-get-grade
	./test-get-grade-count
	./test-get-max-grade

clean:
	$(RM) *.o test-get-grade test-get-grade-count test-get-id \
        test-get-max-grade
