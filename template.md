_This project has been created as part of the 42 curriculum by aplucins and masilva-c_

# Push Swap
Sorting data with two stacks and a given set of operations.
Algorithmic complexity, disorder and inversions, complexity based sorting algos. adaptive algorithm design


## Description
```bash
./push_swap $(ARGS) [--strategy-selection] [--benchmark]
```
Sort data on a stack, with a limited set of instructions, using the lowest possible number of actions. To succeed you’ll have to manipulate various
types of algorithms and choose the most appropriate solution (out of many) for optimized data sorting.

You have at your disposal a set of integer values, 2 stacks, and a set of operations to manipulate both stacks.
Write a C program called push_swap which calculates and displays on the standard output the smallest program, made of 
Push swap language operations, that sorts the integers received as arguments.

### Arguments

* **stack a**: A list of integers
* **optional flags**: 
	benchmark (--bench) 
	strategy selector (--simple, --medium, --complex, --bench)

### Output
* **{Nothing}**: no args or operations were provided or executed.
* **Operations**: push swap operations to sort the given stack.
* **Error\n**: sent to STDERR 
* **Benchmark**: sent to STDERR upon flag request after sorting the stack.

### External Functions Used

* `read`, write, `malloc`, `free`, exit
* ft_fprintf() - ft_printf equivalent developed by masilva-

### Technical Requirements


---

This implementation features an **Adaptive Sorting Strategy** that selects the adequate sorting algorithm based on the data's disorder metric.

## Instructions



### Usage
Compile the binary using the provided `Makefile`:

```bash
make
```

### Argument generation

The program should run with no memory leaks.

#### Memory utils
#### Valgrind

```bash
# To check for memory or fd leaks, run the following commandline, dont forget to compile with -g
valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --track-fds=yes ./push_swap $(cat args.txt) --bench
```
#### fsanitize


---

## Algorithm



## Contributions
masilva-
- data structure management and error
	initialize data, error handling without memory leaks and with exit() call, freeing allocated memory for cmdline, stacks and bench variables. I implemented a Singleton pattern for the benchmark structure (t_bench) to provide global, read/write access to performance metrics (disorder, total_ops, operation counters) without relying on function scope or global vars.

- lexer and utils
	checks if no empty arguments were provided.
	proceeds to convert input onto a char **cmdline matrix with args ready to parse. allows our program to handle multiple strs with arguments, first combining them together safely with join_and_free(), and then removing whitespaces with ft_split_strs() util.
	```text
	./push_swap 4 1 "32\t 08  -12 --bench" 
	```
	``` c
	**cmdline = {"4", "1", "32", "08", "-12", "--bench"} 
	```
- parser
	checks for flag syntax [single strategy selection and optional benchmark]and stack's data [no duplicates, within int range, args are not integers].
	i used two static variables for flag syntax and a flag 'i' (info) for access to ft control, not to corrupt the value.

- tokenizer
	converts validated input to the program's data structs t_stack and t_bench.
	stores the provided ints onto a linked list of t_stack type, with a dynamic memory allocation, and sets a index corresponding to the sorted position within the list.
	stores program information necessary for execution: benchmark option, the user's strategy selection and stack disorder.

- strategy selector
	checks if stack needs sorting, based on disorder metric,
	assigns adaptive strategy if none were selected by the user.
	calls algorithmic strategy and begins sorting.

- compute_disorder(), adaptive strategy and brut_algo()
	compute_disorder() returns float 0.00f to maintain accurate disorder value, instead of a normalized value.
	adaptive reassigns the strategy selection for proper --bench print.
	For D < 0.2, improved the simple algorithm performance on a small sized stack, for n < 3 and n < 5;
- performance benchmark [extra]
	added a performance benchmark, using 42's criteria, atribuiting from bad to excelent performance, based on total moves count.
	


aplucins

Simple algorithm (O(n.n)):
    The algorithm is instructed to push the elements from A to B in ascending order and then push them all back in the order they are.
    -It will locate the lowest value element in A;
    -Calculate the faster way to get that element ([Rotate A] or [Reverse Rotate A]), execute it and once the   lowest element is on top of A, it is pushed to B ([Push to B]);
    -Repeat for each n (list element);
    -Once there are no elements in A it pushes all of the elements in B to A ([Push to A]);

Since the algorithm pushed the elements from A to B in ascending order, the elements are ordered from highest to lowest, once they are pushed to B. Therefore when the elements are pushed from B to A, they will appear in ascending order on A.

