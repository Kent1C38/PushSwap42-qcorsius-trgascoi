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
