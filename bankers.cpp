#include <fstream>
#include <iostream>

int main() {
    const int n = 5;          // number of processes
    const int m = 3;          // number of resources

    int available[m];         // matrix of available resources
    int max[n][m];            // matrix containing the maximum amount of resources a process can demand
    int allocation[n][m];     // matrix that contains the amount of resources of each type allocated to each process

    std::ifstream inputFile("inputFile.txt");

    // reads from inputFile into "allocation" matrix
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            inputFile >> allocation[i][j];
            // std::cout << allocation[i][j] << " ";   // for checking values stored in "allocation" matrix
        }
    }
    
    // std::cout << '\n';

    // reads from inputFile into "max" matrix
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            inputFile >> max[i][j];
            // std::cout << max[i][j] << " ";      // for checking values stored in "max" matrix
        }
    }

    // std::cout << '\n';

    // reads from input file into "available" array
    for(int i = 0; i < m; i++) {
        inputFile >> available[i];
        // std::cout << available[i] << " ";       // for checking values stored in "available" array
    }

    inputFile.close();

    int finish[n] = {0};   // whether or not process is finished - start unfinished
    int safeSequence[n];   // stores safe sequence
    int need[n][m];        // remaining resource needs of each process
    int index = 0;         // for indexing safeSequence[]

    /* // checks values stored in finish[]
    for (int w = 0; w < n; w++) {
        std::cout << finish[w] << " ";
    } */
    

    // calculates each processes resource needs and stores them in need[][]
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    int marker = 0;     // 0 if all processes finish, will become 1 if need exceeds availability

    // checks if need exceeds availability for all processes
    // if it encounters a process that cannot finish, sets marker to 1 and breaks loop
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            if (finish[i] == 0) {
                marker = 0;
                for (int j = 0; j < m; j++) {
                    if (need[i][j] > available[j]) {
                        marker = 1;
                        break;
                    }
                }

                if (marker == 0) {   // if all processes finish
                    safeSequence[index++] = i;
                    for (int l = 0; l < m; l++) {
                        available[l] += allocation[i][l];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    marker = 1;

    // checks if sequence is safe, by seeing if all processes finish
    // if any process did not finish, need exceeds availability and sequence is not safe
    for (int i = 0; i < n; i++) {
        if (finish[i] == 0) {
            marker = 0;
            std::cout << "System is not in a safe state.\n";
            break;
        }
    }
    // if all processes are finished system is in safe state
    // print out safe sequence
    if (marker == 1) {
        std::cout << "System is in a safe state.\n";
        std::cout << "Safe sequence is: ";
        for (int i = 0; i < n - 1; i++) {
            std::cout << "p" << safeSequence[i] << " ";
        }
        std::cout << "p" << safeSequence[n - 1] << '\n';
    }

    return 0;
}

// final version

