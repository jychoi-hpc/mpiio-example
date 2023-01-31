# MPI-IO examples
This is a collection of examples to demonstrate MPI-IO.

The list of examles is as follows:
* `seqwrite.c`: independent write
* `parwrite.c`: collective write

To build, type
```
make
```

To run, type the following command:
```
mpirun -n 10 EXEC
```
EXEC can be either `seqwrite` or `parwrite`

To check output (`out.dat`), use the following command:
```
od -i out.dat 
```