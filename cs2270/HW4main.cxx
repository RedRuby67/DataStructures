#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
	bstNode<int>* root = NULL;//make an initial root pointer
	int data; //data to be cin by user
	char command; //command to be cin by user
	
	while(true) //we keep letting user do stuff until they hit q
	{ //all our commands (some take 2 cin some take 1)
		
		cout << "enter i followed by number to insert" << endl;
		cout << "enter r followed by number to remove" << endl;
		cout << "enter f followed by number to find" << endl;
		cout << "enter s to see the size of the tree" << endl;
		cout << "enter t to print out the tree" << endl;
		cout << "enter q to quit" << endl;
		cin >> command;
		if (command =='i' || command =='r' || command =='f')
		{
			cin >> data;
		}
		switch(command) //case statement that runs through our commands
		{
			//I gave case i, case f, case t as an example of how we do stuff in main
			case 'i':
				if (root == NULL)  { //ALWAYS check the NULL case before dereferencing
					root = new bstNode<int>(data);
				} else {
				
					root->insert(data);
				}
				break;
			
			case 'r':
			//fill this in
				if (root != NULL) {
					root->remove(data);
				} else {
					cout << "***Tree Empty***" << endl;	
				}	
				break;
			
			/*
			case 'r':
                if(root == '\0')
                    cout << "no data to remove";
                else
                {
                    //if there's just the root node...
                    if(data==root->get_data() && root->get_right() == NULL && root->get_left() == NULL)
                    {
                        root = '\0';
                    }
                    else
                    {
                        cout << "trying to remove...\n";
                        root->remove(data);
                    }
                }
                
                break;
			*/
			
			case 'f':
				cout << "***f " << data << "***" << endl;
				if(root->find(data))
				{
					cout<<"found!"<<endl;
				}
				else
				{
					cout<<"Not Found!"<<endl;
				}
				break;
			
			case 's':
			//fill this in				
				if (root->size() != 1) {
					cout << "Binary tree has: " <<root->size() << " nodes" << endl;
					root->size();
				}
				else if (root->size() == 1) {
					cout << "Binary tree has: " << root->size() << " node" << endl;
				}
				else {
					cout << "Binary tree is empty." << endl;
				}
				break;
			
			case 't':
				if(root!=NULL) {
					root->traverse();
				}
				break;
			
			case 'q':
				return 0;
				break;
		}
	}
	return 0;

}
