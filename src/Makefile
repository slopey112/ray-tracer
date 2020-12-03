IDIR =../include
CC = gcc
CFLAGS = -g -I$(IDIR)
EXE = ray-tracer
ODIR=obj

_OBJ = main.o vector.o types.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))

all: $(EXE)

$(ODIR)/%.o: %.c
	$(CC) ${CFLAGS} -c $< -o $@

$(EXE): $(OBJ)
	$(CC) $^ ${CFLAGS} -o $@

clean:
	rm -f $(ODIR)/*.o $(EXE)
