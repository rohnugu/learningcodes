OBJS = matrix.o matrix_main.o smatrix.o smatrix_main.o
TARGET = matrix smatrix

all: $(TARGET)

matrix.o: matrix.c matrix.h
	$(CC) -c matrix.c

matrix_main.o: matrix_main.c matrix.h
	$(CC) -c matrix_main.c

matrix: matrix.o matrix_main.o | .gitignore
	$(CC) -o matrix matrix.o matrix_main.o
	echo matrix >> .gitignore

smatrix.o: smatrix.c smatrix.h
	$(CC) -c smatrix.c

smatrix_main.o: smatrix_main.c smatrix.h
	$(CC) -c smatrix_main.c

smatrix: smatrix.o smatrix_main.o | .gitignore
	$(CC) -o smatrix smatrix.o smatrix_main.o
	echo smatrix >> .gitignore
.gitignore:
	echo *.o >> .gitignore

clean:
	rm -f $(OBJS) $(TARGET) .gitignore
