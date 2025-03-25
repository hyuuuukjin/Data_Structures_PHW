//PHW1-2
//202235115_¿Â«ı¡¯

#include <stdio.h>

#define MAX_SIZE 5

int queue1[MAX_SIZE];
int queue2[MAX_SIZE];
int front1 = -1;  //front for queue1
int rear1 = -1;  //rear for queue1
int front2 = -1;  //front for queue2
int rear2 = -1;  //rear for queue2

//Function to check if the queue is FULL
int queue_full()
{
	if (rear1 >= MAX_SIZE - 1)
	{
		return 1;
	}

	return 0;
}

//Function to check if the queue is EMPTY
int queue_empty()
{
	if (front1 == -1 && rear1 == -1)
	{
		return 1;
	}

	return 0;
}

//Function to check if the queue is EMPTY
//If it is empty, reset front and rear.
int queue_empty2()
{
	if (front2 - 1 == -1 && rear2 - 1 == -1)
	{
		front2 = -1;
		rear2 = -1;

		return 1;
	}

	return 0;
}

//Function to print queue: int queue1[]
void print_queue1()
{
	printf("Queue = ");

	for (int i = front1; i <= rear1; i++)
	{
		printf("%d ", queue1[i]);
	}

	printf("( Front = %d, ", front1);
	printf("Rear = %d ) \n", rear1);
}

//Function to print queue: int queue2[]
void print_queue2()
{
	printf("Queue = ");

	for (int i = front2; i <= rear2; i++)
	{
		printf("%d ", queue1[i]);
	}

	printf("( Front = %d, ", front2);
	printf("Rear = %d ) \n", rear2);
}

//Function to enqueue elements to queue1[]
//Input argument: an element to enqueue newly
void enqueue(int n)
{
	if (front1 == -1)
	{
		front1++;
	}
	rear1++;

	queue1[rear1] = n;
}

//Function to duplicate queue1 to queue2 except the last data, and set front2,  rear2
void enqueue2(int n)
{
	if (front2 == -1 && rear2 == -1)
	{
		front2 = front1 - 1;
		rear2 = rear1;
	}

	for (int i = 0; i <= rear2 - 1; i++)  //duplicate queue1 excpet the last data
	{
		queue2[i] = queue1[i];
		queue1[i] = queue2[i];
	}

	if (queue_empty2())
	{
		printf("Queue Empty! \n");
	}
	else
	{
		rear2--;
		front1 = front2;
		rear1 = rear2;
		print_queue2();
	}
}

//Function to dequeue elements from queue1[]
int dequeue()
{
	int temp = queue1[front1];

	if (front1 == rear1)  //checking if the queue is empty and if it is, reset variables 'int front' and 'int rear'
	{
		front1 = -1;
		rear1 = -1;
	}
	else
	{
		front1++;
	}

	return temp;
}

//Helper function to run enqueue(int)
//Input argument: an array to use elements from
//Input argument: number of elements to enqueue
void run_enqueue(int nums[], int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("Enqueue(%d) -> ", nums[i]);

		if (!queue_full())
		{
			enqueue(nums[i]);
		}
		else
		{
			printf("Queue FULL! \n");

			return;
		}

		print_queue1();
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
			enqueue2(dequeue());
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
	int nums[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	print_queue1();
	printf("\n");

	run_enqueue(nums, 5);
	run_dequeue(5);
	printf("\n");

	run_enqueue(nums, 3);
	run_dequeue(3);
	printf("\n");

	return 0;
}