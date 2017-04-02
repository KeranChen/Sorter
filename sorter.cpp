/*This file contains the end user (people) interface 
 implementation with the functionality described in 
the program specifications above.  It contains your
`"main", which runs your entire program.
*/

#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <stdexcept>

#include "sortAlgs.h"

using std::string;
using std::stringstream;
using std::runtime_error;
using namespace std;


void runInteractive(string method, string outputMode);
void runFile(string method, string outputMode, string fileName);
int string2int(std::string s);
void printVect(vector<int> &nums);
void process(vector<int> &nums, string method, string outputMode, string listOrigin);
void saveToFile(vector<int> &nums, string listOrigin, string method);


//./sorter sortAlg outputMode [fileName]

int main(int argc, char*argv[]) {
    //std::cout<< "Hello Sorter \n";
    if (argc == 3) {
        runInteractive(argv[1], argv[2]);
    } else if (argc == 4) {
        runFile(argv[1], argv[2], argv[3]);
    }
    return argc;
}

/*
runFile. get input numbers from file and process it
input: stirng method, string outputMode, string fileName
output: nothing
*/

void runFile(string method, string outputMode, string fileName) {
    ifstream input;
    string nextCommand;
    vector<int> nums;
    input.open(fileName);

    if (not input.is_open()) {
        cerr << "Unable to read filename\n";
        return;
    }
    while (!input.eof()) {
        input >> nextCommand;
        int num = string2int(nextCommand);
        nums.push_back(num);
    }
    input.close();
    process(nums, method, outputMode, fileName);
}

/*
process the given input numbers using the specified method, outputMode 
INPUT: reference of numbers, string method, stirng outputmode, string listOrigin
output: nothing
*/
void process(vector<int> &nums, string method, string outputMode, string listOrigin) {
    if (method == "-s1") {
        insertionSort( nums);
    } else if (method == "-s2") {
        mergeSort(nums);
    } else if (method == "-s3") {
        quickSort(nums);
    }
    if (outputMode == "--print") {
        printVect( nums);
    } else if (outputMode == "--save") {

        saveToFile(nums, listOrigin, method);
    }
}

/*
run the Interactive mode, which takes input from cin
input: string method, string outputMode
output: void
*/

void runInteractive(string method, string outputMode) {
    string nextCommand;
    std::vector<int> nums; 
    while (getline(cin, nextCommand)) {
        if (nextCommand.empty()) {
            break;
        }
        int num = string2int(nextCommand);
        nums.push_back(num);

    }
    process(nums, method, outputMode, "cin");


} 

/*
print the sorted numbers into cout
input: reference to numbers
output: void
*/

void printVect(vector<int> &nums) {
    int length = (int) nums.size();
    for (int i = 0; i < length; i++) {
        cout << nums[i] << endl;
    }
}
/*
save the sorted numbers into a file specified by its origin and sorting method
input: reference to numbers, string lsitOrigin, string method
output: void
*/


void saveToFile(vector<int> &nums, string listOrigin, string method) {
    ofstream myfile;
    string saveName = listOrigin;
    if (method == "-s1") {
        saveName.append("_1");
    } else if (method == "-s2") {
        saveName.append("_2");
    } else {
        saveName.append("_3");
    }
    int length = (int) nums.size();
    saveName.append("_");
    saveName.append(to_string(length));
    saveName.append("_sorted.txt");

    myfile.open(saveName);
    
    for (int i = 0; i < length; i++) {
        myfile << nums[i] <<endl;
    }
    myfile.close();

}

/*
convert a string into int
input: string s
output: int
*/
int string2int(string s)
{
        stringstream ss(s);
        int result;

        ss >> result;
        if (ss.fail())
                throw(runtime_error("string2int: non-numeric value: " + s));

        return result;
}

