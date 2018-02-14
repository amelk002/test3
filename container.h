#ifndef __CONTAINER_H__
#define __CONTAINER_H__
#include <algorithm>
#include <iostream>
#include <vector>

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

class Sort {
  public:
    /* Constructors */
    Sort();
    /* Pure Virtual Functions */
    virtual void sort(Container* container) = 0;
};

class ListContainer : public Container
{
	protected:
		list<Base*> baseList;
		Base* child;
	public:
		ListContainer(): child(NULL) {}
		ListContainer(Sort* newList): child(NULL)
		{
			sort_function = newList;
		}
		void sort()
		{
			sort_function->sort(this);
		}
		void add_element(Base* newElement)
		{
			baseList.push_back(newElement);
		}
		void print()
		{
			list<Base*>::iterator it;
			for(it = baseList.begin(); it != baseList.end(); ++it)
			{
				Base* temp = *it;
				cout << temp->evaluate() << endl;
			}
		}
		void swap(int first, int second)
		{
			list<Base*>::iterator it;
			int counter = 0;
			int counter2 = 0;
			Base* firstElement;
			Base* secondElement;
			for(it = baseList.begin(); it != baseList.end(); ++counter, ++counter2, ++it)
			{
				if(counter == first)
				{
					firstElement = *it;
				}
				if(counter2 == second)
				{
					secondElement = *it;
				}
			}
			for(counter = 0, counter2 = 0, it = baseList.begin(); it != baseList.end(); ++counter, ++counter2, ++it)
			{
				if(counter == first)
				{
					*it = secondElement;
				}
				if(counter2 == second)
				{
					*it = firstElement;
				}
			}
		}
		Base* at(int i)
		{
			list<Base*>::iterator it;
			int counter = 0;
			for(it = baseList.begin(); it != baseList.end(); ++it, ++counter)
			{
				if(counter == i)
				{
					return *it;
				}
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


class BubbleSort : public Sort
{
	protected:
		Container* child;
		vector<Base*> baseVector;
	public:
		BubbleSort(): child(NULL) {}
		BubbleSort(Container* temp): child(temp) {}
		void sort(Container* temp)
		{
			child = temp;
			for( int i = 0; i < temp->size(); ++i)
			{
				for(int j = 0; j < temp->size(); ++j)
				{
					if(j != temp->size() - 1)
					{
						if(temp->at(j)->evaluate() > temp->at(j + 1)->evaluate())
						{
							temp->swap(j, j+1);
						}
					}
				}
			}
		}
};

class SelectionSort : public Sort
{
	protected:
		Container* child;
	public:
		SelectionSort(): child(NULL) {}
		SelectionSort(Container* temp): child(temp) {}
		void sort(Container* temp)
		{
			child = temp;
			int first, in, out;
			for(out = 0; out < temp->size(); ++out)
			{
				first = 0;
				for(in = 1; in <= out; ++in)
				{
					if(temp->at(in)->evaluate() > temp->at(first)->evaluate())
					{
						first = in;
					}
				}
				temp->swap(first, out);
			}
		}
};

#endif // __CONTAINER_H__
