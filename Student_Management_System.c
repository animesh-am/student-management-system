// Written by Animesh Maity
/*-----Date- 9th August 2022
*/
// Student Management System

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 50 // take length of name
#define N 5    // take number of students
struct student
{
    // Student Data
    char name[MAX];
    int studentId;
    int age;
};
struct student s[N];
int nos = 0;
void add() // add new student details
{
    int i;

    printf("How many students to add? ");
    scanf("%d", &nos);
    getchar();
    if (nos <= N)
    {
        for (i = 0; i < nos; i++)
        {

            printf("Enter Student Name:- ");
            scanf(" ");
            fgets(s[i].name, MAX, stdin);
            getchar();
            printf("Enter Student Id:- ");

            scanf("%d", &s[i].studentId);
            getchar();
            printf("Enter Student Age:- ");

            scanf("%d", &s[i].age);
            getchar();
        }
    }
    else
    {
        printf("\nSystem can take upto %d students", N);
        getch();
    }
}

void update() // update student details
{
    int i, sID = 0, c = 0;
    printf("\nEnter the Student ID to update details: ");
    scanf("%d", &sID);

    for (i = 0; i < nos; i++)
    {
        if (s[i].studentId == sID)
        {
            printf("\n ----------------------");
            printf("\n|      1.Name          |");
            printf("\n|      2.Student ID    |");
            printf("\n|      3.Age           |");
            printf("\n ----------------------");
            int ch;
            printf("\nEnter your choice: ");
            scanf(" ");
            scanf("%d", &ch);

            switch (ch)
            {
            case 1:
                printf("\nEnter new name: ");
                scanf(" ");
                fgets(s[i].name, MAX, stdin);
                break;
            case 2:
                printf("\nEnter new student ID: ");
                scanf("%d", &s[i].studentId);
                break;
            case 3:
                printf("\nEnter new age: ");
                scanf("%d", &s[i].age);
                break;
            default:
                printf("\nWrong choice!");
            }
            printf("DETAILS UPDATED!");
            c = 1;
            break;
        }
    }
    if (c != 1)
    {
        printf("\nSTUDENT ID IS NOT IN SYSTEM!");
    }
    getch();
}

void search() // search any student by name or student id
{
    printf("\n -----------------------------");
    printf("\n|    1.Search by name         |");
    printf("\n|    2.Search by student ID   |");
    printf("\n -----------------------------");
    scanf("");
    int ch;
    scanf("");
    printf("\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
    {
        int i, c = 0;
        char n[50];
        printf("\nEnter the NAME of student: ");
        scanf(" ");
        fgets(n, MAX, stdin);

        for (i = 0; i < nos; i++)
        {
            if (!(strcmp(s[i].name, n)))
            {
                printf("\nThe student's details are: ");
                printf("\nName is %s", s[i].name);
                printf("\nStudent ID is %d.", s[i].studentId);
                printf("\nAge is %d.", s[i].age);
                c = 1;
            }
        }
        if (c != 1)
        {
            printf("\nStudent not Found!");
        }
        getch();
        break;
    }
    case 2:
    {
        int rn, i, c = 0;
        printf("\nEnter STUDENT ID to find: ");
        scanf("%d", &rn);

        for (i = 0; i < nos; i++)
        {
            if (s[i].studentId == rn)
            {
                printf("\nThe student's details are: ");
                printf("\nName is %s.", s[i].name);
                printf("\nStudent ID is %d.", s[i].studentId);
                printf("\nAge is %d.", s[i].age);
                c = 1;
            }
        }
        if (c != 1)
        {
            printf("\nStudent not Found!");
        }
        getch();
        break;
    }
    default:
        printf("\nWrong choice!");
    }
}

void show() // show all student's details in the system
{
    // Display Student Data
    int i;
    for (i = 0; i < nos; i++)
    {
        printf("Name is %s", s[i].name);
        printf("Student ID is %d. \n", s[i].studentId);
        printf("Age is %d. \n\n", s[i].age);
    }
    printf("Press enter to continue...");
    getch();
}

int main()
{
    system("color b0");
    int i, ch;
    printf("Written by    \"ANIMESH MAITY\"");

    while (1)
    {
        printf("\n|---------- Student Management System----------|\n");
        printf("|______________________________________________|\n");
        printf("|           1. Add Student                     |\n");
        printf("|           2. Update Student                  |\n");
        printf("|           3. Search Student                  |\n");
        printf("|           4. All Student                     |\n");
        printf("|           5. EXIT                            |\n");
        printf("|           6. CLEAR                           |\n");
        printf("|______________________________________________| \n");

        printf("Enter Your Choice :- ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            add();
            break;

        case 2:
            update();
            break;

        case 3:
            search();
            break;

        case 4:
            show();
            break;
        case 5:
            exit(0);
            break;
        case 6:
            system("cls");
            break;
        default:
            printf("Invalid Choice");
        }
        system("cls");
    }
    scanf("");
    return 0;
}
