#include <stdio.h>

struct Student
{
    char set;
    float gpa;
    char name[10];
};

int main(void)
{
    struct Student stu1 = {.gpa = 66.6, .set = 'D', .name = "Daisy"};
    printf("Name: %s\nSet: %c\nGPA: %.2f\n", stu1.name, stu1.set, stu1.gpa);

    struct Student stu2 = {'C', 89.6, "Lano"};
    printf("Name: %s\nSet: %c\nGPA: %.2f\n", stu2.name, stu2.set, stu2.gpa);

    struct Student stu3;
    stu3.gpa = 78.94;
    // stu3.name = "Cleo";
    stu3.set = 'C';

    printf("Name: %s\nSet: %c\nGPA: %.2f\n", stu3.name, stu3.set, stu3.gpa);

    return 0;
}
