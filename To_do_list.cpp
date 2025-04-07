#include<iostream>
#include<vector>
using namespace std;
struct Tasks{
    string description;
    bool completed;
};

void displaytasks(const vector<Tasks> &tasks){
    cout<<endl;
    if(tasks.empty()){
        cout<<"No Task at this time !"<<endl;
        return ;
    }
    else{
        cout<<"TO-DO LISTS "<<endl;
        for(size_t i=0;i<tasks.size() ; i++){
            cout<<i+1 <<". "<<(tasks[i].completed ? "[✔] ": "[ ] ")<<tasks[i].description<<endl;
        }
    }
}

void addtask(vector<Tasks> &tasks){
    cout<<endl;
    string desc;
    cout<<"Enter the task description : ";
    cin.ignore();
    getline(cin,desc);
    tasks.push_back({desc , false});
    cout<<"Task added !"<<endl;
}

void markasdone(vector<Tasks> &tasks){
    displaytasks(tasks);
    cout<<endl;
    if(tasks.empty()){
        return ;
    }
    int index;
    cout<<"Enter the task number to marks as done :";
    cin>>index;

    if(index>0 && index<=tasks.size()){
        tasks[index - 1].completed = true;
        cout<<"Marked as completed !"<<endl;
    }
    else{
        cout<<"Invalid index number !"<<endl;
    }
}

void removetasks(vector<Tasks> &tasks){
    displaytasks(tasks);
    cout<<endl;
    if(tasks.empty()){
        return ;
    }

    int index;
    cout<<"Enter the tasks to remove : ";
    cin>>index;

    if(index >0 && index <=tasks.size()){
        tasks.erase(tasks.begin() + index-1);
        cout<<"TAsks Removed !"<<endl;
    }
    else{
        cout<<"Invalid index number !"<<endl;
    }
}

int main(){
    vector<Tasks> tasks;
    int choice;

    while(true){
        cout<<"\nChoose one of the following option :"<<endl;
        cout<<"1. Add tasks "<<endl;
        cout<<"2. view Tasks "<<endl;
        cout<<"3. Marks task as done "<<endl;
        cout<<"4. Remove task "<<endl;
        cout<<"5. Exit. "<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;

        switch(choice){

            case 1 : 
            addtask(tasks);
            break;

            case 2:
            displaytasks(tasks);
            break;

            case 3:
            markasdone(tasks);
            break;

            case 4:
            removetasks(tasks);
            break;

            case 5:
            cout<<"Bye bye......!"<<endl;
            return 0;

            default:
            cout<<"Invalid choice !"<<endl;
        }
    }
    return 0;
}
