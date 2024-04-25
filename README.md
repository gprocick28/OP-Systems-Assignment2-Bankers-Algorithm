# Banker's Algorithm - For Deadlock Avoidance
This program implements the Banker's Algorithm for resource allocation and deadlock avoidance. It determines whether or not the provided system is in a safe state, and if so it determines the safe sequence. It is written in C++, and was done so in a Linux environment.
## Compilation Instructions
* bankers.cpp can be compiled using the following command in a terminal: g++ bankers.cpp -o bankers
## Execution Instructions
* Once compiled, the program can be executed using the following command in a terminal: ./bankers
## Implementation Details
This program reads input from a text file. The text files contains the details of a system's processes and resources at a given time (t0). The program determines whether or not the given system is in a safe state, and if it is it outputs the safe sequence. Matrices are used to store the current allocation and the maximum resource demand of the processes. A 1-dimensional array stores the available resources.
## Author
Gavin Procick
