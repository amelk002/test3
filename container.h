#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <algorithm>
#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

class Container {
    protected:
        Sort* sort_function;

    public:
        /* Cosntructors */
        Container() : sort_function(NULL) { }
        Container(Sort* function);

        /* Non Virtual Functions */
        // Set the type of sorting algorithm
        void set_sort_function(Sort* sort_function);

        /* Pure Virtual Functions */
        // insert the top pointer of the tree into the container
        virtual void add_element(Base* element) = 0;
        // iterate through the trees and output values
        virtual void print() = 0;
        // calls on the previously set sorting-algorithm.
        // Check if sort_function is not null, throw exception if is null
        virtual void sort() = 0;

        /* Essentially the only functions needed to sort */
        // switch tree locations
        virtual void swap(int i,int j) = 0;
        // get top pointer of tree at index i
        virtual Base* at(int i) = 0;
        // return container size;
        virtual int size() = 0;
};


class ListContainer : public Container
{
	protected:
		list<Base*> baseList;
		Base* child;
	public:
		ListContainer(): child(NULL) {}
		ListContainer(Sort* temp): child(NULL)
		{
			sort_function = temp;
		}
		void sort()
		{
			 sort_function->sort(this);
		}
		void add_element(Base* element)
		{
			baseList.push_back(element);
		}
		void print()
		{
			list<Base*>::iterator it;
			for(it = baseList.begin(); it != baseList.end(); it++)
			{
				Base* a = *it;
				cout << a->evaluate() << endl;
			}
		}
		void swap(int i,int j)
		{
			list<Base*>::iterator it;
			int counter = 0;
			Base* temp1;
			Base* temp2;
			int counter2 = 0;
			for(it = baseList.begin(); it != baseList.end(); it++)
			{
				if(counter == i)
				{
					temp1 = *it;
				}
				if(counter == j)
				{
					temp2 = *it;
				}
				counter++;
				counter2++;
			}
			counter = 0;
			counter2 = 0;
			for(it = baseList.begin(); it != baseList.end(); it++)
			{
				if(counter == i)
				{
					*it = temp2;
				}
				if(counter == j)
				{
					*it = temp1;
				}
				counter++;
				counter2++;
			}
		}
		Base* at(int i)
		{
			list<Base*>::iterator it;
			int counter = 0;
			for(it = baseList.begin(); it != baseList.end(); it++)
			{
				if(counter == i)
				{
					return *it;
				}
				counter++;
			}
			return *it;
		}
		int size()
		{
			return baseList.size();
		}
};

class vectorcontainer : public Container
{
	protected:
		vector<Base*> vector1;
		Base* child;
	public:
		vectorcontainer(): child(NULL) {}
		vectorcontainer(Sort* vectors): child(NULL)
		{
			sort_function = vectors;
		}
		void sort()
		{
			sort_function->sort(this);
		}
		void add_element(Base* newElement)
		{
			vector1.push_back(newElement);
		}
		void print()
		{
			for(unsigned int i = 0; i < vector1.size(); ++i)
			{
				cout << vector1.at(i)->evaluate() << endl;
			}
		}
		void swap(int first, int second)
		{
			Base* tempVal  = vector1.at(first);
			vector1.at(first) = vector1.at(second);
			vector1.at(second) = tempVal;
		}
		Base* at(int i)
		{
			return vector1.at(i);
		}
		int size()
		{
			return vector1.size();
		}
};


#endif // __CONTAINER_H__
