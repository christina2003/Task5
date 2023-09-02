#include <stdio.h>
#include <stdlib.h>

#define MAX_TASKS 100

typedef struct {
    int id;
    char description[100];
} Task;

Task taskList[MAX_TASKS];  //array to store tasks
int numTasks = 0;          //Number of tasks currently stored


// Function to add new tasks to the task manager
void addTask() {
    Task newTask;

    printf("Enter task description: ");
    fgets(newTask.description, sizeof(newTask.description), stdin);
    newTask.description[strcspn(newTask.description, "\n")] = '\0';

    newTask.id = numTasks + 1;

    taskList[numTasks] = newTask;
    numTasks++;

    printf("Task added successfully!\n");
}


// Function to display the tasks currently stored in the task manager
void viewTasks() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    printf("Current Tasks:\n");
    for (int i = 0; i < numTasks; i++) {
        printf("Task ID: %d\n", taskList[i].id);
        printf("Description: %s\n\n", taskList[i].description);
    }
}


// Function to remove a task from the task manager based on the input ID by user
void removeTask() {
    if (numTasks == 0) {
        printf("No tasks found.\n");
        return;
    }

    int taskId;
    printf("Enter task ID to remove: ");
    scanf("%d", &taskId);

    int foundIndex = -1;
    for (int i = 0; i < numTasks; i++) {
        if (taskList[i].id == taskId) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < numTasks - 1; i++) {
            taskList[i] = taskList[i + 1];
        }

        numTasks--;
        printf("Task removed successfully!\n");
    } else {
        printf("Task ID not found.\n");
    }
}

int main() {
    int option;

    do {
        printf("Minions Task Manager\n");
        printf("1. Add Task\n");
        printf("2. View Tasks\n");
        printf("3. Remove Task\n");
        printf("4. Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);
        getchar(); // Clear the newline character from the input buffer

        switch (option) {
            case 1:
                addTask();
                break;
            case 2:
                viewTasks();
                break;
            case 3:
                removeTask();
                break;
            case 4:
                printf("Exiting Minions Task Manager. Have a great day!\n");
                break;
            default:
                printf("Invalid option. Please try again.\n");
                break;
        }

        printf("\n");

    } while (option != 4);

    return 0;
}
