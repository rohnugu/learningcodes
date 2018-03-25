OBJS = matrix.o matrix_main.o smatrix.o smatrix_main.o kmp_example.o
TARGET = matrix smatrix kmp_example

all: $(TARGET)

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

matrix_main.o: matrix_main.c matrix.h
	$(CC) -c matrix_main.c

matrix: matrix.o matrix_main.o
	$(CC) -o matrix matrix.o matrix_main.o

smatrix.o: smatrix.c smatrix.h
	$(CC) -c smatrix.c

smatrix_main.o: smatrix_main.c smatrix.h
	$(CC) -c smatrix_main.c

smatrix: smatrix.o smatrix_main.o
	$(CC) -o smatrix smatrix.o smatrix_main.o

kmp_example.o: kmp_example.c
	$(CC) -c kmp_example.c

kmp_example: kmp_example.o
	$(CC) -o kmp_example kmp_example.o

clean:
	rm -f $(OBJS) $(TARGET)
