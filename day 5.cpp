#include<iostream>
using namespace std;
namespace space{
    class classequ{
    public:
        int val1=3,val2=5;
        void print(){
            cout<<"val1: "<<val1<<endl;
            cout<<"val2: "<<val2<<endl;
        }
    };
    inline namespace math{
        int add(int x, int y) { return x+y;}
        int sub(int x, int y) { return x-y;}
        int mul(int x, int y) { return x*y;}
        int div(int x, int y) { return x/y;}
    }
}
// namespace alliase 
namespace solve=space::math;
class derive_namaespace{
    public:
        void calc(){
            cout<<"Inside class  Add : "<<solve::add(20,2)<<endl;
            cout<<"Inside class  Sub : "<<solve::sub(20,2)<<endl;
            cout<<"Inside class  Mul : "<<solve::mul(20,2)<<endl;
            cout<<"Inside class  Div : "<<solve::div(20,2)<<endl;
        }
}deriveobj;
int main(){ 
    cout<<"namespace alliase Add : "<<solve::add(5,3)<<endl;
    cout<<"namespace alliase Sub : "<<solve::sub(4,3)<<endl;
    cout<<"namespace alliase Mul : "<<solve::mul(4,3)<<endl;
    cout<<"namespace alliase Div : "<<solve::div(5,3)<<endl<<endl;
    cout<<"Inline Name Space Add : "<<space::add(40,5)<<endl;
    cout<<"Inline Name Space Sub : "<<space::sub(40,5)<<endl;
    cout<<"Inline Name Space Mul : "<<space::mul(40,5)<<endl;
    cout<<"Inline Name Space Div : "<<space::div(40,5)<<endl<<endl;
    deriveobj.calc();   
    return 0;
}