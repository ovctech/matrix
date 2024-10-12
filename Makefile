CC = g++
CPPFLAGS = -lgtest -std=c++17
COVERAGE = -fno-elide-constructors
CHECKFLAGS = -Wall -Werror -Wextra
SRC = s21_matrix_oop.cc
TEST = s21_tests.cc

all: test gcov_report

test: clean
	@${CC} ${TEST} ${SRC} ${CHECKFLAGS} ${CPPFLAGS} -o test
	@./test

%.o: %.cc
	@${CC} -std=c++17 ${CHECKFLAGS} -c $^

%.a: %.o
	@ar rcs $@ $^
	@ranlib $@

clean:
	@/bin/rm -rf *.o *.a test *.gcno *gcda report *.info test *.out

gcov_report: ${TEST} ${SRC}
	@$(CC) --coverage $^ ${COVERAGE} ${CPPFLAGS} ${CHECKFLAGS} -o test
	@./test
	@lcov -t "test" -o test.info --no-external -c -d ./
	@genhtml -o report test.info
	@open report/index.html

cppcheck:
	cppcheck --enable=all --suppress=missingIncludeSystem . *.cc

check-style:
	@find . -type f \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -print0 | xargs -0 clang-format -n -style=Google

set-style:
	@find . -type f \( -name "*.h" -o -name "*.c" -o -name "*.cc" \) -print0 | xargs -0 clang-format -i -style=Google

cpp:
	@cppcheck —enable=all —suppress=missingIncludeSystem ./$(CPP_FILES)
	@cppcheck —enable=all —suppress=missingIncludeSystem ./$(HEADERS)

prod: cpp set-style check-style test

leaks: test
	CK_FORK=no leaks --atExit -- ./test

valgrind: test
	valgrind -v --track-origins=yes --tool=memcheck --leak-check=full ./test
