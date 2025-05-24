#include <iostream>

#include <random>

using namespace std;

//creating main game function

void game(int random_number){

    cout<<"make a random guess between 1 to 100"<<endl; //taking initial input 

    int guess;

    cin>>guess;

    while(guess!=random_number){

        if(guess>random_number){ //if guess is greater than number 
            
            if(guess-random_number <10){

                cout<<"Too close but go little bit Low, Guess again!"<<endl;

                cin>>guess;

            }

            else{

                cout<<"Too High, Guess again!"<<endl;

                cin>>guess;

            }
        }
        else if(guess<random_number){//if guess is less than number

            if(random_number-guess <10){

                cout<<"Too close but go little bit High, Guess again!"<<endl;

                cin>>guess;

            }

            else{

                cout<<"Too Low, Guess again!"<<endl;

                cin>>guess;

            }
        }

    }

    cout<<"BINGO! YOU GUESSED THE RIGHT NUMBER"<<endl;

    return;

}

int main(){

    random_device rd; // Seed the random generator

    mt19937 gen(rd()); // Mersenne Twister generator

    uniform_int_distribution<> distr(1,100); // Range [1, 100]

    int random_number = distr(gen);
    
    game(random_number);
    
}