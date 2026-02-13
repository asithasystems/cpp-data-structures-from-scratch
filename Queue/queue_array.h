#include <iostream>
using namespace std;

class Q_arry
{
private:
	int capacitor=4;
	int front=0;
	int rear=-1;
	int arr[4];

	
public:
	void enqueue(int x)
	{
		if (rear > capacitor - 1)
		{
			cout << "queue is full" << endl;
		}
		else
		{
			arr[rear + 1] = x;
			rear++;
		}

	}
	int dequeue()
	{
		front++;
		return arr[front-1];
	}

	void display()
	{
		for (int i = front; i <= rear; i++)
		{
			cout << arr[i] << "  ";
		}
		cout << endl;
	}



};