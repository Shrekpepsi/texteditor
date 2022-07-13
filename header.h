#include <iostream> 
#include <stack>  
using namespace std;
class textEditor {

    private:
    stack<char> leftStack; 
    stack<char> rightStack; 

    public:
        void insertWord(char word[]);
        void insertCharacter(char character);
        bool deleteCharacter();
        bool backSpaceCharacter();
        void moveCursor(int position);
        void moveLeft(int position);
        void moveRight(int position);
        void findAndReplaceChar(char findWhat, char replaceWith);
        void examineTop();
};
