# Game of Life
## Purpose
This project is made to simulate Conway's Game of Life 
in an accurate manner, whilst also utilizing different 
data structures and algoriths such as lists, stacks, 
binary trees and graphs
## Implementation
Although not the most optimal implementation, this project
uses a pretty intuitive understanding of data structures
in order to respond to the 4 tasks given
### Libraries
The project uses 2 libraries, listlib and genlib, which aim
to separate the functions strictly related to data structures,
for example reading or adding to lists or stacks, from the
functions which directly impact the Game of Life matrix
### Makefile
The makefile has some handful commands for building, testing 
with different files, and staging the relevat changes to git
## Important functions
### gen_urmatoare()
gen_urmatoare takes as variables the current matrix and a case
parameter, and changes it based on the rule (c = 0 for rule A,
c = 1 for rule B). It also returns a list of the coordinates 
of cells that change, being a fundamental function for all tasks.
### printGenTree()
printGenTree takes the current matrix and recusively changes it 
using both the rules, then prints the matrixes accordingly. If 
c = 1, the same function is used for printing the longest hamiltonian
path with hamilton()
### hamilton()
hamilton() takes the current matrix and creates an array of graphs
with each component made of live cells in the matrix. It then sorts
these arrays, and finds the first hamiltonian path on the graph with
most vertices that has one, printing the length and the path. It
prints -1 if no path exists.