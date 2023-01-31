CC = mpicc

all: seqwrite parwrite

seqwrite: seqwrite.c
	mpicc $< -o $@

parwrite: parwrite.c
	mpicc $< -o $@

clean:
	rm -f *.o seqwrite parwrite out.dat