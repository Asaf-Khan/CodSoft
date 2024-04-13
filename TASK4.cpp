#include<iostream>
#include<string>
#include<limits>

using namespace std;

//FUNCTIONS TO BE USED.
int TaskInput();
void AddTasks(string array[],int size);
void ViewTasks(string array[],int size);
void TaskComplete(string array[],int size);
void RemoveTask(string array[],int size);

int main()
{
    cout<<"******************TO-DO LIST******************"<<endl;

    int size = TaskInput();
    string Todolist[size];
    AddTasks(Todolist,size);
    char choice;

    do
    {
        cout<<"==============MENU=============="<<"\n\n"
            <<"1-> Mark Task as Completed.\n"
            <<"2-> Remove Task.\n"
            <<"3-> View Tasks.\n"
            <<"4-> Exit.\n";
        cin>>choice;
        system("cls");
        switch (choice)
        {
        case '1':
            TaskComplete(Todolist,size);
            break;
        case '2':
            RemoveTask(Todolist,size);
            break;
        case '3':
            ViewTasks(Todolist,size);
            break;
        case '4':
            cout<<"Have a Good Day :) "<<endl;
            break;
        default:
            cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^"<<endl;
            break;
        }
    }while(choice != '4');

    return 0;    
}
//Function for getting number of tasks.
int TaskInput()
{
    int tasks; 
    cout<<"Enter number of Tasks :";
    while(!(cin>>tasks))
    {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    while (tasks <= 0)
    {
       cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
        while(!(cin>>tasks))
        {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
    }
    
    system("cls");
    return tasks;
}
//Function for adding tasks.
void AddTasks(string array[],int size)
{    
    cin.ignore();
    for(int i = 0;i<size;i++)
    {
    cout<<"Task "<<i+1<<" : ";
    getline(cin,array[i]);

    system("cls");
    }
    
}
//Function for viewing tasks.
void ViewTasks(string array[],int size)
{
    for(int i = 0;i<size;i++)
    {
    cout<<"Task "<<i+1<<" :"<<"\n\n";
    cout<<array[i]<<endl;
    }
}
//Function for marking tasks as completed.
void TaskComplete(string array[],int size)
{
    int task;
    ViewTasks(array,size);
    cout<<"Which Task is completed : ";
    while(!(cin>>task))
    {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    task -= 1;
    while (!(task >=0 && task<size))
    {
       cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
        while(!(cin>>task))
        {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
       task -= 1;
    }
    
    array[task] += " (Completed)";
}
//Function for removing tasks.
void RemoveTask(string array[],int size)
{
    int task;
    ViewTasks(array,size);
    cout<<"Which Task do you want to remove : ";
    while(!(cin>>task))
    {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    task -= 1;
     while (!(task >=0 && task<size))
    {
       cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
        while(!(cin>>task))
        {
         cout<<"Invalid Input !!!\n\t\tNo worries try again ^_^ :";
         cin.clear();
         cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
       task -= 1;
    }
    
    array[task] = "-";
}
