#include<iostream>
using namespace std;
string courselist[] = {"CIVIL","IT","CS","ECE","EEE"};
class AgeNotWithinRangeException: public exception{
    public:
    const char * what() const throw(){
        return "AgeNotWithinRangeException";
    }
};
class NameNotValidException: public exception{
    public:
    const char * what() const throw(){
        return "NameNotValidException";
    }
};
class InvalidCouseException: public exception{
    public:
    const char * what() const throw(){
        return "InvalidCouseException";
    }
}; 
class TooManyObject: public exception{
    public:
    const char * what() const throw(){
        return "TooManyObjectsException\n";
    }
}; 
class Student{
    private:
        static bool count;
        int rollno,age;
        string name,course;
    public:
        Student(int rollno,int age,string course,string name){
            //cout<<"Constructor"<<endl;
            // Limit the number of student Object
                if(!count){
                    TooManyObject val;
                    cout<<val.what();
                    throw val;
                }
            this->rollno=rollno;
            // Age Check
            try{
                if(age<15 || age>21){
                    AgeNotWithinRangeException var;
                    throw var;
                } else {
                    //cout<<"Age = "<<age<<"\n";
                    this->age=age;
                }
            } catch(exception& e){
                cout<<e.what()<<endl;
            }   
            //cout<<"age Complete"<<endl;
            // Name Check
            try{
                bool flag=true;
                for(int i=0;i<name.length();i++){
                    if(!((name[i]>='a' && name[i]<='z') || (name[i]>='A' && name[i]<='Z'))){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    this->name=name;
                } else{
                    NameNotValidException val;
                    throw val;   
                }
            } catch(exception& e){
                cout<<e.what()<<endl;
            }
            //cout<<"Name Complete"<<endl;
            // Course Check
            try{
                bool flag = false;
                for(int i=0;i<4;i++){
                    if(!(courselist[i].compare(course))){
                        flag = true;
                    }
                }
                if(flag){
                    this->course=course;
                } else {
                    InvalidCouseException val;
                    throw val;
                }
            } catch(exception& e){
                cout<<e.what()<<endl;
            }  
            //cout<<"courese completed"<<endl;
            count = false;
        }
};
bool Student::count=true;
using namespace std;   
int main(){
    // Age Error
    
    //Student obj(21,5,"CIVIL","Jhon");
    
    // Name Error

    //Student obj(21,20,"CIVIL","Jhon");

    // course Error

    //Student obj(21,20,"AI","Jhon");

    // Too many students

    Student obj1(21,20,"CIVIL","Jhon");
    Student obj2(21,20,"CIVIL","Jhon"); 
    
    return 0;
}