# Polymorphism-and-Linked-Lists

The Linked-Lists was one of my assignments, and it was done in the first semester of the second year,

## 2 Problem Description 

DNA contains the genetic code that defines the structure of every organism on Earth. The information in this DNA is copied and inherited across generations from individua to individual, but may change over generations due to crossover and mutation. A more successful individual is more likely to survive to breed, increasing the likelihood that it will be able to pass on its particular DNA encoding.

In this practical, we are going to represent an individual with a binary “DNA” strand and mutate it over a number of generations to get a better quality individual. The concepts in this practical are related to Evolutionary Computation, a field of Artificial Intelligence.

### 2.1 BinaryNode
In this practical, we use a class called BinaryNode to represent a gene on the DNA. BinaryNode has a boolean variable storing the value of this gene. Every BinaryNode object points to another BinaryNode object, which create a linked list. You should be able to iterate through the linked list by traversing pointers.
void example(BinaryNode* head){
    BinaryNode* ptr = head;
    while (ptr != NULL){
//do stuff
        ptr = ptr->getNext();
    }
}

### 2.2 Representing binary DNA
The binary DNA is represented by the Individual class which uses BinaryNode to hold a list of binary digits. Your Individual class should at least have the following functions:
* string getString(): The function outputs a binary string representation of the BinaryNode list (e.g.“01010100”).
* BinaryNode* getFirstBit(): The function returns a pointer to the first BinaryN- ode in the list.
* void setFirstBit(BinaryNode* newHead): The function takes in a pointer to a BinaryNode and update the first BinaryNode in the list.
* int getMaxOnes(): The function returns the longest consecutive sequence of ‘1’ digits in the list (e.g. calling the function on “1001110” will obtain 3).
* int getLength(): The function returns the length of the list.
* A constructor that takes in the length of the binary DNA and creates the BinaryN- ode list. Each binary value in the list should be given a value of 0 by default.
* A constructor that takes in a list of BinaryNodes and creates a new Individual with an identical list. Note that this involves creating a new copy of the list.
* A destructor that deletes each of the BinaryNodes, not just the first one.

### 2.3 Smooth Operator
In order to mutate the DNA, we need a class called Mutator. The Mutator class has a virtual function mutate that takes in an Individual and an integer index k as parameter and returns the offspring after mutation. You are also required to derives two classes from Mutator:
* BitFlip: The mutate function in this class goes through the BinaryNode list and “flips” the k-th binary digit. If k is greater than the length of the list, we will count in circles. For example, if the length of the list is 10 and k = 12, then the mutate function will flip the second digit.
* Rearrange: In this class, the mutate function rearranges the list. The function will select the k-th BinaryNode in the list (again, counting in circles). This node and all nodes after it (all the way to the tail) will be moved to the start of the list. 
For example, if you were rearranging the list (a,b,c,d,e) and k = 3, the function would return an Individual with the list (c,d,e,a,b).
In your main.cpp, please add an ordinary function
Individual* execute(Individual* indPtr, Mutator* mPtr, int k),
which calls the mutate function on the Individual object and returns the offspring. Your execute function should decide on which mutator to use based on the actual type of the Mutator.

## 2. Description

BinaryNode:
* two constructors reset and set initial values. And using the pair function (get and set), the nestValue and Value are set and returned.
* BinaryNode() : reset the value and nextvalue as 0 and NULL
* BinaryNode(bool, BinaryNode*) : set initial Value and nextValue + setNext (BinaryNode*) : set the nextValue
* getNext() : return the nextValue
* etValue(bool) : set the value
* getValue() : return value

Individual:
* The individual class implement almost operation for Node list and taking DNA result.  Three constructors are created to set, get and print BinaryNode and result, depending on the parameter.
* deleteBinaryNode() : delete previous node + Individual(int) : set the list
* Individual(BinaryNode*) : copy list
* Individual(string) : take Binary Number as the list
* mutate(int) : virtual to work in derived classes (Rearrange and BitFlip)
* getString() : return the result list changed in the Rearrange and BitFli
* getFirstBit() : return First bit in the list
* serFirstBit(BinaryNode*) : set and change First bit, checking the next node.
* getMaxOnes() : return the longest consecutive sequence of 1 
* getLength() : return the length of list

BitFlip:
* Using BinaryNode list, Flip the value 0 to 1 or 1 to 0, depending on the Binary and index input
* BitFlip(int) : take initial length from the individual class 
* BitFlip(BinaryNode*): take list from the individual class 
* BitFlip(string): take Binary number from the individual class 
* mutate(int) : Rearrange the value

Rearrange:
* Using BinaryNode, Rearrange the value, , depending on the Binary and index input
* Rearrange(int) : take initial length from the individual class 
* Rearrange(BinaryNode*) : take list from the individual class 
* Rearrange(string) : take Binary number from the individual class 
* mutate(int) : Flip the value

main:
* In the main function, all classes is called. Firstly, the input is taken by getline, and once it is saved separately, the main function implement individual class, using the derived classes.

## 3. Running

makefile compiles all files provided, so just need to tpye "make" in the terminal, and run "main.exe".

```
(binarystr1 k1 binarystr2 k2)
Sample input: 000000 2 0111 2 
Sample output: 010000 1110 3
```
