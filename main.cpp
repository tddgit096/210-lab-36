//Lab 36 | Toma Dimov | COSMC210

#include <iostream>
#include <fstream>
#include "StringBinaryTree.h"
using namespace std;

string INPUTFILE = "codes.txt";

void populateFromInput(StringBinaryTree&,string);   //file reading and populating
void BSTmenu(StringBinaryTree&);                    //user menu

int main() {
    StringBinaryTree BST;
    populateFromInput(BST, INPUTFILE);
    BSTmenu(BST);
    return 0;
}

    //Populates the given BST via file input, pass by reference
void populateFromInput(StringBinaryTree& B,string inputfile){
    fstream file(inputfile);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            B.insertNode(line);
        }
    file.close();
    }
    else{
        cout<<"Input file not found. Aborting./n";
        return;
    }
}

    //BST menu
void BSTmenu(StringBinaryTree& B){
    while(true){
        string strInput;
        //Menu Display for user
        cout<<"============ Main Menu ==============\n";
        cout<<"  [1]Display BST.\n";
        cout<<"  [2]Search for string.\n";
        cout<<"  [3]Add New Node.\n";
        cout<<"  [4]Remove Node by string.\n";
        cout<<"  [5]Replace Node.\n";
        cout<<"  [0]Exit.\n";

        getline(cin,strInput);
        int input = stoi(strInput);
        switch (input)
        {
        case 0: //exit
            return;
        case 1: //display
            B.displayInOrder();
            break;
        case 2:{//search via string
            string searchString;
            cout<<"Which string would you like to search for (case sensitive)?\n";
            getline(cin,searchString);
            cout<<searchString<<(B.searchNode(searchString) ? " found." : " not found.")<<endl;
            break;
        }
        case 3:{ //add a new node
            string newString;
            cout<<"Adding new string. Enter its value:\n";
            getline(cin,newString);
            B.insertNode(newString);
            cout<<newString<<" added.\n";
            break;
        }
        case 4:{ //remove by string
            string targetString;
            cout<<"Enter the string to be removed (case sensitive)\n";
            getline(cin,targetString);
            if(!B.searchNode(targetString)){ //check if target is present
                cout<<targetString<<" not found.\n";
                break;
            }
            B.remove(targetString);
            cout<<targetString<<" successfully removed.";
            break;
        }
        case 5:{ //replace node
            string targetString;
            cout<<"Enter the string to be modified/replaced (case sensitive)\n";
            getline(cin,targetString);
            //Somewhat redundant, the BST method will abort and COUT an error if searchNode isn't present, but it does it after the user inputs new value
            //This does it before the user enters the new value, better for the user this way.
            if(!B.searchNode(targetString)){ //check if target is present
                cout<<targetString<<" not found.\n";
                break;
            }
            string newString;
            cout<<"What would you like to change "<< targetString<< " to?\n";
            getline(cin,newString);
            B.modify(targetString,newString);
            cout<<"Replacement complete.\n";
            break;
        }
        default:
            break;
        }
    }
}