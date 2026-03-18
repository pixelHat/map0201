CC = clang
CFLAGS = -Wall -Wextra -g

gauss_elimination: gauss-elimination.c
	$(CC) $(CFLAGS) gauss-elimination.c -o gauss_elimination

gauss_elimination_openmp: gauss-elimination.c
	$(CC) $(CFLAGS) -fopenmp gauss-elimination.c -o gauss_elimination_openmp

run_tests: gauss-elimination.c tests.c
	$(CC) $(CFLAGS) -DTESTING gauss-elimination.c tests.c -o run_tests

test: run_tests
	./run_tests

clean:
	rm -f gauss_elimination run_tests
