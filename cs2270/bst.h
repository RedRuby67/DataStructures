#include <cstddef>
#include <iostream>
#ifndef BST_H
#define BST_H

using namespace std;

template<class Item>
class bstNode
{
	public:
	//constructor
	bstNode(const Item& init_data, bstNode* init_left = NULL, bstNode* init_right = NULL)
		{
			data_field = init_data;
			left_field = init_left;
			right_field = init_right;
		}
	
	//helper functions if you need them ..
	//I think I haven't used any of them so far	
	
	Item& get_data() {
		return data_field;
	}
	
	void set_data(Item& target) {
		data_field = target;
	}
	
	bstNode*& get_left() {
		return left_field;
	}
	bstNode*& get_right() {
		return right_field;
	}
	
	//FUNCTIONS YOU IMPLEMENT BELOW
	bool find(Item& targetData);
	void insert(Item& targetData);
	void remove(Item& targetData);
	int size();
	void traverse();
	
	//int maxValue();
	int getMax();
	void deleteAddress();
	bstNode* findParent(Item& targetData);
	bstNode* find_pointer(Item& targetData);
	
	//our private variables (we just have 3)
	private:
		Item data_field; //our data
		bstNode* left_field; //pointer to left child
		bstNode* right_field; //pointer to right child
};
//ALL OUR IMPLEMENTATIONS GO IN HERE-- NO .CPP FILE FOR BSTNODE BECUASE IT'S A TEMPLATE CLASS


template<class Item>
bool bstNode<Item>::find(Item& targetData)
{
	if (data_field == '\0') {
		return false;
	}	
	else if (data_field == targetData) {
		return true;
	}
	
	if (left_field != '\0') {
		if (left_field->find(targetData)) {
			return true;
		} else {
		left_field->find(targetData);
	}
}
	
	if (right_field != '\0') {
		if (right_field->find(targetData)) {
			return true;
		} else {
		right_field->find(targetData);
	}
}
	return false;
}


template<class Item>
void bstNode<Item>::insert(Item& targetData)
{
    if (targetData < data_field) {
        if (left_field == '\0') {
            left_field = new bstNode<Item>(targetData);
        }
        else {
            left_field->insert(targetData);
        }
	}
        if (targetData >= data_field){
            if (right_field == '\0') {
                right_field = new bstNode<Item>(targetData);
            }
            else {
                right_field->insert(targetData);
            }
        }
}

template<class Item>
void bstNode<Item>::traverse()
{
	if (left_field != NULL) {
		left_field->traverse();
	}
	
	cout << data_field << endl;
	
	if (right_field != NULL) {
		right_field->traverse();
	}
}

template<class Item>
void bstNode<Item>::remove(Item& targetData)
{
	while(find(targetData)) {
		if (this->data_field == targetData) {
			if (right_field == '\0' && left_field == '\0' ) {
				delete this;
				//cout << "Only root node." << endl;
			}
			
			if (left_field != '\0' || right_field != '\0') {
				this->data_field = getMax();
				deleteAddress();
				//cout << "Root replaced with: " << this->data_field << endl;
			}
		}
		
		else if (targetData < data_field) {
			if(left_field->data_field == targetData){		
				left_field = left_field->left_field;
			}
			else if(left_field != '\0') {
				left_field->remove(targetData);
			} else {
				left_field = '\0';
			}
		}
		
		else if (targetData > data_field) {
			if(right_field->data_field == targetData){		
				right_field = right_field->right_field;
			}
			else if(right_field != '\0') {
				right_field->remove(targetData);
			} else {
				right_field = '\0';
			}
		}
	}
}
		

template<class Item>
bstNode<Item>* bstNode<Item>::findParent(Item& targetData)
{
    bstNode* tempPointer;
    if ( !(left_field == '\0') )// make sure that the fields are not null.  we dont want to seg fault
        {
            if ( this->left_field->data_field == targetData)
                {
                    return this;
                }
            tempPointer = left_field->findParent(targetData);
            if ( tempPointer != '\0') // recurse through the rest of the tree until we hit the end.
                {
                    return tempPointer;
                }
        }
    if ( (right_field != '\0') )// make sure that the fields are not null.  we dont want to seg fault
        {
            if ( this->right_field->get_data() == targetData)
                {
                    return this;
                }
            tempPointer = right_field->findParent(targetData);
            if ( tempPointer != '\0') // recurse through the rest of the tree until we hit the end.
                {
                    return tempPointer;
                }
        }
    // none of the tree contains what we are looking for.  so, return false.
    return '\0';
}


// needs to be maxValue?
template<class Item>
int bstNode<Item>::getMax() 
{
	bstNode* temp = this;
	if (temp->left_field != '\0') {
		temp = temp->left_field;
		while (temp->right_field != '\0') {
			temp = temp->right_field;
		}
		return temp->data_field;
	}
	else if (temp->right_field != '\0') {
		temp = temp->right_field;
	while (temp->left_field != '\0') {
		temp = temp->left_field;
	}
	return temp->data_field;
} 
return 0;
}
	
template <class Item>
void bstNode<Item>::deleteAddress()
{
	bstNode* temp = this;
	if (temp->left_field != '\0') {
		temp = temp->left_field;
		if (temp->right_field != '\0') {
			//cout << "No right branch after initial left "<< endl;
			this->left_field = temp->left_field;
			temp = '\0';
			return;
		}
	while (temp->right_field->right_field != '\0') {
		temp = temp->right_field;
	}
	//cout << "while loop ending " << temp->data_field << endl;
	temp->right_field = '\0';
	return;
}
	else if (temp->right_field != '\0') {
		temp= temp->right_field;
		if(temp->left_field == '\0') {
			//cout << "No right branch after initial right "<< endl;
			this->right_field = temp->right_field;
			temp = '\0';
			return;
		}
		while(temp->left_field->left_field != '\0') {
			temp = temp->left_field;
		}
		temp->left_field = '\0';
	}
}

// help from Alex Campell on size function

template<class Item>
int bstNode<Item>::size()
{	
	int nodenum = 1;	
	if(left_field != '\0') {
		nodenum += left_field->size();
	}
	if(right_field != '\0'){
		nodenum += right_field->size();
	}
	return nodenum;
}

	//go through and count the number of nodes in this
	
#endif
