#include <stdio.h>
#include <stdlib.h>
#include <mpi.h>

#define LEN 4

int main(int argc, char **argv)
{
    char *filename;
    int err, rank, nprocs;
    int buf[LEN] = {0};
    int i, k;
    MPI_Offset offset;

    MPI_File fh;
    MPI_Info info;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &nprocs);

    // Open a file and shared by all
    MPI_File_open(MPI_COMM_WORLD, "out.dat", MPI_MODE_CREATE | MPI_MODE_RDWR, MPI_INFO_NULL, &fh);

    for (i = 0; i < LEN; i++)
        buf[i] = rank + 1;

    // Method #1: Use view
    offset = (MPI_Offset) rank * LEN * sizeof(int);
    MPI_File_set_view(fh, offset, MPI_INT, MPI_INT, "native", MPI_INFO_NULL);
    MPI_File_write_all(fh, buf, LEN, MPI_INT, MPI_STATUS_IGNORE);
    // Method #2: Use MPI_File_write_at_all
    // MPI_File_write_at_all(fh, offset, buf, LEN, MPI_INT, MPI_STATUS_IGNORE);


    // Close the file
    MPI_File_close(&fh);

    MPI_Finalize();
    return 0;
}