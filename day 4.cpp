#include<iostream> 
#include<cmath>
using namespace std;
class Rectangle{
    private:
        int* width = new int;
        int* heigth = new int;
        int* left = new int[2];
        int* top = new int[2];
        int* area =new int;
    public:
        Rectangle(int width, int heigth, int left[], int top[]) {
            *this->width = width;
            *this->heigth = heigth;
            this->left[0] = left[0];
             this->left[1] = left[1];
            this->top[0] = top[0];
            this->top[1] = top[1];
            *area=width * heigth;
        }
        Rectangle(float width, float heigth, float left[], float top[]){
            //cout << typeid(height).name() << endl;
            *this->width = round(width);
            *this->heigth = round(heigth);
            this->left[0] = round(left[0]);
            this->left[1] = round(left[1]);
            this->top[0] = round(top[0]);
            this->top[1] = round(top[1]);
            *area=(*this->width) * (*this->heigth);
        }
        Rectangle (const Rectangle& temp){
            *width=*temp.width;
            *heigth=*temp.heigth;
            left[0]=temp.left[0];
            left[1]=temp.left[1];
            top[0]=temp.top[0];
            top[1]=temp.top[1];
            *area=(*temp.width) * (*temp.heigth);
        }
        void print(){
            cout<<"Rectangle: Widhth = "<<*width<<" Height = "<<*heigth<<" left = ("<<left[0]<<","<<left[1]<<") top = ("<<top[0]<<","<<top[1]<<") Area: "<<*area<<endl;
        }
        ~Rectangle(){
            //cout<<"Deleting  ..."<<endl;
            delete width;
            delete heigth;
            delete []left;
            delete []top;
            delete area;
        }
};
int main(){
    Rectangle iobj(4,5, new int[2]{1,2} , new int[2]{3,3});
    iobj.print();
    Rectangle fobj(3.4,5.7,new float[2]{8.4,2.7} , new float[2]{5.5,3.9});
    fobj.print();
    Rectangle copyobj(iobj);
    copyobj.print();
    return 0;
}