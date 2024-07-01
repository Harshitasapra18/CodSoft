#include<iostream>
#include<cstdlib>
#include<ctime>
int main(){
    srand(time(0));
    int randomNumber = rand() % 100 + 1;
    int userGuess;
    int attempts=0;
    std::cout<<"NUMBER GUESSING GAME STARTED"<<std::endl;
    while(true){
        std::cout<<"GUESS A NUMBER BETWEEN 1 TO 100 : ";
        std::cin>>userGuess;
        attempts++;
        if(userGuess>randomNumber){
            std::cout<<"TRY AGAIN AS IT IS TOO HIGH  "<<std::endl;
        }else if(userGuess<randomNumber){
            std::cout<<"TRY AGAIN AS IT IS TOO LOW "<<std::endl;
        }else{
            std::cout<<"CONGRATULATIONS IT IS TRUE YOU GUESSED THE CORRECT NUMBER IN   "<< attempts <<" "  <<" ATTEMPTS "<<std::endl;
            break;
        }
    }
    return 0;
}  