# pushswap

masilva-
- parser list of ints to stack a ☑️
	- atoi? or ints must be adequatelly formated?
	- no dups
	- within int range
	- only digits or signs
	- check for adequate flagging
- compute disorder ☑️
	- done
- strategy selector ☑️
	--simple Forces the use of your O(n2) algorithm.
	--medium Forces the use of your O(n√n) algorithm.
	--complex Forces the use of your O(n log n) algorithm.
	--adaptive Forces the use of your adaptive algorithm based on disorder.
			This is the default behavior if no selector is given

- benchmark mode ☑️
	--bench
	print to stderr

- flag handler ☑️
	bench + strategy selector multi or single option 


research
- makefile
	https://www.it.uc3m.es/pbasanta/asng/course_notes/gcc_compiling_linking_en.html

- sorting algorithms
	https://www.geeksforgeeks.org/dsa/time-complexities-of-all-sorting-algorithms/

	https://www.merriam-webster.com/dictionary/parser
	
https://medium.com/@piyushkashyap045/understanding-tokenizers-in-natural-language-processing-nlp-1c295d3cfec2
- benchmark

resources
masilva-

DSA - Data Structures and Algorithms
https://www.geeksforgeeks.org/dsa/dsa-tutorial-learn-data-structures-and-algorithms/


https://www.geeksforgeeks.org/dsa/introduction-to-stack-data-structure-and-algorithm-tutorials/
[stack with array](https://www.geeksforgeeks.org/c/implement-stack-in-c/)
[stack using linked list](https://www.geeksforgeeks.org/c/stack-using-linked-list-in-c/)
https://www.geeksforgeeks.org/dsa/stack-implementation-using-deque/
https://www.geeksforgeeks.org/dsa/implement-stack-using-array/
https://www.geeksforgeeks.org/dsa/implement-a-stack-using-singly-linked-list/
https://www.sciencedirect.com/topics/computer-science/decision-threshold
https://developers.google.com/machine-learning/crash-course/classification/roc-and-auc
https://medium.com/@andremrufino/asymptotic-analysis-and-big-o-notation-db4dba3fe802
https://stackoverflow.com/questions/25993671/outputting-%E2%88%9A-symbol-in-c

https://github.com/o-reo/push_swap_visualizer



- readme com thresholds, internal techniques per regime, complexity arg (upper bounds) for time and space within the push swap model.


complexity class refers to the rate of disorder of a given input, and on this project it will be used to select the most adequate sorting strategy, 
taking that into consideration

https://www.geeksforgeeks.org/dsa/insertion-sort-algorithm/
https://www.geeksforgeeks.org/dsa/selection-sort-algorithm-2/
https://www.w3schools.com/dsa/dsa_algo_bubblesort.php
https://www.geeksforgeeks.org/dsa/bubble-sort-algorithm/

https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81 chunk merge sort

https://www.geeksforgeeks.org/dsa/introduction-to-block-sort/



**Push_swap** is an algorithmic project designed to deepen our understanding of data structures, complexity analysis, and adaptive algorithm design. The core objective is to sort a stack of integers using a secondary stack and a restricted set of stack manipulation commands (`sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, `rrr`), producing the shortest possible sequence of operations.


---

## Technical Overview & Adaptive Strategy

Rather than relying on input size (N) alone, this project selects algorithms based on input disorder (D). 

### Disorder Metric
Disorder measures how far the initial stack A is from being sorted, expressed as a normalized ratio of actual inversions over total potential pairs:

**Disorder (D) = Mistakes (Inversions) / Total Unique Pairs**
*(Where Total Unique Pairs = N * (N - 1) / 2)*

* **D = 0.0:** Fully sorted stack (0 operations required).
* **D < 0.2:** Low disorder (nearly sorted).
* **0.2 <= D < 0.5:** Medium disorder (moderate entropy/patterns).
* **D >= 0.5:** High disorder (chaotic or reverse-sorted input).

---

## Thresholds, Internal Techniques & Complexity Analysis

The adaptive router selects internal strategies based on D, balancing setup overhead against theoretical upper bounds within the Push_swap operation model:

| Regime | Disorder Threshold | Internal Technique | Operations Time Upper Bound | Space Complexity |
| :--- | :--- | :--- | :--- | :--- |
| **Low Disorder** | D < 0.2 | Adaptive Outlier Extraction / Insertion Pass | O(n^2) worst-case, O(n) empirical | O(n) auxiliary |
| **Medium Disorder** | 0.2 <= D < 0.5 | Chunk-Based / Block Partitioning (√n buckets) | O(n√n) | O(n) auxiliary |
| **High Disorder** | D >= 0.5 | Radix Sort (LSD Bit-Passes) / Stack Partitioning | O(n log n) | O(n) auxiliary |

### Rationale & Complexity Arguments

#### 1. Low Disorder Regime (D < 0.2) — O(n^2) Class
* **Internal Technique:** Iterative outlier extraction. The algorithm scans Stack A for neighbor-index inversion gaps. Isolated out-of-order elements are temporarily pushed to Stack B, Stack A is base-sorted (or handled via `alg3`), and elements from B are re-inserted using targeted swaps (`sa`).
* **Time Complexity Upper Bound:** While general Insertion/Selection methods degrade to O(n^2) on random inputs, their operation cost on low disorder scales with inversions: O(n + K). When D < 0.2, K is extremely small, yielding an empirical near-linear runtime of O(n) moves.
* **Space Complexity:** O(n) total auxiliary stack space.

#### 2. Medium Disorder Regime (0.2 <= D < 0.5) — O(n√n) Class
* **Internal Technique:** Block/Chunk Partitioning. Stack A is divided into k = √n value ranges. Elements belonging to the active chunk are pushed into Stack B using rotational searches (`ra`/`rra`), forming a roughly sorted distribution in B. Elements are then systematically pushed back to A in strict descending order.
* **Time Complexity Upper Bound:** Searching and rotating each element into its corresponding chunk requires at most O(n) rotations. Across √n chunk passes, the operation count scales to O(n√n).
* **Space Complexity:** O(n) auxiliary space.

#### 3. High Disorder Regime (D >= 0.5) — O(n log n) Class
* **Internal Technique:** Least Significant Bit (LSD) Radix Sort or Stack Quick-Partitioning. Data is normalized into 0-based indices. The algorithm performs bitwise evaluations on Stack A, pushing 0-bits to B and rotating 1-bits in A, then restoring B back to A.
* **Time Complexity Upper Bound:** The process requires log2(max_index) bit passes. Each pass processes all n elements in O(n) operations, yielding a strict theoretical bound of O(n log n) total generated operations.
* **Space Complexity:** O(n) auxiliary space.

---


