#include <stdio.h>

#define MAX_SIZE 5

int queue[MAX_SIZE];
int front = -1;
int rear = -1;
int temp;

//Function to check if the queue is FULL
int queue_full()
{
	if ((front == 0 && rear == MAX_SIZE - 1) || (front == rear + 1))
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Function to check if the queue is EMPTY
int queue_empty()
{
	if (front == rear)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

//Function to insert elements to queue[]
//Input argument: a data to insert
void enqueue(int n)
{
	if (front == -1 && rear == -1)
	{
		front = 0;
		rear = 0;
		queue[rear] = n;
	}
	else
	{
		rear++;
		queue[rear] = n;
	}
}

//Function to delete elements from queue[]
int dequeue()
{
	if (front == -1)
	{
		printf("queue underflow \n");
		return 0;
	}
	else if (front == MAX_SIZE - 1)
	{
		front = 0;
		return 0;
	}
	else
	{
		temp = queue[front];
		front++;
		return temp;
	}
}

//Function to print queue: queue[]
void print_queue()
{
	printf("Queue: ");

	for (int i = 0; i <= MAX_SIZE - 1; i++)  //i <= MAX_SIZE-1 to see all datas in queue
	{
		printf("%d ", queue[i]);
	}

	printf("(Front = %d", front + 1);  //front+1 to see front address easily at console
	printf(" Rear = %d) \n", rear + 1);  //rear+1 to see rear address easily at console
}

//Helper function to run enqueue(int)
//Input argument: a data to insert
void run_enqueue(int n)
{
	printf("Enqueue[%d] -> ", n);

	if (!queue_full())
	{
		if (rear == MAX_SIZE - 1)
		{
			rear = 0;
			queue[rear] = n;
		}
		else
		{
			enqueue(n);
		}

	}
	else if (queue_full())
	{
		printf("queue overflow! \n");

		if (front == 0 && rear == MAX_SIZE - 1)
		{
			rear = 0;
			queue[rear] = n;
		}
		else if (front == rear + 1)
		{
			rear++;
			queue[rear] = n;
		}
	}
	print_queue();
}

//Helper function to run dequeue()
//Input argument: number of elements to delete
void run_dequeue(int n)
{
	printf("Dequeue() -> ");

	for (int i = 0; i < n; i++)
	{
		if (!queue_empty())
		{
			dequeue();
		}
		else
		{
			front = -1;
			rear = -1;
			printf("Queue empty! \n");
		}
		print_queue();
	}
}

int main(void)
{
	print_queue();
	printf("\n");

	run_enqueue(10);
	run_enqueue(50);
	run_enqueue(20);
	run_enqueue(70);
	printf("\n");

	run_dequeue(1);
	printf("\n");

	run_enqueue(100);
	run_enqueue(40);
	printf("\n");

	run_dequeue(3);
	printf("\n");
}