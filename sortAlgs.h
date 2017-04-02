#ifndef SORTALGS_H
#define SORTALGS_H

#include <vector>
#include <string>

using namespace std;

void insertionSort(vector<int> &nums);
void mergeSort(vector<int> &nums);
void quickSort(vector<int> &nums);
void mergeSort(vector<int> &nums, vector<int> &helper, int left, int right);
void merge(vector<int> &nums, vector<int> &helper, int left, int mid, int right) ;
void mySwap(vector<int> &nums, int left, int right);
void quickSort(vector<int> &nums, int left, int right);
int partition(vector<int> &nums, int left, int right);
int getPivotIndex(int left, int right);

#endif