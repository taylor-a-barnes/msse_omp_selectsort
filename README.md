# Implementing Select Sort With OpenMP

In `src/main.cpp`, you will find a code that initializes each rank with a random vector (named `sortvec`) of size `nvalues`.

Currently, the code calls `std::sort` to sort the vector.
You must replace the `std::sort` call with your own implementation of a [selection sort](https://en.wikipedia.org/wiki/Selection_sort), which must be parallelized using OpenMP.
Be careful not to use excessive amounts of memory; in particular, you should avoid creating a situation in which each thread has private variables that are of similar size to `sortvec`.

Hint: At some point, you will likely find that you need to do a custom reduction operation.
One option for doing this would be to define a new reduction operation with `#pragma omp declare reduction`.
An alternate approach would be to use an `omp single` section and/or `omp critical` section and perform the reduction there.
