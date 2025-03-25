//PHW 1-3
//202235115_¿Â«ı¡¯

#include <stdio.h>

#define MAX_SIZE 5

int stack[MAX_SIZE];
int stack2[MAX_SIZE];
int top = -1;
int top2 = -1;

//Function to check if the stack is FULL
int stack_full()
{

    if (top >= MAX_SIZE - 1)
    {
        return 1;
    }

    return 0;
}

//Function to check if the stack1 is Empty
int stack_empty()
{

    if (top == -1)
    {
        return 1;
    }

    return 0;
}

//Function to check if the stack2 is Empty
int stack2_empty()
{

    if (top2 == -1)
    {
        return 1;
    }

    return 0;
}

//Function to print queue that made with stacks
void print_queue()
{
    printf("Queue: ");

    for (int i = top2; i >= 0; i--)
        printf("%d ", stack2[i]);
    for (int i = 0; i <= top; i++)
        printf("%d ", stack[i]);
    printf("\n");
}

//Function to insert data to stack1
void push(int n)
{
    if (!stack_full())
        stack[++top] = n;
    else
        printf("Queue is full!\n");
}

//Function to delete data from stack1
int pop()
{
    if (!stack_empty())
        return stack[top--];

    printf("Queue is empty!\n");

    return -1;
}

//Function to insert data to stack2
void push2(int n)
{
    if (top2 < MAX_SIZE - 1)
        stack2[++top2] = n;
}

//Function to delete data from stack2
int pop2()
{
    if (!stack2_empty())
        return stack2[top2--];

    return -1;
}

// helper function: run push
// input arguments: int arr[] <- an array from which input values are taken
// input arguments: int num <- total number of elements to push
void run_push(int arr[], int num)
{
    for (int i = 0; i < num; i++) {
        printf("enqueue(%d): -> ", arr[i]);

        if (!stack_full())
            push(arr[i]);
        else
            printf("Queue is full!\n");

        print_queue();
    }
}

// helper function: run pop
// input argument: total number of elements to pop
void run_pop(int num)
{
    for (int i = 0; i < num; i++)
    {
        if (!stack_empty())
        {
            push2(pop());
        }
        else
        {
            printf("Queue is empty!\n");
        }
    }
}

//Function to insert data to the queue that made with stacks
void enqueue(int n)
{
    push(n);
}

//Function to delete data from the queue that made with stacks
int dequeue()
{
    if (stack2_empty())
    {
        run_pop(top + 1);
    }

    return pop2();
}

int main()
{
    int nums[] = { 1, 2, 3, 4, 5 };

    run_push(nums, 3);
    print_queue();
    printf("\n");

    for (int i = 0; i < 2; i++)
    {
        printf("dequeue(%d) ", dequeue());
        print_queue();
    }

    run_push(nums, 2);
    print_queue();
    printf("\n");

    while (!stack_empty() || !stack2_empty())
    {
        printf("dequeue() -> %d\n", dequeue());

        print_queue();
    }

    return 0;
}
