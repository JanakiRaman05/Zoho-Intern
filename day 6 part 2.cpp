#include<iostream>
using namespace std;
void error(int a,int b,string word,int index,int c,int d){
    try{
        if(b==0){
            throw 0;
        } else{
             cout<<"Divide Value : "<<a/b<<" No Error! , outside try/catch";
        }   
        try {
            if(index<word.length()){
                cout<<"\nLetter : "<<word[index]<<" No Error! , inside try/catch"<<endl;
            } else {
                throw 1;
            }
         } catch(...){
            cout<<"\nError : String out of index , catch fucntion in inside catch.";
            // Rethrowing exception
            if(d==0){
                throw 1;
                cout<<"\nrethrowing exception";
            } else{
                cout<<" Inner divide value = "<<c/d<<endl;
            }
         }
    } catch(int n){
        if(n==0){
            cout<<"Error : Divide by zero , Catch function in outside catch"<<endl;
        } else{
            cout<<"Rethrow Error : Divide by zero , Catch function in outside catch"<<endl;
        } 
    }
}
int main(){
    cout<<"Case 1: no error!"<<endl;
    error(10,2,"words",2,7,2);
    cout<<"\nCase 2: outer try catch error!"<<endl;
    error(1,0,"words",2,6,2);
    cout<<"\nCase 3: inner try catch error!"<<endl;
    error(10,2,"words",5,3,1);
    cout<<"\nCase 4: Rethrow the Catched expression !"<<endl;
    error(10,2,"words",5,4,0);
    return 0;
}