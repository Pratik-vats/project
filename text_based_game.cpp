#include<iostream>
#include<ctime>
using namespace std;
class game {
    public :
    int number, round;
    int coin = 100;
    char choice;
    int  totalround = 0;
    int lose = 0;
    int tier1 =0,tier2=0,tier3=0,tier4=0,tier5=0;

    void display(){
        cout<<"You have initially 100 Coins !"<<endl;
        cout<<"RULES :-"<<endl;
        cout<<"tier 1 - +10 coins\n";
        cout<<"tier 2 - +20 coins\n";
        cout<<"tier 3 - +30 coins\n";
        cout<<"tier 4 - +40 coins\n";
        cout<<"tier 5 - +50 coins\n";
        cout<<"Else : -10 coins\n";
    }
    void play(){
        do{
        cout<<"Available Rounds = "<<coin/10<<endl;
        cout<<"Number of times you want to play  :: ";
        cin>>round;
        totalround += round;
        cout<<endl;
        if(round*10 >coin){
            cout<<"Insufficient coin !"<<endl;
            break;
        }
        for(int i=0 ; i<round ; i++){
        number = rand() % 100;
        if(number>=0 && number <=50){
            cout<<"better luck next time !"<<endl;
            coin = coin - 10;
            lose+=1;
        }
        else if(number>50 && number<=75){
            cout<<"you won tier 1 gear !"<<endl;
            coin = coin + 10;
            tier1+=1;
        }
        else if(number>75 && number<=90){
            cout<<"you won tier 2 gear !"<<endl;
            coin = coin + 20;
            tier2+=1;
        }
        else if(number > 90 && number<=95){
            cout<<"you won tier 3 gear !"<<endl;
            coin = coin + 30;
            tier3+=1;
        }
        else if (number>95 && number<=98){
            cout<<"you won tier 4 gear !"<<endl;
            coin = coin + 40;
            tier4+=1;
        }
        else{
            cout<<"you won tier 5 gear !"<<endl;
            coin = coin + 50;
            tier5+=1;
        }
        cout<<"Coin = "<<coin<<"\n\n";
        }
        if(coin>0){
            cout<<"Do you want to continue(Y/N) :";
            cin>>choice;
        }
        if(choice == 'N' || choice == 'n'){
            cout<<"\nThanks for playing !\n"<<endl;
            break;
        }
        }while(coin>0);
    }
    void summary(){
        cout<<"Summary :-\n";
        cout<<"Total round played = "<<totalround<<endl;
        cout<<"Total Win : "<< tier1 + tier2 + tier3 + tier4 + tier5 <<endl;
        cout<<"Tier 1 : "<<tier1<<endl;
        cout<<"Tier 2 : "<<tier2<<endl;
        cout<<"Tier 3 : "<<tier3<<endl;
        cout<<"Tier 4 : "<<tier4<<endl;
        cout<<"Tier 5 : "<<tier5<<endl;
        cout<<"Total loss : "<<lose<<endl;
        cout<<"Remaining Coins is "<<coin<<"\n\n";
        cout<<"XXXXXXX------XXXXXXX";
    }
};
int main(){ 
    srand(time(0));
    game g;
    g.display();
    g.play();
    g.summary();

    return 0;
}
