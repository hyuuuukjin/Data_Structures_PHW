//Lab 1-2
//202235115_¿Â«ı¡¯

#include <stdio.h>

#define MAX_SIZE 10

int queue[MAX_SIZE];  //global array of size 10
int front = -1;
int rear = -1;

//Function to check if the queue is FULL
int queue_full()
{
	if (rear >= MAX_SIZE - 1)
	{
		return 1;
	}

	return 0;
}

//Function to check if the queue is EMPTY
int queue_empty()
{
	if (front == -1 && rear == -1)
	{
		return 1;
	}

	return 0;
}

//Function to enqueue elements to queue[]
//Input argument: an element to enqueue newly
void enqueue(int n)
{
	if (front == -1)
	{
		front++;
	}
	rear++;

	queue[rear] = n;
}

//Function to dequeue elements from queue[]
int dequeue()
{
	int temp = queue[front];

	if (front == rear)  //checking if the queue is empty and if it is, reset variables 'int front' and 'int rear'
	{
		front = 0;
		rear = 0;
	}
	else
	{
		front++;
	}

	return temp;
}

void print_queue()  //Function to print queue: int queue[]
{
	printf("Queue = ");

	for (int i = 0; i <= rear; i++)
	{
		printf("%d ", queue[i]);
	}

	printf("( Front = %d, ", front);
	printf("Rear = %d ) \n", rear);
}

//Helper function to run enqueue(int)
//Input argument: an array to use elements from
//Input argument: number of elements to enqueue
void run_enqueue(int nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enque(%d) -> ", nums[i]);

		if (!queue_full())
		{
			enqueue(nums[i]);
		}
		else
		{
			printf("Queue FULL! \n");

			return;
		}

		print_queue();
	}

}

//Helper function to run dequeue()
//Input argument: number of elements to dequeue
void run_dequeue(int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Dequeue() -> ");

		if (!queue_empty())
		{
			dequeue();
			print_queue();
		}
		else
		{
			printf("Queue EMPTY! \n");

			return;
		}
	}
}

int main(void)
{
	int nums[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };

	print_queue();
	printf("\n");

	run_enqueue(nums, 5);
	run_dequeue(3);
	printf("\n");

	run_enqueue(nums, 10);
	run_dequeue(11);
	printf("\n");

	run_enqueue(nums, 3);
	printf("\n");

	print_queue();

	return 0;
}