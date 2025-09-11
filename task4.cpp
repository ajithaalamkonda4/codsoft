#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to hold each task
struct Task {
    string description;
    bool completed;
};

// Function to display all tasks
void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks available.\n";
        return;
    }

    cout << "\n=== To-Do List ===\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description 
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

// Function to add a new task
void addTask(vector<Task>& tasks) {
    Task newTask;
    cout << "\nEnter task description: ";
    cin.ignore(); // clear input buffer
    getline(cin, newTask.description);
    newTask.completed = false;
    tasks.push_back(newTask);
    cout << "Task added successfully!\n";
}

// Function to mark a task as completed
void markTaskCompleted(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "\nEnter task number to mark as completed: ";
    cin >> index;

    if (index >= 1 && index <= (int)tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

// Function to remove a task
void removeTask(vector<Task>& tasks) {
    int index;
    viewTasks(tasks);
    if (tasks.empty()) return;

    cout << "\nEnter task number to remove: ";
    cin >> index;

    if (index >= 1 && index <= (int)tasks.size()) {
        tasks.erase(tasks.begin() + index - 1);
        cout << "Task removed successfully!\n";
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    do {
        cout << "\n=== To-Do List Menu ===\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "Exiting... Goodbye!\n"; break;
            default: cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