Medium algorithm (O(n.sqrt(n))):
    The algorithm will push groups of elements and then sort them back to A.
    -Each block will have range/sqrt(n) elements and all blacks will have a certain range (the first block has the range/sqrt(n) lowest elements of the stack, and so forth);
    -Stack A will be rotated ([Rotate A]) and push ([Push to B]) each block so that all of the elements of the block are together;
    -Stack B pushes the it's highest value element to A ([Push to A]);

Since the blocks have the values of the same range using a selection dort algorithm on bock B will still have the desired effect of cutting the number of rotations, thanks to the block structure.

Complex algorithm (O(n.log(n))):
    The algorithm will sort all of the elements using the bits of each element, if the analyzed bit is 0 the element will be pushed ([Push to B]) and after all of the elements are pushed, all elements from B ar pushed to A. The bits are analyzed from Left to Rigth.
    -The algorithm will analyze the bits of each number from left to rigth;
    -It will do a full rotation pushing to B ([Push to B]) all of the elements the have a 0 in the analyzed bit space;
    -The process is repeated x times where x is the number of bits of the biggest number in the stack;

Since we are organizing the bits from left to rigth the last push presents all of the elements in ascending order. In case of the existance of negative numbers, after sorting the algorithm will push all of the negative numbers in descendig order to B ([Push to B]) and then push them back ([Push to A]) putting them otherwise, they will be presented sorted as if the where |n|.



## Resources
### Research & Fundamentals
* **Compilation & Linking:** [GCC Compiling and Linking Notes](https://www.it.uc3m.es/pbasanta/asng/course_notes/gcc_compiling_linking_en.html)
* **Sorting Complexities:** [Time Complexities - All Sorting Algorithms](https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/)
* **Parsing & Tokenization:**
  * [Merriam-Webster: Parser Definition](https://www.merriam-webster.com/dictionary/parser)
  * [Understanding Tokenizers in NLP](https://medium.com/@piyushkashyap045/understanding-tokenizers-in-natural-language-processing-nlp-1c295d3cfec2)
* **Decision Thresholds & Theory:**
  * [ScienceDirect: Decision Threshold Concepts](https://www.sciencedirect.com/topics/computer-science/decision-threshold)
  * [Google ML Crash Course: Classification, ROC & AUC](https://developers.google.com/machine-learning/crash-course/classification/roc-and-auc)
  * [Asymptotic Analysis & Big-O Notation](https://medium.com/@andremrufino/asymptotic-analysis-and-big-o-notation-db4dba3fe802)
  * [StackOverflow: Outputting Square Root Symbol in C](https://stackoverflow.com/questions/25993671/outputting-%E2%88%9A-symbol-in-c)

### Data Structures & Stacks
* **DSA Overview:** [GeeksforGeeks DSA Tutorial](https://www.geeksforgeeks.org/dsa/dsa-tutorial-learn-data-structures-and-algorithms/)
* **Stack Data Structure:** [Introduction to Stack Data Structure](https://www.geeksforgeeks.org/dsa/introduction-to-stack-data-structure-and-algorithm-tutorials/)
* **Stack Implementations:**
  * [Implement Stack in C (Array)](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
  * [Implement Stack in C (Linked List)](https://www.geeksforgeeks.org/c/stack-using-linked-list-in-c/)
  * [Stack Implementation Using Deque](https://www.geeksforgeeks.org/dsa/stack-implementation-using-deque/)
  * [Implement Stack Using Array (DSA)](https://www.geeksforgeeks.org/dsa/implement-stack-using-array/)
  * [Implement Stack Using Singly Linked List](https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/)

### Sorting Algorithms & Techniques
* **O(n²) Algorithms:**
  * [Insertion Sort Algorithm](https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/)
  * [Selection Sort Algorithm](https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/)
  * [Bubble Sort Algorithm (W3Schools)](https://www.w3schools.com/dsa/dsa_algo_bubblesort.php)
  * [Bubble Sort Algorithm (GeeksforGeeks)](https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/)
* **O(n√n) / Chunking Algorithms:**
  * [Chunked Merge Sort Approach](https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81)
  * [Introduction to Block Sort](https://www.geeksforgeeks.org/dsa/introduction-to-block-sort/)

### Visualization Tools
* **Push_swap Visualizer:** [GitHub - o-reo/push_swap_visualizer](https://github.com/o-reo/push_swap_visualizer)

### AI Usage
I used AI to help me format this Readme.md.