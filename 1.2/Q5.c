#include <stdio.h>

typedef struct student {
    int age;
} Student;

int isyounger(Student, Student);

int main(int argc, char const *argv[])
{
    Student stud1, stud2;
    printf("Student 1 age: ");
    scanf("%d", &stud1.age);
    printf("Student 2 age: ");
    scanf("%d", &stud2.age);

    if(isyounger(stud1, stud2)) {
        printf("Student 1 is younger than Student 2\n");
    } else {
        printf("Student 1 is not younger than Student 2\n");
    }

    return 0;
}

int isyounger(Student one, Student two)
{
    int flag = 0;
    if(one.age == two.age) {
        flag = 1;
    }

    return flag;
}