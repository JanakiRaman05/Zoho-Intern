#include<iostream>
#include<vector>
using namespace std;
class mobile{
    public:
    mobile(){
        // empty constructor for vector
    }
    long long int phnumber,bill;
    mobile(long long int phnumber,int bill){
        this->phnumber = phnumber;
        this->bill = bill;
    }
};
class landline{
    public:
        int bill;
        string lannumber;
        landline(){
            // empty constructor for vector
        }
        landline(string lannumber,int bill){
            this->bill = bill;
            this->lannumber = lannumber;
        }
};
class templates : public mobile,public landline{
    private:
        vector<mobile> mobile_data;
        vector<landline> landline_data;
    public:
        // decide whether it is a mobile or landline connection
        bool decide(string val){
            if(val[0]== '0' )
                return false;
            else 
                return true;
        }
        // string to long long number
        long long int convert (string str){
            long long int ans=0;
            for(int i=0;i<str.length();i++){
                ans=(ans*10)+(str[i]-48);
            }
            return  ans;
        }
        // Adding data 
        void add (string val){
            if(decide(val)){
                mobile_add(convert(val));
            } else {
                landline_add(val);
            }
        }
        // Adding Mobile Connection
        void mobile_add(long long int number){
            bool flag = true;
            //cout<<"Inside Mobile Connection: "<<number<<" size "<<mobile_data.size()<<endl;
            for(int i=0; i<mobile_data.size(); i++){ 
                if(mobile_data[i].phnumber == number){
                    cout<<"Your Mobile Connection Number: "<<number<<" already Exsit "<<endl;
                    flag = false;
                }
            }
            if(flag){
                cout<<"Your Mobile Connection Number: "<<number<<" Added Successfully "<<endl;
                mobile_data.push_back(mobile(number,0));
            } 
        }
        // Adding Land Line connections
         void landline_add(string number){
            bool flag = true;
            for(int i=0; i<landline_data.size(); i++){
                if(!(landline_data[i].lannumber.compare(number))){
                    cout<<"Your Land Line Connection Number: "<<number<<" already Exsit "<<endl;
                    flag = false;
                }
            }
            if(flag){
                cout<<"Your Land Line Connection Number: "<<number<<" Added Successfully "<<endl;
                landline_data.push_back(landline(number,0));
            }
        }
        //Paying function
        void pay (string val){
            if(decide(val)){
                mobile_pay(convert(val));
            } else {
                landline_pay(val);
            }
        }
        // Paying Mobile bills
        void mobile_pay (long long int number) {
            bool flag = true;
            for(int i=0; i<mobile_data.size(); i++){
                if(mobile_data[i].phnumber == number){
                    cout<<"Your Mobile Connection Number: "<<mobile_data[i].phnumber;
                    cout<<" Your Bill Amount: "<<mobile_data[i].bill<<" Paid "<<endl;
                    mobile_data[i].bill=0;
                    flag = false;
                }
            }
            if(flag)
                cout<<"Your Mobile Connection Number: "<<number<<" Do not exist "<<endl;
        }
        // Paying Land Line bills
        void landline_pay (string number) {
            bool flag = true;
            for(int i=0; i<landline_data.size(); i++){
                if(!(landline_data[i].lannumber.compare(number))){
                    cout<<"Your Land line Connection Number: "<<landline_data[i].lannumber;
                    cout<<" Your Land line Bill Amount: "<<landline_data[i].bill<<" Paid "<<endl;
                    landline_data[i].bill=0;
                    flag = false;
                }
            }
            if(flag)
                cout<<"Your Connection Number: "<<number<<" Do not exist "<<endl;
        }
        // Updatig bill 
        void update(string val){
            int amount;
            cout<<"Enter the Bill Amount For Connection Number "<<val<<" : ";
            cin>>amount;
            if(decide(val)){
                mobile_update(convert(val),amount);
            } else {
                landline_update(val,amount);
            }
        }
        // Updatig mobile bill
        void mobile_update (long long int number,int amount){ 
            bool flag = true;
            for(int i=0; i<mobile_data.size(); i++){
                if(mobile_data[i].phnumber == number){
                    cout<<"Your Mobile Connection Number: "<<mobile_data[i].phnumber;
                    mobile_data[i].bill+=amount;
                    cout<<" Your Bill Amount: "<<mobile_data[i].bill<<" Updated "<<endl;
                    flag = false;
                }
            }
            if(flag)
                cout<<"Your Mobile Connection Number: "<<number<<" Do not exist "<<endl;
        }
        // Updatig Land Line bill
        void landline_update (string number,int amount) {
            bool flag = true;
            for(int i=0; i<landline_data.size(); i++){
                if(!(landline_data[i].lannumber.compare(number))){
                    cout<<"Your Land line Connection Number: "<<landline_data[i].lannumber;
                    landline_data[i].bill+=amount;
                    cout<<" Your Land line Bill Amount: "<<landline_data[i].bill<<" Updated "<<endl;
                    flag = false;
                }
            }
            if(flag)
                cout<<"Your Connection Number: "<<number<<" Do not exist "<<endl;
        }
        // Printing all connections
        void print(){
            cout<<"Mobile Connection \n";
            for(int i=0;i<mobile_data.size();i++){
                cout<<i+1<<". Mobile Connection number: "<<mobile_data[i].phnumber<<" Bill Amount: "<<mobile_data[i].bill<<endl;
            }
            cout<<"\nLand Line connection \n";
            for(int i=0;i<landline_data.size();i++){
                cout<<i+1<<". Land Line Connection number: "<<landline_data[i].lannumber<<" Bill Amount: "<<landline_data[i].bill<<endl;
            }
        }
}template_obj;
int main(){
    cout<<"Adding connection..."<<endl;
    template_obj.add("0944301231");
    template_obj.add("9443012317");
    template_obj.add("0874301231");
    template_obj.add("8743012317");
    cout<<"\nAdding existing connection..."<<endl;
    template_obj.add("0944301231");
    template_obj.add("9443012317");
    cout<<"\nUpdating connection..."<<endl;
    template_obj.update("0944301231");
    template_obj.update("9443012317");
    cout<<"\nPaying connection..."<<endl;
    template_obj.pay("0944301231");
    template_obj.pay("9443012317");
    cout<<"\nPrinting connection..."<<endl;
    template_obj.print();
    return 0;
}