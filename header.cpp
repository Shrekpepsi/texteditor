#include<iostream>
#include"header.h"

using namespace std;

void textEditor::examineTop(){
    if(leftStack.empty())
        cout << "leftStack: empty\t";
    else
        cout << "leftStack: " << leftStack.top() << "," << leftStack.size() << "\t\t";
    if(rightStack.empty())
        cout << "rightStack: empty\n";
    else
        cout << "rightStack: " << rightStack.top() << "," << rightStack.size() << endl;
} 
void textEditor::insertWord(char word[]) {
    int i=0;

    while(word[i]!='\0') {
        insertCharacter(word[i]);
        i++;
    }
} 
void textEditor::insertCharacter(char character){

    leftStack.push(character);
} 

bool textEditor::deleteCharacter(){

    if (rightStack.empty())
        return false;
    else
        rightStack.pop();
    return true;
}

bool textEditor::backSpaceCharacter(){

    if (leftStack.empty())
        return false;
    else
        leftStack.pop();
    return true;
}

void textEditor::moveCursor(int position){

    int leftSize, rightSize, count;
    leftSize = leftStack.size();
    rightSize = rightStack.size();
    if (position < leftSize)
        moveLeft(position);
    else {
        count = position - leftSize;
        moveRight(count);
    }
}

void textEditor::moveLeft(int position){
    int leftSize;
    leftSize = leftStack.size();
    while(position!=leftSize) {
        rightStack.push(leftStack.top());
        leftStack.pop();
        leftSize = leftStack.size();
    }
}

void textEditor::moveRight(int count){
    int rightSize, i=1;
    rightSize = rightStack.size();
    if (count > rightSize)
        cout << "Cannot move the cursor, right, to the specified position";
    else {
        while(i<=count) {
            leftStack.push(rightStack.top());
            rightStack.pop();
            i++;
        } 
    } 
}

void textEditor::findAndReplaceChar(char findWhat, char replaceWith){

    int count=1, originalCursorPoistion = leftStack.size();
    moveCursor(0); 
    
    while(!rightStack.empty()) {
        if(rightStack.top()==findWhat) {
        deleteCharacter();
        insertCharacter(replaceWith);
        }
        else
            moveCursor(count);
            count++;
    } 
    moveCursor(originalCursorPoistion); 
}


