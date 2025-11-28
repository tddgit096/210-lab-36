//Lab 36 | Toma Dimov | COSMC210

#include <iostream>
#include "StringBinaryTree.h"
using namespace std;
    //Modify the class to process the codes found in the codes.txt file, which are strings, rather than integers. 
        //read line by line
            //call insert after each line
            //class function must compare strings by alphabetical order
                //lets use std:: strings, that's already a feature implemented in them
                //modify class function to store and sort strings instead
    //Write a program that creates and populates a BST from these records.
        //see above
    //Add interactive, menu-driven functionality to add, delete, search, and modify records

/*Milestones to document with your commits, in addition to 10-minute commits (commit must read 'Milestone n' where n is the milestone number):

    DONE -1. Project is set up and running using the provided files.
    DONE -2. Code modification from int to strings is complete, and your code exercises this for testing.
    3. Your code successfully creates a BST from the records and outputs it using the method of your choosing. 
    4. Your code's menu is functional.
*/

int main() {
    StringBinaryTree BST;
    int SIZE = 8;
    string test[SIZE]={"zebra", "ape", "donkey","eagle", "whale", "cat","dog","beaver"};
    for(int i=0;i<SIZE;i++){
        BST.insertNode(test[i]);
    }
    BST.displayInOrder();
    cout<<"\n\"dog\" deleted:\n";
    BST.remove("dog");
    BST.displayInOrder();
    cout<< "eagle is " << BST.searchNode("eagle")? "found.\n" : "not found.\n";
    BST.insertNode("iguana");
    cout<<"iguana added.\n";
    BST.displayInOrder();
    return 0;
}