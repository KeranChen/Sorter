#Sorter
Author: Kaiyun Chen

Purpose: 
This program is written to sort the input numbers, from either standard cin
or from a given file, and output the sorted numbers to either a new file or
print them out directly. 

Ack:
No help received

Files:
        - sorter.cpp:   This file contains the end user (people) interface 
                        implementation with the functionality described in 
                        the purpose section above.  It contains
                        "main", which runs the entire program.

        - sortAlgs.h:   This contains the function declarations (interface) 
                        for the sort functions that I implemented,
                        and that "sorter.cpp" can use to sort the lists of
                        numbers. 

        - sortAlgs.cpp: This contains the function definitions 
                        (implementation) for the sorts I declared in 
                        "sortAlgs.h". 
        
        - Makefile:     This is the Makefile for this project. 

        - README:       This is the documents for this project.

How to Compile and Run the program:

cd to the directory which contains the files of this program.
$ make
$ ./sorter sortAlg outputMode [fileName]

in the last command, sortAlg could be "-s1", "-s2" or "-s3", which will 
choose the specified sorting algorithm to sort the input numbers. outputMode
could be "--print", which will print the sorted result numbers directly, or 
"--save", which will save the sorted result in a new file. [fileName] is an 
optional input if user wants to sort the numbers from a file. 

Data Structures and Algorithms:

1. This program use vector<int> to store the  numbers. vector<int> is a c++ 
interface that achieves the semantic logic sequence. The  advantage of this
vector interface over an regualr int array is that this vector interface 
is a dynamic array, so the capacity of the number sequence can vary. This 
characteristic of vector is very useful in this program, because the program
doesn't know the capacity of the input numbers before hand. 


2. Sorting Algorithm 1: Insertion sort
The idea of insertion sort algorithm is that, we are incresing the number of 
already sorted elements in the sequence, by correctly inserting the next 
unsorted element into the sorted part. we can stop the sort when we are 
running out of unsorted elements in the sequence.

The time complexity of Insertion sort is O(n^2). Because for the first element
we need to check 1 element to insert it correctly, for the second element
we need to check 2 elements to insert it correctly... for the last element, we
check (n - 1) elements to insert it correctly. Hence the total time complexity
is 1+2+3+...+ (n-1)  = O(n^2)

The space complexity of this insertion sort in this project is O(1). Since
I am using a swapping fuction to swap every 2 elements, in order to insert the
new elements into corrected index. So when we want to insert a new element,
we loop through the sorted part of the sequence by iterator i, 
if nums[i] <= new element, don't do anything
if nums[i] > new element, swap the position of nums[i] and new element.

3. Sorting Algorithm 2: Merge Sort
The idea of merge Sort is divide and conquer. If we can divide the sequence
into 2 part, and somehow sort the 2 parts, then it will be easy to merge the 
2 sorted part into a single sorted sequence, and we can divide the sequence 
into smaller and smaller pieces, until we cann't devide any longer. Then we 
merge the 2 sorted part into larger one, and merge the larger parts into even
larger one.....

I worte a recursive merge sort algorithm. I recursively divide the sequence, 
and merge the 2 sorted subsequence back on every level.
On every level, it will take O(1) time to devide the sequence, and O(n) time
to merge every 2 sorted part. And we can in total devide the squence logN time,
so in total we have LogN levels. 
In total, time Complexity O(nlogn).

The space complexity of merge sort in this program is O(n). Because I use a 
single helper sequence to help the merging, and I can reuse the helper sequence 
on every level.

4. Sorting Algorithm 3: Quick Sort
The idea of quick sort is that, every time we determine the corrected final 
position for a single element in the sequence. If we do this for n times, we
can determine the corrected final position for all the elements in the sequence

This program implements the quick sort in a recursive way. Since once we 
determine the corrected position for a single element (pivot), we can devide
the numbers in to a smaller part than the pivot and a larger part, and in those
2 parts, we can find other pivots respectively, and devide the sequence into 
even smaller parts repectively. 

So if we are lucky, and we choose our pivots as the middle elements every time,
so the pivot can devide the sequence up into 2 equal parts, so we only need to 
do the devision for log n times; However, if we are not lucky, we could choose
the smallest or largest element of the sequence every time, so we can only 
"devide" the sequence into 1 part, so we need to devide for n times. Since 
we are doing Big O analysis, we need to assume for the worst, so we would
assume we devide for n times, and every time we devide, we need to scan through
the sequence to determine the corrected position for pivot (O(n)). In total,
time complexity is O(n^2).

Space complexity in the program for quick sort is O(1). This program just 
overwirte the original sequence to put the pivot into corrected position,
no helper array needed.

Tests:

I test all the 3 sorting algorithms, and 2 input modes and 2 output modes 
repectively. 
The different input numbers are 0 numbers, 1, numbers, 15 numbers.
I also tested the sorting algorithms on: acending numbers, decending numbers,
regular non sorted numbers, uniform numbers (all elements equal). 
