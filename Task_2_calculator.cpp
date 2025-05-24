#include <iostream>

using namespace std;

//Calculator function for calculation

double calc(double num1,double num2,char operation){

    double res;

    switch(operation)
    {
    case '+':
        
        res = num1+num2;
        break;

    case '-':
        
        res = num1-num2;
        break;

    case '*':
        
        res = num1*num2;
        break;

    case '/':
        if(num2!=0){

            res = num1/num2;
    
        }

        else{

            res = 1;
            cout<<"INVALID INPUT! Denominator cannot be less than 1"<<endl;
            return res;

        }
        break;

    default:

        cout<< "INVALID OPERATOR! Choose a valid operator";
        break;
    }

    return res;
}

int main(){

    cout<<"\t\t\t\t\t SIMPLE CALCULATOR!"<<endl;
    double num1,num2;
    char operation;
    char choice = 'y';

    while(choice == 'y'){
        
        cout<<"Enter two real numbers: "<<endl;
        cin>>num1>>num2;
        cout<<"Enter operation: ";
        cin>>operation;
        cout<<"Result =>  "<<calc(num1,num2,operation)<<endl;
        cout<<"Do You want further calculations y/n : ";
        cin>>choice;
    
    }

    return 0;

}