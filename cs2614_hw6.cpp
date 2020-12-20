// cs2614_hw6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

//Heao class
class Heap {
private:
    vector<int> heapVector; //stores the contents of the heap
    int currentSize;        //stores the current size of the heap

public:
    //Constructor for the heap using vector values 
    Heap(vector<int> heapVector) {
        this->heapVector = heapVector;
        this->currentSize = 0;
    }

    //restore function that will work up the heap restoring the rules after adding or removing from said heap
    void restoreUp(int i) {
        while ((i / 2) > 0) {
            if (this->heapVector[i] < this->heapVector[i / 2]) {
                int temp = this->heapVector[i / 2];
                this->heapVector[i / 2] = this->heapVector[i];
                this->heapVector[i] = temp;
            }
            i = i / 2;
        }
    }

    //restore function that will work down the heap restoring the rules after adding or removing from said heap
    void restoreDown(int i) {
        while ((i * 2) <= this->currentSize) {
            int minChild = this->minChild(i);
            if (this->heapVector[i] > this->heapVector[minChild]) {
                int temp = this->heapVector[i];
                this->heapVector[i] = this->heapVector[i];
                this->heapVector[minChild] = temp;
            }
            i = minChild;
        }
    }

    //minChild function that finds and returns the smallest child. Used with functions above for percolating nodes in the tree
    int minChild(int i) {
        if (((i * 2) + 1) > this->currentSize) {
            return i * 2;
        }
        else {
            if (this->heapVector[i * 2] < this->heapVector[(i * 2) + 1]) {
                return i * 2;
            }
            else {
                return (i * 2) + 1;
            }
        }
    }

    //Function for deleting the min value of the tree. Majority of the changes are made using the restoreUp and restoreDown helper functions
    int delMin() {
        if (this->currentSize > 1) {
            int retval = this->heapVector[1];
            this->heapVector[1] = this->heapVector[this->currentSize];
            this->currentSize = this->currentSize - 1;
            this->heapVector.pop_back();
            this->restoreDown(1);
            return retval;
        }
        else {
            int retval = this->heapVector[0];
            this->heapVector[1] = this->heapVector[this->currentSize];
            this->currentSize = this->currentSize - 1;
            this->heapVector.pop_back();
            this->restoreDown(1);
            return retval;
        }
    }

    void buildHeap(vector<int> vecHeap) {
        int i = vecHeap.size() / 2;
        this->currentSize = vecHeap.size();
        this->heapVector = vecHeap;
        while (i > 0) {
            this->restoreDown(i);
            i = i - 1;
        }
    }


    //Insert function used to add items to the heap
    void insert(int k){
        //append the value
        this->heapVector.push_back(k);
        //increment size
        this->currentSize = this->currentSize + 1;
        //Restore heap rules
        this->restoreUp(this->currentSize);
        }

    bool isEmpty() {
        if (this->heapVector.size() > 0) {
            return false;
        }
        return true;
    }

    int findMin() {
        return this->heapVector[1];
    }
    void enumerate() {
        for (int i = 0; i < this->heapVector.size(); i++) {
            cout << heapVector[i];
        }
     }
};


int main()
{
    int inputVal;   //First input value used to transfer values to the vector used for heap construction
    int inputTask = NULL;  //Second input value used to store the task needing to be acomplished by the heap
    int inputKey = NULL;   //Third input value that is a key x to be associated with the operator
    vector<int> inputVector; //vector used to store input heap values
    

    cin >> inputTask; //Input and store Task Number
    cin >> inputKey; //Input and store the x Key
   
    cin >> inputVal; //Priming read for inputVal
    //Add all of the needed hap values to the inputVector
    while (inputVal != NULL) {
        inputVector.push_back(inputVal);

        cin >> inputVal;
    }
    inputVal = NULL;
    cin >> inputVal;

    inputVector.shrink_to_fit();

    Heap *mh = new Heap(inputVector);
    mh->buildHeap(inputVector);

    //Determine what to do based on task input
    if (inputTask == 0) { //If input is 0, enumeration only
        mh->enumerate();
    }
    else if(inputTask == 1) { //If input is 1, instering key and auto enumeration
        mh->insert(inputKey);
        mh->enumerate();
    }
    else if (inputTask == 2) { //If the is 2, delete root key and auto enumeration
        mh->delMin();
        mh->enumerate();
    }
}