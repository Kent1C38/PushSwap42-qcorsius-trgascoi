*This project has been created as part of the 42 curriculum by trgascoi, qcorsius.*

# Description
Push-Swap is a project that runs sorting algorithms on a stack given by the user and write in the console every moves needed to sort the stack. You can also use the `--bench` option to see the resume.

# Instructions
In order to compile the project, you must use the `make` command, it will create the executable file named `push_swap`.<br>
The program is lauched following this pattern:<br>
`./push_swap [ <options> ] <numbers>`

### Options

#### Sorting strategies:
- `--simple` : the program selects the algorith with a O($n^2$) complexity
- `--medium` : the program selects the algorith with a O($n\sqrt(n)$) complexity
- `--complex` : the program selects the algorith with a O($n\log(n)$) complexity
- `--adaptive` : the program selects the appropriate algorithm following the disorder percentage of the stack

###### /!\ You can only choose one of those, if you try with more the program will result in an error.

#### "Benchmark mode":
`--bench` : instead of writing all steps performed, writes a resume that prints the disorder percentage, the chosen algorithm, and counts the total operations

# Resources
Websites:
- [Reddit](https://www.reddit.com/)
- [Stack Overflow](https://stackoverflow.com/)

AIs usage:
- Algorithm understanding
- Refactorization of the code to respect the norm
- Help to understand how to simply handle options as arguments for the program

# Algorithms & Rationale

## Why These Algorithms?

These algorithms were specifically chosen to work with the unique constraints of Push-Swap: **two stacks** with **limited operations** (`sa/sb`, `pa/pb`, `ra/rb`, `rra/rrb`). Unlike classic sorting on arrays or lists with direct element access, we must choose algorithms that work with stack operations, making traditional approaches like quicksort or heapsort less adaptated.

## Algorithm Details

### Simple Sort - O($n^2$)
**Adapted Selection Sort** - Finds the smallest element, rotates it to the top of A, pushes to B, repeats. Finally pushes all back from B to A sorted. Optimal for already well ordered input stacks.

### Medium Sort - O($n\sqrt{n}$)
**Range Sort** - Divides values into $\sqrt{n}$ ranges and processes each sequentially. Elements of each range are pushed to B, then returned to A in order. Ideal compromise for medium ordered input stacks.

### Complex Sort - O($n\log n$)
**Adapted Radix Sort** - Processes numbers bit-by-bit. For each bit position, keeps 0-bits in A (rotate) and pushes 1-bits to B, then pushes all back. Repeats for $\log_2(n)$ passes. Comparison-free, optimal for less ordered inputs.

### Adaptive Sort
**Automatic Selection** - Analyzes input disorder percentage and stack size to automatically choose the most efficient algorithm: simple for nearly sorted, range for medium disorder, radix for high disorder.