// BinaryHeap.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>

using namespace std;

class AbstractHeap
{

public:
	//helpers 
	template<typename T> static void swap(T& a, T&b)
	{
		T tmp = a;
		a = b;
		b = tmp;
	}

public:
	explicit AbstractHeap(int capacity) :
		m_heapCapacity(capacity),
		m_heapSize(0),
		m_heap(new float[m_heapCapacity])
	{
	}

	virtual ~AbstractHeap()
	{
		if (m_heap)
		{
			delete[] m_heap;
		}
	}

	bool isEmpty()
	{
		return m_heapSize == 0;
	}

	bool isFull()
	{
		return m_heapSize == m_heapCapacity;
	}

	// to get index of parent node from childIdx 
	int parent(int childIdx)
	{
		return (childIdx - 1) / 2;
	}

	// to get index of left child of parent Node at index: parentIdx
	int left(int parentIdx) 
	{
		return (2 * parentIdx + 1);
	}

	// to get index of right child of parent Node at index: parentIdx
	int right(int parentIdx)
	{ 
		return (2 * parentIdx + 2);
	}


	virtual void insert(float val) = 0;
	virtual void heapify(int idx) = 0;

	float extractRoot()
	{
		if (isEmpty())
		{
			return -1;
		}
		float root = getRootVal();
		//remove root val from Heap
		m_heap[0] = m_heap[m_heapSize - 1];
		m_heapSize--;
		heapify(0);
		return root;
	}


	int getHeapSize() const
	{
		return m_heapSize;
	}

	float getRootVal()
	{
		if (isEmpty())
		{
			return -1;
		}
		return m_heap[0];
	}

	float* getPtr()
	{
		return m_heap;
	}


protected:
	int m_heapCapacity;
	int m_heapSize;
	float* m_heap;

};



class MinHeap : public AbstractHeap
{

public:
	explicit MinHeap(int capacity) : AbstractHeap(capacity)
	{
	}

	void insert(float val) override
	{
		if (isFull())
		{
			std::cout << "\nMinHeap is already full!!!\n";
			return;
		}
		m_heap[m_heapSize++] = val;
		int childNodeIdx = m_heapSize - 1;
		while (childNodeIdx > 0 && m_heap[childNodeIdx] < m_heap[parent(childNodeIdx)])
		{
			swap(m_heap[childNodeIdx], m_heap[parent(childNodeIdx)]);
			childNodeIdx = parent(childNodeIdx);
		}
	}

	void heapify(int idx) override 
	{
		int l = left(idx);
		int r = right(idx);
		int smallest = idx;
		if (l < m_heapSize && m_heap[l] < m_heap[smallest])
		{
			smallest = l;
		}
		if (r < m_heapSize && m_heap[r] < m_heap[smallest])
		{
			smallest = r;
		}
		if (smallest != idx)
		{
			swap(m_heap[idx], m_heap[smallest]);
			heapify(smallest);
		}
	}
};


class MaxHeap : public AbstractHeap
{

public:
	explicit MaxHeap(int capacity) : AbstractHeap(capacity)
	{
	}

	void insert(float val) override
	{
		if (isFull())
		{
			std::cout << "\nMaxHeap is already full!!!\n";
			return;
		}
		m_heap[m_heapSize++] = val;
		int childNodeIdx = m_heapSize - 1;
		while (childNodeIdx > 0 && m_heap[childNodeIdx] > m_heap[parent(childNodeIdx)])
		{
			swap(m_heap[childNodeIdx], m_heap[parent(childNodeIdx)]);
			childNodeIdx = parent(childNodeIdx);
		}
	}

	void heapify(int idx) override
	{
		int l = left(idx);
		int r = right(idx);
		int biggest = idx;
		if (l < m_heapSize && m_heap[l] > m_heap[biggest])
		{
			biggest = l;
		}
		if (r < m_heapSize && m_heap[r] > m_heap[biggest])
		{
			biggest = r;
		}
		if (biggest != idx)
		{
			swap(m_heap[idx], m_heap[biggest]);
			heapify(biggest);
		}
	}
};



static void heapTest()
{
	int n = 10;
	MinHeap minHeap(n); // contains elements bigger than median values eg. 6-root 7 8 9 10
	MaxHeap maxHeap(n); // contains elements smaller than median values eg. 1 2 3 4 5-root 

	maxHeap.insert(1);
	maxHeap.insert(2);
	maxHeap.insert(3);
	maxHeap.insert(4);
	maxHeap.insert(3);
	maxHeap.insert(232);
	maxHeap.insert(5);
	cout << "MAX_HEAP__: ";
	for (int i = 0; i< maxHeap.getHeapSize(); ++i)
	{
		cout << maxHeap.getPtr()[i] << " ";
	}
	cout << endl;
	maxHeap.extractRoot();
	cout << "MAX_HEAP_after_root_deleted: ";
	for (int i = 0; i< maxHeap.getHeapSize(); ++i)
	{
		cout << maxHeap.getPtr()[i] << " ";
	}
	cout << endl;


	minHeap.insert(1);
	minHeap.insert(2);
	minHeap.insert(3);
	minHeap.insert(4);
	minHeap.insert(3);
	minHeap.insert(232);
	minHeap.insert(5);
	cout << "MIN_HEAP__: ";
	for (int i = 0; i< minHeap.getHeapSize(); ++i)
	{
		cout << minHeap.getPtr()[i] << " ";
	}
	cout << endl;
	minHeap.extractRoot();
	cout << "MIN_HEAP_after_root_deleted: : ";
	for (int i = 0; i< minHeap.getHeapSize(); ++i)
	{
		cout << minHeap.getPtr()[i] << " ";
	}
	cout << endl;
	cin >> n;
}

//static int computeMedian
#undef TEST
int main() 
{
#ifdef TEST
	heapTest();
#endif
}



