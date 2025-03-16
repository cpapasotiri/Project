<p align="center"><img src="logo_en.png" alt="DIT NKUA Logo" width=50%/></p>

# <center>Software Development for Information Systems - Project - Winter Semester 2023-2024</center>


## Team Members
<table>
    <tr>
    <th>Surname</th>
    <th>First Name</th>
    <th>Registration Number</th>
    </tr>
    <tr>
    <td>Ezekelian</td>
    <td>Anait</td>
    <td>1115201900056</td>
    </tr>
    <tr>
    <td>Papasotiri</td>
    <td>Christina</td>
    <td>1115201900151</td>
    </tr>
</table>

## Compile & Run
    C++
    Use the following commands to compile:
        cmake .
        cmake --build . 
        Run the project executable with the following command:
            ./project <input filepath> <dimensions> <K nearest neighbors> <distance type e or m> <delta> <p>
            e.g. ./project datasets/2dims.bin 2 2 e
            e.g. ./project datasets/00000020.bin 100 10 m
        Run the brute force executable with the following command:
            ./brute_force <input filepath> <dimensions> <K nearest neighbors> <distance type e or m>

    Use the the following commands to run Catch2 Unit Tests:
        Run the tests executable with the following command:            
            ./allTests
        Run to see tests in detail:
            make run_tests

    Use the following command to clean build files:
        make clean_all  
    
## Code Organisation
    Project/  
    ├── datasets/  
    │   ├── *.bin  
    ├── include/  
    │   ├── *.hpp  
    ├── src/  
    │   ├── brute_force/  
    │   │   ├── *.cpp  
    │   ├── common/  
    │   │   ├── *.cpp  
    │   ├── project/  
    │   │   ├── *.cpp  
    ├── templates/  
    │   ├── *.tpp  
    ├── tests/  
    │   └── *_tests.cpp  
    └── CMakeLists.txt  
    └── clean.cmake  

## Project Description
### Introduction
The Nearest Neighbor Search (NSS) is an optimization problem aimed at finding the point in a dataset that is closest or most similar to a given point. The concept of proximity is expressed through a dissimilarity metric, where a low value indicates high similarity.

Typically, the Nearest Neighbor Search problem is defined as follows: given a set of points 𝑆 in a space 𝑀 and a query point 𝑞 ∈ 𝑀, the task is to find the point in 𝑆 that is closest to 𝑞. Dissimilarity is usually measured through a distance metric in a metric space 𝑀.

A generalization of this problem is the search for the k nearest neighbors (K-Nearest Neighbors - KNN), where the task is to find the 𝑘 closest points to a given point. A common implementation is through the k-Nearest Neighbors Graph (KNNG), where each node in the graph is connected to the 𝑘 nearest points.

Constructing the KNNG using brute-force techniques is time-consuming and practically applicable only for small datasets. For this reason, in this project, we attempted to implement an algorithm for an approximate solution to the problem, aiming for better speed and efficiency compared to the brute-force algorithm.

The algorithm used is NN-Descent.
The basic graph construction algorithm is as follows:

1. Create a random graph (connect each node to 𝐾 random nodes).
2. For each node: Measure the distance from the node to the neighbors of neighbors. If any neighbors of neighbors are closer, update the graph accordingly and maintain only the K nearest neighbors.
3. If the graph is modified, go back to step 2; otherwise, terminate.

In this project, we implemented three different versions, each an optimization of the previous one:

#### Version 1:
Implementation of the basic algorithm for a dataset with 100-dimensional points and 2-dimensional points created by us. Implementation of the Brute Force algorithm and storing the results in a binary file for comparison with NN-Descent. Distance calculations use two different distance functions (Euclidean and Manhattan) and unit tests for all public functions of the structures.

#### Version 2:
Optimization of the basic algorithm using the following techniques:
* Local Join
* Incremental Search
* Sampling
* Early Termination

#### Version 3:
Optimization of distance calculation using the Euclidean Norm.
* Initialization of the KNN graph with random projection trees (RPTrees).
* Parallel execution using threads.

### Modeling/Implementation
#### Data Structures Used:
* Templates were used to create more flexible and efficient code that could be reused for various data structures. Adapting to different data types was an essential tool.
* The vector is a dynamic array implementation.
* The graph is a collection of nodes connected by edges.
* The vertex is the node in the graph structure.
* The dll is a doubly linked list consisting of nodes. Each node contains data and two pointers, one to the previous node and one to the next.
* The queue is a data structure that follows the first-in-first-out principle.
* The job_scheduler manages task execution using a pool of threads, semaphores, and a priority queue for tasks to be executed concurrently.
* The job is a code routine to be executed by a thread, potentially concurrently with others.
* The point_norm_job calculates the norm of two points.
* The RPTree is a structure for representing random projection trees used for graph initialization. It consists of RPTreeNode, which stores arrays of arrays (i.e., multidimensional points) and pointers to left and right child nodes, created during the dataset's partitioning process.

#### Challenges Faced:
* Difficulty in understanding the usage of the Catch2 library for software correctness testing.
* Difficulty linking Github Actions with CMake (used for compiling files) to automate testing on each push.
* Difficulty in constructing a management method for handling different functions running concurrently.
* Difficulty synchronizing threads, particularly locking and unlocking threads for task execution.

### Optimizations
#### Local Join
The graph construction process initially involves creating a "neighbor" set for each node, including both direct and reversed neighbors. The graph is then updated by calculating all distances between pairs of neighbors for each direct neighbor set. After the first step, where reversed neighbors are calculated, the computation can be performed locally for each node. Temporary modifications for each neighbor set are stored, and calculations are performed at the end of each iteration.

#### Incremental Search
To avoid redundant comparisons in each local join, a boolean flag is added to the nodes, signifying whether a node has already been processed.

#### Early Termination
When the graph remains unchanged for 10 consecutive iterations, the algorithm terminates early.

### References
[NN-Descent algorithm](https://www.researchgate.net/publication/330397378_K-nearest_Neighbor_Search_by_Random_Projection_Forests) <br>
[Catch2 Testing Framework](https://github.com/catchorg/Catch2)