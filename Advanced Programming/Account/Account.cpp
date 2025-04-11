
#include <iostream>
#include <string>

using namespace std;

class Account{

private:

    int AccountID;
    string Family;
    float Balance;

public:

    Account(int=0,string="no name",float=0);
    void setID(int);
    void setFamily(string);
    void setBalance(float);
    int getID();
    string  getFamily();
    float getBalance();
    void setAccount(int ,string ,float );
    void Withdraw(float);
    void Deposit(float);
    void print();
    
};


Account::Account(int a,string f,float b){

    setAccount(a,f,b);
    
}
//_____________________________________________________
void Account::setAccount(int a,string f,float b){

    if(b>=10){

          setID(a);
          setFamily(f);
          setBalance(b);
        
    }

    else{

        AccountID=0;
        Family="no name";
        Balance=0;

    }
}
//_____________________________________________________
void Account::setID(int a){

    AccountID=a;
}
//______________________________________________________
void Account::setFamily(string f){

    Family=f;
}
//______________________________________________________
void Account::setBalance(float b){

    if(b>=10){

        Balance=b;
    }
}
//_______________________________________________________
int Account::getID(){

    return(AccountID);
    
}
//______________________________________________________
string  Account::getFamily(){

    return(Family);
}
//________________________________________________________
float Account::getBalance(){

    return(Balance);
}
//________________________________________________________
void Account::Withdraw(float w){

    float ba=Balance-w;

    if(ba>=10){

           Balance-=w;
        
    }
}
//_______________________________________________________
void Account::Deposit(float d){

    if(d>=0){

        Balance+=d;
        
    }
}
//_________________________________________________________
void Account::print(){

    cout<<AccountID<<"\n"<<Family<<"\n"<<Balance<<endl;
}
//_________________________________________________________
int main() {

    int ID;
    float more,less,balance;
    string family;
   
//    cout<<"please enter AccountID:"<<endl;
    cin>>ID;

//    cout<<"please enter Family:"<<endl;
    cin>>family;

//    cout<<"please enter Balance:"<<endl;
    cin>>balance;

    Account A(ID,family,balance);

    if(balance>=10){

        cin>>more;
        cin>>less;
        A.Deposit(more);
        A.Withdraw(less);
       
    
    }
    
    A.print();
//    system("pause");
    return 0;
}
