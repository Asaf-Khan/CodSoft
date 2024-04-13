#include<iostream>
#include<limits>


using namespace std;
//FUNCTION TO BE USED.
void calculate(float a,float b);

int main()
{
    float num1,num2;
    cout<<"------------------Welcome to Simple Calculator------------------"<<endl; 
    cout<<"Enter first number : ";
    while(!(cin>>num1))
    {
            cout<<"wrong input. Try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
            
    }
    system("cls");
    cout<<"Now enter the second : ";
    while(!(cin>>num2))
    {
            cout<<"wrong input. Try again : ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
    }
    system("cls");    
    calculate(num1,num2);

    return 0;
}
//Function for calculations.
void calculate(float a,float b)
{
    char select;
 
    cout<<"\n----------------CALCULATOR----------------"<<"\n"
        <<"1.Additon\n2.Subtraction\n3.Multiplication\n4.Division\n"<<"\n"
        <<"Enter operation number : ";
    cin>>select;
 
    switch (select)
    {
    case '1':
        system("cls");
        cout<<"Sum is : "<<a+b<<endl;
        break;
    case '2':
        system("cls");
        cout<<"Difference is : "<<a-b<<endl;
        break;
    case '3':
        system("cls");
        cout<<"Product is : "<<a*b<<endl;
        break;
    case '4':
        if(b==0)
        {
            system("cls");
            cout<<"UNDEFINE "<<endl;
        }
        else
        {
            system("cls");
        cout<<"Division is : "<<a/b<<endl;
        }
        break;
    default:
        system("cls");
        cout<<"Wrong input !!"<<endl;
        calculate(a,b);
        break;
    }

}