#include<iostream>
#include<random>
#include<omp.h>

int main(int argc, char *argv[]) {

  // We will initialize the random number seed with the process rank
  std::mt19937 mt = std::mt19937(1);
  std::uniform_real_distribution<double> dist(0.0, 1.0);

  // Create a set of random values on each rank
  int nvalues = 50000;
  std::vector<double> sortvec(nvalues);
  for (int ivalue = 0; ivalue < nvalues; ivalue++) {
    sortvec[ivalue] = dist(mt);
  }

  /* This is where you need to sort the values across all threads
     You will need to REPLACE the call to std::sort with your own code
     REMEMBER: Be careful to limit your use of memory.
  */
  double start_time = omp_get_wtime();
  std::sort(sortvec.begin(), sortvec.end());
  double walltime = omp_get_wtime() - start_time;

  // Print the final values
  // To ensure that everything is printed in the correct order, we loop over ranks
  for ( int ivalue = 0; ivalue < nvalues; ivalue++) {
    std::cout << "   Index: " << ivalue << "   Value: " << sortvec[ivalue] << std::endl;
  }

  // Verify that there are no errors in the ordering
  for (int i = 1; i < nvalues; i++) {
    if ( sortvec[i] < sortvec[i-1] ) {
      std::cerr << "ERROR: VALUES " << i-1 << " AND " << i << " ARE MISORDERED." << std::endl;
    }
  }

  std::cout << "Total walltime: " << walltime << std::endl;

}