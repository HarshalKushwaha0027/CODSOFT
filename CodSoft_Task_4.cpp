#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct Task
{
    string description;
    bool status;
    Task(const string& task_name) : description(task_name),status(false){}
};

class  ToDoList
{
private:

    vector<Task> todo;

public:

    void addtoList(const string& task_name){

        todo.push_back(Task(task_name));
        cout<<"\t Your Task added successfully to the List!! \n";

    }

    void viewList(){

        cout<<"Tasks : \n";
        for(size_t i = 0;i<todo.size();i++){
            cout<<i+1<<".) "<<todo[i].description;
            if(todo[i].status){
                cout<<"  ( This Task is already completed!! )";
            }
            cout<<endl;
        }
    }

    void mark(size_t index){
        if(index >= 1 && index <= todo.size()){
            todo[index-1].status = true;
            cout<<"Task marked as completed.\n";
        }

        else{
            cout<<"Invalid index!!\n";
        }
    }

    void remove(size_t index){
        if(index >= 1 && index <= todo.size()){
            todo.erase(todo.begin()+index);
            cout<<"Task deleted.\n";
        }

        else{
            cout<<"Invalid index!!\n";
        }
    }
};


int main(){

    ToDoList todoID;

    int option;

    do {

        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. Mark Task as Completed\n";
        cout << "3. Display Tasks\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        cin >> option;

        switch (option) {

            case 1: {
                string details;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, details);
                todoID.addtoList(details);
                break;
            }
            case 2:{
                size_t taskIndex;
                cout << "Enter task index to mark as completed: ";
                cin >> taskIndex;
                todoID.mark(taskIndex);
                break;
            }
            case 3: 
			    todoID.viewList();
                break;
            case 4: {
                size_t taskIndex;
                cout << "Enter task index to remove: ";
                cin >> taskIndex;
                todoID.remove(taskIndex);
                break;
            }
            case 5:
                cout << "Exiting from program.\n";
                break;
            default:
                cout << "Invalid choice of operation. Please choose from the above options.\n";
        }
        
    } while (option != 5);

    return 0;

}
