#include<iostream>
#include<cstdlib>
#include<ctime>
#include<limits>

using namespace std;
//FUNCTION TO BE USED.
int GenerateNumber();

int main()
{
    int guess;
    int randomNumber = GenerateNumber();
    cout<<"------------Welcome to Guess number game------------"<<"\n\n\n";
    do
    {
        cout<<"Enter a NUMBER : ";
        while(!(cin>>guess))
        {
            cout<<"Wrong input \nNo worries try again :";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(),'\n');
        }
      
        if(guess == randomNumber)
        {
            cout<<" \nYou have Guessed it RIGHT :)"<<endl;
        }
        else if(guess>randomNumber)
        {
           cout<<" \nYour guess is HIGH  :("<<endl;
             cout<<" \nNo worries try again\n "<<endl; 
        }
        else if(guess<randomNumber)
        {
           cout<<" \nYour guess is LOW  :("<<endl; 
             cout<<" \nNo worries try again\n "<<endl;

        }
        else
        {
            cout<<"\nWRONG INPUT !!!"<<endl;
            cout<<" \nNo worries try again\n "<<endl;
        }
    }while(guess != randomNumber);
    
    return 0;
}
//Function for generating random number between 0-10.
int GenerateNumber()
{
    int generate;
    
    srand(time(NULL));
    generate = rand() % 10 +1;

    return generate;
}
