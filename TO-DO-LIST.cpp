#include <iostream>
#include <vector>

using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back({description, false});
}

void viewTasks(const vector<Task>& tasks) {
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i].description << " ["
             << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        tasks[index].completed = true;
    }
}

void removeTask(vector<Task>& tasks, size_t index) {
    if (index < tasks.size()) {
        tasks.erase(tasks.begin() + index);
    }
}

int main() {
    vector<Task> tasks;
    int choice;
    string description;

    do {
        cout << "\n1. Add Task\n2. View Tasks\n3. Mark Task as Completed\n4. Remove Task\n5. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                size_t index;
                viewTasks(tasks);
                cout << "Enter task number to mark as completed: ";
                cin >> index;
                markTaskCompleted(tasks, index - 1);
                break;
            case 4:
                viewTasks(tasks);
                cout << "Enter task number to remove: ";
                cin >> index;
                removeTask(tasks, index - 1);
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
