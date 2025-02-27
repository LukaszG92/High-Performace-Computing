# Matrix Multiplication Performance Benchmarks

## Overview
This document tracks the execution time of matrix multiplication algorithms under various optimization techniques. The goal is to analyze how different optimizations affect performance and identify the most effective approaches for different matrix sizes and system configurations.

## Performance Results

|  Matrix Size  | Without Optimization | Loop Reordering |   -O2 Flag   | Parallelization |     Tiling     |
|---------------|----------------------|-----------------|--------------|-----------------|----------------|
|  2048 x 2048  |         56697.820312 |    10901.878906 |  1501.230957 |     2276.886963 |    3889.127930 |
|  4096 x 4096  |        590688.000000 |    82281.242188 | 10276.513672 |    17718.728516 |   32823.230469 |
|  8192 x 8192  |       4651723.000000 |   705779.750000 | 92420.945312 |   173359.250000 |  293556.093750 |

*The results are presented in milliseconds (ms) for each optimization technique.*

*The -O2 Flag is applied on the loop reordering optimization.*

## Testing Environment
- **CPU Model**: Apple M2
- **Number of Cores**: 8 cores (typically 4 performance cores + 4 efficiency cores)
- **Memory**: 8GB RAM
- **Operating System**: macOS Sonoma 14.6.1
- **Compiler**: Apple Clang
- **Compiler Version**: 16.0.0 (clang-1600.0.26.3)
