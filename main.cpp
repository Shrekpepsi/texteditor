#include <iostream>

#include"header.h"
#include<stack>
using namespace std;


int main()
{
	int position=0; char text[]="";
	char t;
    textEditor txt;
    int checksum;
    bool ans;
    while(checksum !=7){
    cout<<"Enter 1 to enter new word\n Enter 2 to enter a single caracter\n Enter ";
    cout<< "3 to move curser to desired location \n Enter 4 to delete caracter using (DEl key) ";
    cout<<"\nEnter 5 to delete caracter using(backspace key)";
    cout<<"\nEnter 6 to find and replace";
    cout<<"\nEnter 7 to exit";
    cout<<"\n|";
    cin>>checksum;
    cout<<endl; 
    
    switch (checksum){
    	case 1:
    		cout<<"Enter word \n |";
    		cin>>text;
    		txt.insertWord(text);
    		cout<<"Word Inserted\n";
    		txt.examineTop();
    		cout<<endl;
    		break;
    	case 2:
    		cout<<"Enter caracter \n |";
    		cin>>t;
    		txt.insertCharacter(t);
    		cout<<"caracter Inserted \n";
    		txt.examineTop();
    		cout<<endl;
    		break;
    	case 3:
    		cout<<"Enter position to move curser to \n |";
    		cin>>position;
    		txt.moveCursor(position);
    		txt.examineTop();
    		cout<<endl;
    		break;
    	case 4:
    		ans =txt.deleteCharacter();
    		if (ans){
    			cout<<"deleted"<<endl;
    			txt.examineTop();
    		}
    		else{
    			cout<<"Error";
			}
			cout<<endl;
    		break;
    	case 5:
    		ans =txt.backSpaceCharacter();
    		if (ans){
    			cout<<"deleted"<<endl;
    			txt.examineTop();
    		}
    		else{
    			cout<<"Error";
			}
			cout<<endl;
    		break;
    	case 6:
    		char a,b;
    		cout<<"\nEnter word to replace";
    		cin>>a;
    		cout<<"Enter to replace with";
    		cin>>b;
    		txt.examineTop();
    		cout<<endl;
    		break;
    		
				
	}
}
    cout<<"Good bye";
    return 0;
}


/*

int main() {
	
	
	
    int i=0; char text[80];
    textEditor txt;

    cout << "Enter the word to be inserted: ";
    cin.getline(text,80);
    txt.insertWord(text);

    cout << "Inserting the word:";
    txt.examineTop();

    cout << "Enter the word to be inserted: ";
    cin.getline(text,80);
    txt.insertWord(text);
    cout << "Inserting the word:";
    txt.examineTop();
    cout << "Move cursor to the position 14: ";
    txt.moveCursor(14); txt.examineTop();
    cout << "Move cursor to the position 17: ";
    txt.moveCursor(17);
    txt.examineTop();

    for(i=0;i<3;i++){
        if(!txt.deleteCharacter())
            cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
        else
            cout << "Delete characters using DEL: ";
            txt.examineTop();
    }

    for(i=0;i<7;i++){
        if(!txt.backSpaceCharacter())
            cout << "There is nothing to delete. Move your cursor accordingly to delete the character";
        else
            cout << "Delete characters using Backspace: ";
            txt.examineTop();
    }

    txt.findAndReplaceChar('t','T');
    cout << "Replace occurrences of t with T: ";
    txt.examineTop();
    return 0;
} 

*/
