# Liangpai Code Test

Author: Li Yuanting 

Date: 10/4/2024

## Overview
This problem is designed to process trade data from a input.csv file and calculate various statistics for each instrument. The project consists of three primary files:
1. `Exercise.cpp` - Entry point of the program.
2. `trade_process.h` - Header file containing class definitions and function declarations.
3. `trade_process.cpp` - Implementation of trade processing functions.

The program reads trade data from `input.csv` and outputs the calculated results to `output.csv` in the required format.

## Compile
For the given command, we can see it's Unix system. If GCC has been already installed, we can easily compile the code to get the executable `Exercise` by following:

```bash
g++ -std=c++17 -o Exercise Exercise.cpp trade_process.cpp
```

## Use the program

Here we come to the final stage. By running the given code in the directory of Executable:

```bash
./Exercise input.csv output.csv
```

Of course we need to put the csv files in the same folder(or we need to write the path of it). And we can also edit the name of input and output.

## Comment

1. The structure of instrument can be adjusted to make the members private if the system is not only for us to use.
2. I added header for output.csv to be more human-readable. But to make sure the output is the same as the given sample, I just commented it.

Output are put here as output_0.csv and output_1.csv. They are the same as the sample output.

The time for the project itself is approximately 50min - 1h. I used some time to configure the environment and for the comments/readme.
