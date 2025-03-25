#include <stdio.h>

#define MAX_SIZE 10



int stack[MAX_SIZE];

int top = -1;



int stack_full() {

    if (top >= MAX_SIZE - 1)

        return 1;

    return 0;

}



int stack_empty() {

    if (top == -1)

        return 1;

    return 0;

}



void push(int x) {

    top++;

    stack[top] = x;

}



int pop() {

    int temp = stack[top];


    top--;

    return temp;

}



// helper function: print the current stack

void print_stack() {

    printf("stack = ");

    for (int i = 0; i <= top; i++)

        printf(" %d", stack[i]);

    printf(" (top=%d)\n", top);

}



// helper function: run a series of pushes

// input arguments: int arr[] <- an array from which input values are taken

// input arguments: int num <- total number of elements to push

void run_pushes(int arr[], int num) {

    for (int i = 0; i < num; i++) {

        printf("push(%d) , ", arr[i]);

        if (!stack_full()) {

            push(arr[i]);

        }

        else {

            printf("stack full! ");

        }

        print_stack();


    }

}



// helper function: run a series of pops

// input argument: int num <- total number of elements to pop

void run_pops(int num) {

    int value;

    for (int i = 0; i < num; i++) {

        printf("pop() ");

        if (!stack_empty()) {

            value = pop();

            printf("-> %d , ", value);

        }

        else {

            printf("stack empty! ");

        }

        print_stack();

    }

}



int main() {

    int numbers[] = { 3, 9, 4, 5, 2, 1, 6, 8, 7, 5, 8 };



    print_stack();

    run_pushes(numbers, 5);


    run_pops(3);

    run_pushes(numbers, 10);

    run_pops(15);

}