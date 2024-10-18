#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#define MAX_COURSES 5
#define MAX_STUDENTS 100
#define MAX_NAME_LENGTH 10

struct student
{
    int id;
    char name[50];
    int attendance[MAX_COURSES];
};

struct student students[MAX_STUDENTS];
int num_students = 0;

// Function prototypes
void login();
void insert_student_details();
void display_all_details();
void search_specific_information();
void delete_or_modify_student_detail();
void save_data();
void load_data();

// Main function
int main()
{
    // num_students = 0;

    load_data();

    printf("Welcome To Student Attendance Calculator \n");
    printf("Login To Proceed\n");

    login();

    while (1)
    {
        printf("\nAttendance Calculator Menu:\n");
        printf("1. Insert details of student\n");
        printf("2. Display all details\n");
        printf("3.Search specific information\n");
        printf("4. Delete/modify any student detail\n");
        printf("5. Save and exit\n\n");

        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            insert_student_details();
            break;
        case 2:
            display_all_details();
            break;
        case 3:
            search_specific_information();
            break;
        case 4:
            delete_or_modify_student_detail();
            break;
        case 5:
            save_data();
            return 0;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to handle login
void login()
{
    char username[50], password[50];

    // Prompt the user to enter their username and password
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    // Check if the username and password are correct
    if (strcmp(username, "pranu") == 0 && strcmp(password, "pass") == 0)
    {
        printf("Login successful.\n");
    }
    else
    {
        printf("Invalid username or password. Exiting...\n");
        getch();
        exit(0);
    }
}

// Function to insert student details
void insert_student_details()
{
    if (num_students >= MAX_STUDENTS)
    {
        printf("Maximum number of students reached. Cannot add more students.\n");
        return;
    }

    printf("\nEnter details for student %d:\n", num_students + 1);
    printf("Enter Registration number : ");
    scanf("%d", &students[num_students].id);
    printf("Enter name: ");
    scanf("%s", students[num_students].name);

    printf("Enter attendance for each course:\n");
    int i;
    for ( i = 0; i < MAX_COURSES; i++)
    {
        printf("Course %d: ", i + 1);
        scanf("%d", &students[num_students].attendance[i]);
    }

    num_students++;

    printf("Student details added successfully.\n");
}

// Function to display all student details
void display_all_details()
{
    if (num_students == 0)
    {
        printf("No students added yet.\n");
        return;
    }

    // Display the header
    printf("\n%-5s %-20s", "ID", "Name");
    int i;
    for ( i = 0; i < MAX_COURSES; i++)
    {
        printf(" Course %d", i + 1);
    }
    printf("\n");

    // Display the student details
    //int i,j;
    for ( i = 0; i < num_students; i++)
    {
        printf("%-5d %-20s", students[i].id, students[i].name);
        int j;
        for ( j = 0; j < MAX_COURSES; j++)
        {
            printf(" %8d", students[i].attendance[j]);
        }
        printf("\n");
    }
}

// Function to search for specific student information
void search_specific_information()
{
    // Check if there are any students
    if (num_students == 0)
    {
        printf("No students added yet.\n");
        return;
    }

    // Prompt the user to enter the student ID to search for
    int search_id;
    printf("Enter the student ID to search for: ");
    scanf("%d", &search_id);

    // Search for the student with the given ID
    int found = 0;
    int i;
    for ( i = 0; i < num_students; i++)
    {
        if (students[i].id == search_id)
        {
            // Display the student details
            printf("\nDetails for student with ID %d:\n", search_id);
            printf("Name: %s\n", students[i].name);
            printf("Attendance:\n");
            int j;
            for ( j = 0; j < MAX_COURSES; j++)
            {
                printf("Course %d: %d\n", j + 1, students[i].attendance[j]);
            }
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("No student with ID %d found.\n", search_id);
    }
}

// Function to delete or modify student details
void delete_or_modify_student_detail()
{
    // Check if there are any students
    if (num_students == 0)
    {
        printf("No students added yet.\n");
        return;
    }

    // Prompt the user to enter the student ID to delete/modify
    int search_id;
    printf("Enter the student ID to delete/modify: ");
    scanf("%d", &search_id);

    // Search for the student with the given ID
    int found = 0;
    int index,i;
    for ( i = 0; i < num_students; i++)
    {
        if (students[i].id == search_id)
        {
            found = 1;
            index = i;
            break;
        }
    }

    if (!found)
    {
        printf("No student with ID %d found.\n", search_id);
        return;
    }

    // Display the student details and prompt the user for action
    printf("\nDetails for student with ID %d:\n", search_id);
    printf("Name: %s\n", students[index].name);
    printf("Attendance:\n");
    int j;
    for ( j = 0; j < MAX_COURSES; j++)
    {
        printf("Course %d: %d\n", j + 1, students[index].attendance[j]);
    }
    printf("\nWhat do you want to do?\n");
    printf("1. Delete this student\n");
    printf("2. Modify attendance for a course\n");
    // Prompt the user for action
    int choice;
    printf("Enter your choice (1 or 2): ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        // Delete the student
        //int i,index;
        for ( i = index; i < num_students - 1; i++)
        {
            students[i] = students[i + 1];
        }
        num_students--;
        printf("Student with ID %d deleted.\n", search_id);
        break;
    case 2:
        // Modify attendance for a course
        printf("Enter the course number (1 to %d) to modify attendance for: ", MAX_COURSES);
        int course_num;
        scanf("%d", &course_num);
        if (course_num < 1 || course_num > MAX_COURSES)
        {
            printf("Invalid course number.\n");
            return;
        }

        printf("Enter the new attendance for course %d: ", course_num);
        int new_attendance;
        scanf("%d", &new_attendance);
        students[index].attendance[course_num - 1] = new_attendance;
        printf("Attendance for course %d modified for student with ID %d.\n", course_num, search_id);
        break;

    default:
        printf("Invalid choice.\n");
    }
}

void save_data()
{
    // Open the files for writing
    FILE *name_file = fopen("student_names.txt", "a");
    FILE *attendance_file = fopen("student_attendance.txt", "a");

    // Write the data to the files
    int i,j;
    for ( i = 0; i < num_students; i++)
    {
        fprintf(name_file, "%d %s\n", students[i].id, students[i].name);
        for ( j = 0; j < MAX_COURSES; j++)
        {
            fprintf(attendance_file, "%d ", students[i].attendance[j]);
        }
        fprintf(attendance_file, "\n");
    }

    fclose(name_file);
    fclose(attendance_file);

    printf("Data saved to files.\n");
}

void load_data()
{
    FILE *name_file = fopen("student_names.txt", "r");
    FILE *attendance_file = fopen("student_attendance.txt", "r");

    if (name_file == NULL && attendance_file == NULL)
    {
        printf("The files are empty");
    }
    else
    {
        while (!feof(name_file))
        {
            int id;
            char name[MAX_NAME_LENGTH];
            fscanf(name_file, "%d %s", &id, name);

            students[num_students].id = id;
            strcpy(students[num_students].name, name);
			int j;
            for ( j = 0; j < MAX_COURSES; j++)
            {
                fscanf(attendance_file, "%d", &students[num_students].attendance[j]);
            }
            fscanf(attendance_file, "\n");

            num_students++;
        }
    }

    fclose(name_file);
    fclose(attendance_file);
}
