#include<iostream>
#include<ctime>
using namespace std;

class Market{
    public :
    double cash;
    int stock;
    double profit;
    Market(double val){
        cash = val;
        stock=0;
        profit=0.0;
    }
};
double generateprice(){
    double price =100.0;
    double change = (rand()%500-100)/100.0;
    double tprice = price + change;
    return tprice;
}

void buy(double &cash ,double price , int qty , int &stock){
    stock+=qty;
    double bought=price*qty;
    cout<<"Buy "<<qty<<" stock at price "<<bought<<endl<<endl;
    cash -=bought;
}

void sell(double &cash ,double price ,int &stock , int qty){
    double sold = price*qty;
    stock -= qty;
    cout<<"Sell "<<qty<<" stock at price "<<sold<<endl<<endl;
    cash +=sold;
}

bool trade(double tprice ,double &cash , int &stock){
    int qty=0;
    if(tprice<100){
        qty=(int)cash/tprice;
        if(qty>0){
            buy(cash ,tprice,qty,stock);
        }
        return true;
    }
    if(stock>0 && tprice>102){
        qty = stock;
        sell(cash ,tprice , stock , qty);
        return true;
    }
    return false;
}

void display(double cash , int stock){
    cout<<"Displaying info ---"<<endl;
    cout<<"Cash = "<<cash<<endl;
    cout<<"Stock = "<<stock<<endl;
    cout<<endl;
}

int main(){
    srand(time(0));
    Market m(1000);
    for(int i=0;i<100;i++){
        double price = generateprice();
        if(trade(price , m.cash , m.stock)){
            cout<<"current market price : "<<price<<endl;
            display(m.cash , m.stock);
        }  
    }
    return 0;
}

