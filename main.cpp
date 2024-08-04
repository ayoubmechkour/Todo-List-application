#include <iostream>
#include <string>
#include <limits>

using namespace std;

class Todo {
private:
    static const int array_size = 3;
    string tasks[array_size];
    int task_count = 0;
    int option = -1;

public:
    void start();
    void Display_task();
    void Add_task();
    void Delete_task();
};

void Todo::Display_task() {
    if (task_count == 0) {
        cout << "There are no tasks!" << endl;
    } else {
        cout << "-----------Your tasks: --------------" << endl;
        for (int i = 0; i < task_count; i++) {
            cout << "Task " << i + 1 << " : " << tasks[i] << endl;
        }
    }
}

void Todo::Add_task() {
    if (task_count >= array_size) {
        cout << "The list is full!" << endl<<endl;
    } else {
        cout << "Enter a new task: ";
        cin.ignore();
        getline(cin, tasks[task_count]);
        task_count++;
    }
}

void Todo::Delete_task() {
    int delete_task = 0;
    cout << "Input the task number you want to delete: ";
    cin >> delete_task;
    if (delete_task <= 0 || delete_task > task_count) {
        cout << "Invalid task number!" << endl;
    } else {
        for (int i = delete_task - 1; i < task_count - 1; i++) {
            tasks[i] = tasks[i + 1];
        }
        task_count--;
        cout << "Task " << delete_task << " has been deleted." << endl;
    }
}

void Todo::start() {
    do {

        cout << "---------------Todo list-------------" << endl;
        cout << "1- Add_task" << endl;
        cout << "2- Display_tasks" << endl;
        cout << "3- Delete_task" << endl;
        cout << "0- Exit" << endl;
        cout << "-------------------------------------" << endl;
        cout << "--> ";

        while (!(cin >> option) || option < 0 || option > 3) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input, please enter a valid option (0-3): ";
        }

        cout << endl << endl;

        switch (option) {
            case 1:
                Add_task();
                break;
            case 2:
                Display_task();
                break;
            case 3:
                Delete_task();
                break;
            case 0:
                cout << "Have a productive day!" << endl;
                break;
            default:

                break;
        }

    } while (option != 0);
}

int main() {
    Todo doit;
    doit.start();
    return 0;
}
