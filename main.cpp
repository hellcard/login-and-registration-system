// login and registration system

#include <iostream>
#include <fstream>
#include <string>

bool is_login(){
    std::string username, password, un, pw;
    std::cout<<"Enter a username: ";     std::cin>>username;
    std::cout<<"\nEnter a password: ";   std::cin>>password;

    std::ifstream read("data_"+username+".txt");

    std::getline(read, un);
    std::getline(read,pw);
    if(username == un && password == pw){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int choice;

    std::cout<<"1. Register\n2. Login\nYour choice: ";
    std::cin>>choice;
    std::cout<<std::endl;

    switch(choice){
        case 1:
            {std::string username, password;
            std::cout<<"Enter a username: ";
            std::cin>>username;
            std::cout<<"\nEnter a password: ";
            std::cin>>password;
            std::cout<<std::endl;
            std::ofstream file;
            file.open("data_"+username+".txt");
            file<<username<<std::endl<<password;
            file.close();
            main();
            }
            break;
        case 2:
            if(!is_login()){
                std::cout<<"\nsuch user does not exist\n"<<std::endl;
                main();
            }
            else{
                std::cout<<"\nyou have successfully logged in"<<std::endl;
            }
            break;
        default:
            std::cout<<"there is no such choice\n"<<std::endl;
            main();
    }
    return 0;
}
