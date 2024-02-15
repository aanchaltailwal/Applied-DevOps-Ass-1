#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 10
#define MAX_TASK_LENGTH 50

typedef struct {
    char description[MAX_TASK_LENGTH];
    int completed;
} Task;

Task tasks[MAX_TASKS];
int numTasks = 0;

void addTask(char* description) {
    if (numTasks < MAX_TASKS) {
        strcpy(tasks[numTasks].description, description);
        tasks[numTasks].completed = 0;
        numTasks++;
        printf("Task added successfully!\n");
    } else {
        printf("Cannot add task. Maximum number of tasks reached.\n");
    }
}

void displayTasks() {
    printf("To-Do List:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("%d. [%s] %s\n", i + 1, tasks[i].completed ? "X" : " ", tasks[i].description);
    }
}

void markComplete(int index) {
    if (index >= 0 && index < numTasks) {
        tasks[index].completed = 1;
        printf("Task marked as completed!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

void deleteTask(int index) {
    if (index >= 0 && index < numTasks) {
        for (int i = index; i < numTasks - 1; i++) {
            strcpy(tasks[i].description, tasks[i + 1].description);
            tasks[i].completed = tasks[i + 1].completed;
        }
        numTasks--;
        printf("Task deleted successfully!\n");
    } else {
        printf("Invalid task number!\n");
    }
}

int main() {
    char description[MAX_TASK_LENGTH];
    int choice, index;

    do {
        printf("\n1. Add Task\n2. Display Tasks\n3. Mark Task as Complete\n4. Delete Task\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter task description: ");
                scanf(" %[^\n]s", description);
                addTask(description);
                break;
            case 2:
                displayTasks();
                break;
            case 3:
                printf("Enter task number to mark as complete: ");
                scanf("%d", &index);
                markComplete(index - 1);
                break;
            case 4:
                printf("Enter task number to delete: ");
                scanf("%d", &index);
                deleteTask(index - 1);
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
