#include <string>
#include <string>
#include <iostream>
#include <vector>

#include "sortAlgs.h"

using namespace std;

/*
insertionSort to sort the  given numbers
input: reference to numbers
ouput: void
*/

void insertionSort(vector<int> &nums) {

    if (nums.size() == 0) {
        return;
    }
    int length = nums.size();
    for (int i = 1; i < length; i++) {
        //loop through every element
        for (int j = 0; j < i; j++) {
            if (nums[i] < nums[j]) {
                mySwap(nums, i, j);
            }
        }
    }
    
}
/*
swap two number in the number vector 
input: reference to numbers, left position, right position
ouptu: void
*/

void mySwap(vector<int> &nums, int left, int right) {
    int tmp = nums[left];
    nums[left] = nums[right];
    nums[right] = tmp;
}

/*
mergeSort the given numbers
input: reference to numbers
output: void
*/

void mergeSort(vector<int> &nums) {
    if (nums.size() == 0) {
        return;
    }
    //allocate helper vector to help merge step
    //this algorithm guarantee no more than O(n) space is used
    vector<int> helper;
    for (int i = 0; i < (int) nums.size();i++) {
        helper.push_back(0);
    }
    mergeSort(nums, helper, 0, nums.size() - 1);
    
}

/*
mergeSort recursive helper function
sort the range of elements specified by left and right in the numbers
input: reference to numbers, reference to helper, int left, int right
output: void
*/

void mergeSort(vector<int> &nums, vector<int> &helper, int left, int right) {
    if (left >= right) {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(nums, helper, left, mid);
    mergeSort(nums, helper, mid + 1, right);
    merge(nums, helper, left, mid, right);

}
/*
merge, a helper function in the mergeSort
merge the 2 sorted parts of the numbers, specified by left, mid, right
input: reference to numbers, reference to helper, int left, int mid, int right
ouput: void
*/


void merge(vector<int> &nums, vector<int> &helper, int left, int mid, int right) {
    //coppy the content to helper vector and we will merge from helper 
    for (int i = left; i <= right; i++) {
        helper[i] = nums[i];
    }
    int leftIndex = left;
    int rightIndex = mid + 1;
    while (leftIndex <= mid && rightIndex <= right) {
        if (helper[leftIndex] <= helper[rightIndex]) {
            nums[left++] = helper[leftIndex++];
        } else {
            nums[left++] = helper[rightIndex++];
        }
    }
    //if we still have some elements at leftside, need to copy them
    while(leftIndex <= mid) {
        nums[left++] = helper[leftIndex++];
    }

}

/*
quickSort the given numbers
input: reference to numbers
ouput: void
*/

void quickSort(vector<int> &nums) {
    if (nums.size() == 0) {
        return;
    }
    quickSort(nums, 0, nums.size() - 1);
}


/*
quickSort recursive helper function
quickSort the numbers specified by the range [left, right]
input: reference to numbers, int left, int right
output: void
*/
void quickSort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    //define a pivot and use the pivot to partition the array
    int pivotPos = partition(nums, left, right);
    quickSort(nums, left, pivotPos - 1);
    quickSort(nums, pivotPos + 1, right);
}

/*
partition, a helper function in quick Sort, 
find a pivot element, and find the corrected position of this pivot,
and partition the numbers into 2 parts
input: reference to numbers, int left, int right
output: the sorted pivot index
*/

int partition(vector<int> &nums, int left, int right) {
    int pivotIndex = getPivotIndex(left, right);
    int pivot = nums[pivotIndex];
    //swap the pivot element to the rightMost position first
    mySwap(nums, pivotIndex, right);
    int leftBound = left;
    int rightBound = right - 1;
    while(leftBound <= rightBound) {
        if(nums[leftBound] < pivot) {
            leftBound++;
        } else if (nums[rightBound] >= pivot) {
            rightBound--;
        } else {
            mySwap(nums, leftBound++, rightBound--);
        }
    }
    //swap back the pivot element
    mySwap(nums, leftBound, right);
    return leftBound;
}

/*
get Pivot index, a helper module in quickSort,
this will generate a pivot element in the range left, right
input: int left, int right
output: index of the pivot element.
*/

int getPivotIndex(int left, int right) {
    return left + (right - left) / 2;
}















