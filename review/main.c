#include <stdio.h>

void reset(int *x, int *y);

int main(void)
{
    char name[5];
    printf("Enter a name: ");
    // scanf("%4s", name);
    fgets(name, 5, stdin);

    printf("%s", name);
    return 0;
}

void reset(int *x, int *y)
{
    *x = 0;
    *y = 0;
}

// STRUCTS OLD
//
// #include <stdio.h>
//
// // only variables can go in structs
// struct myStruct
// {
//     int x;
//     int y;
// } typedef my_struct;
//
// void myStructMethod(my_struct* myStructRef);
//
// void myFunct(char *arr)
// {
//     printf("%zu", sizeof(arr));
// }
//
// int main(void)
// {
//     // struct myStruct myStruct1 = {.y = 4, .x = 1};
//     my_struct myStruct1 = {.y = 4, .x = 1};
//     myStructMethod(&myStruct1);
//
//     printf("Size of struct: %zu\n",sizeof(myStruct1));
//
//     int x = 10;
//     int *p = &x;
//     printf("%d", *p + 5);
//
//     char list[] = {'a', 'b', 'c', 'd'};
//     myFunct(list);
//
//
//     return 0;
// }
//
// void myStructMethod(my_struct *myStructRef)
// {
//     // these two are the same. -> is just syntactic sugar
//     printf("%d\n", (*myStructRef).y);
//     // arrow dereferences..
//     // arrows are specifically for structs....
//     printf("%d\n", myStructRef->y);
// }
