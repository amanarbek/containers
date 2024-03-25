CPP =  g++ --std=c++20 -Wall -Werror -Wextra

OS = $(shell uname)

ifeq ($(OS), Darwin)
	LIBFLAGS = -lm -lgtest -lgtest_main -lpthread
	LK = leaks --atExit -- ./test.out
	PRINT = open
else
	LIBFLAGS = -lgtest -lgtest_main -pthread
	LK = valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose ./test.out
	PRINT = xdg-open
endif

all: test

compile:
	$(CPP) ./tests/test_scheme.cc $(LIBFLAGS) -o test.out

test: compile
	./test.out


style_check:
	@cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config *.h
	@cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.h
	clang-format -n ./tests/*.cc
	@rm -rf .clang-format

gcov_report:
	$(CPP) --coverage ./tests/test_scheme.cc $(LIBFLAGS) -lgcov  -o test.out
	./test.out
	@mkdir -p report
	@gcovr --html --html-details -o ./report/report.html
	@$(PRINT) ./report/report.html

leaks: compile
	$(LK)

clean:
	rm -rf *.out report *gcda *.gcno

