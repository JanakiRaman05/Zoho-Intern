#include<iostream>
using namespace std;
string banks[]={"Private","Public"};
enum loan_type{
    goldloan,
    landloan,
    personalloan
};
string loans[]={"goldloan","landloan","personalloan"};
class bank{
    private:
    bool Banktype;
    string name,estdate,branchname;
    public:
    bank(){
        //Empty bank structure
    }
    bank(bool Banktype,string name,string estdate,string branchname) {
        this->Banktype = Banktype;
        this->name = name;
        this->estdate = estdate;
        this->branchname = branchname;
    }
    string getName() { return name; }
    string getEstablisedDate() { return estdate; }
    string getBanktype() { return banks[Banktype]; }
    void getinfo(){
        cout<<"Bank type : "<<banks[Banktype]<<" Name "<<name<<" Establised Date "<<estdate<<endl;
    }
    bool gettype() { return Banktype; }
    string getname() { return name; }
    string getdate() { return estdate;}
};
class loan{
    private:
    int interestRate;
    string documentsreq;
    loan_type loantype;
    public:
    loan(int interestRate,string documentsreq,loan_type loantype){
        this->interestRate = interestRate;
        this->documentsreq = documentsreq;
        this->loantype= loantype;
    }
    int getInterestRate() { return interestRate; }
    string getDocumentsreq() { return documentsreq; }   
    void loaninfo(){
        cout<<"Interest Rate: "<<interestRate<<" Documents: "<<documentsreq<<endl;    
    }
    int getrate() { return interestRate; }
    string getdoc() { return documentsreq; }
    string getloantype() { return loans[loantype]; }

};
class HDFC: public bank,public loan{
    public:
    HDFC(bool Banktype,string estdate,string branchname,int interestRate,string documentsreq,loan_type loantype)
    : bank(Banktype,"HDFC",estdate,branchname),loan(interestRate,documentsreq,loantype){
        // empty constructor
    }
    void getinfo(){
        cout<<"Bank type : "<<banks[gettype()]<<" Name "<<getname()<<" Establised Date "<<getdate();
        cout<<" Interest Rate: "<<getrate()<<" Documents: "<<getdoc()<<" Loan type: "<<getloantype()<<endl;
    }
};
class ICICI: public bank,public loan{
    public:
    ICICI(bool Banktype,string estdate,string branchname,int interestRate,string documentsreq,loan_type loantype)
    : bank(Banktype,"ICICI",estdate,branchname),loan(interestRate,documentsreq,loantype){
        // empty constructor
    }
    void getinfo(){
        cout<<"Bank type : "<<banks[gettype()]<<" Name "<<getname()<<" Establised Date "<<getdate();
        cout<<" Interest Rate: "<<getrate()<<" Documents: "<<getdoc()<<" Loan type: "<<getloantype()<<endl;
    }
};
class SBI: public bank,public loan{
    public:
    SBI(bool Banktype,string estdate,string branchname,int interestRate,string documentsreq,loan_type loantype)
    : bank(Banktype,"SBI",estdate,branchname),loan(interestRate,documentsreq,loantype){
        // empty constructor
    }
    void getinfo(){
        cout<<"Bank type : "<<banks[gettype()]<<" Name "<<getname()<<" Establised Date "<<getdate();
        cout<<" Interest Rate: "<<getrate()<<" Documents: "<<getdoc()<<" Loan type: "<<getloantype()<<endl;
    }
};
class INDIAN: public bank,public loan{
    public:
    INDIAN(bool Banktype,string estdate,string branchname,int interestRate,string documentsreq,loan_type loantype)
    : bank(Banktype,"INDIAN",estdate,branchname),loan(interestRate,documentsreq,loantype){
        // empty constructor
    }
    void getinfo(){
        cout<<"Bank type : "<<banks[gettype()]<<" Name "<<getname()<<" Establised Date "<<getdate();
        cout<<" Interest Rate: "<<getrate()<<" Documents: "<<getdoc()<<" Loan type: "<<getloantype()<<endl;
    }
};
class Broker {
    public:
    void compare(bank bank1,int first,bank bank2 ,int second){
        if(first<second)
            bank1.getinfo();
        else  
            bank2.getinfo();
    }
    void compare(bank bank1,int first,bank bank2 ,int second,bank bank3,int third){
        if(first>second){
            if(second>third){
                bank3.getinfo();
            } else{
                bank2.getinfo();
            }
        } else {
            if(first>third){
                bank3.getinfo();
            } else {
                bank1.getinfo();
            }
        }
    }
    void compare(bank bankarray[],int rate[],int n){
        int min = 0;
        for(int i=0;i<n;i++){
            if(rate[min]>rate[i]){
                min=i;
            }
        }
        bankarray[min].getinfo();
    }
    void print(bank temp){
        temp.getinfo();
    }
    void print(bank bankarray[],int n){
        for(int i=0;i<n;i++){
            bankarray[i].getinfo();
        }    
    }
};
int main(){
    HDFC hobj(1,"13.6.2002","Virudhunagar",11,"Adhar",goldloan);
    ICICI iciobj(0,"14.6.2002","Virudhunagar",2,"pan card",landloan);
    SBI sbiobj(1,"15.6.2002","Virudhunagar",10,"drive card",personalloan);
    INDIAN indiobj(0,"16.6.2002","Virudhunagar",9,"pan card",landloan); 
    cout<<"\nValues\n\n";
    hobj.getinfo();
    iciobj.getinfo();
    sbiobj.getinfo();
    indiobj.getinfo(); 
    cout<<"\n\n";
    Broker bobj;
    // two objects comparison
    cout<<endl<<"Single Comaparison"<<endl;
    bobj.compare(hobj,hobj.getrate(),iciobj,iciobj.getrate());
    // three objects comparison
    cout<<endl<<"Three Comparison"<<endl;
    bobj.compare(hobj,hobj.getrate(),iciobj,iciobj.getrate(),sbiobj,sbiobj.getrate());
    // n objects comparison
    cout<<endl<<"N Objects"<<endl;
    bank bankarray[] = {hobj,iciobj,sbiobj,indiobj};
    int rate [] = {hobj.getrate(),iciobj.getrate(),sbiobj.getrate(),indiobj.getrate()};
    bobj.compare(bankarray,rate,4);
    // printing single bank details
    cout<<endl<<"Single print"<<endl;
    bobj.print(hobj);
    // printing multiple bank details
    cout<<endl<<"Multiple print"<<endl;
    bobj.print(bankarray,4);
    return 0;
}
