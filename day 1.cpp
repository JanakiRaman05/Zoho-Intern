#include<iostream>
using namespace std;
enum Vehicletype {
	petrol,
	diesel,
	electric
};
enum Biketype {
	scooter,
	MotorCycle
};
enum Cartype{
	suv,
	sedan
};
class vehicle{
	private:
	Vehicletype vehicle_Type;
	string brand,model,color;
    float price,mileage;
	public:
	vehicle(){
	}
	vehicle(Vehicletype vehicle_Type,string brand,string model,string color,float price,float mileage){
		this->vehicle_Type=vehicle_Type;
		this->brand=brand;
		this->model=model;
		this->color=color;
		this->price=price;
		this->mileage=mileage;
	}
	friend ostream &operator<<(ostream &out, const vehicle& vehicle){
		cout<<"Brand: "<<vehicle.brand<<" Model: "<<vehicle.model<<" Color: "<<vehicle.color<<" Price: "<<vehicle.price<<endl;
		return cout;
	}
	bool operator < (const vehicle& vehicle){
		return this->price<vehicle.price;
	}
	bool operator > (const vehicle& vehicle){
		return this->price>vehicle.price;
	}
    virtual void getNoOFWheels() = 0;
    
};
class car : public vehicle{
	private:
	int no_of_persons;
	Cartype  car_Type;
	public:
	car(Vehicletype vehicle_Type,string brand,string model,string color,float price,float mileage,int no_of_persons,Cartype car_Type)
	:vehicle(vehicle_Type,brand,model,color,price,mileage){
		this->no_of_persons=no_of_persons;
		this->car_Type=car_Type; 	
	}
	void getNoOFWheels(){
		cout<<"No of Wheels = 4"<<endl;
	}
};
class bike : public vehicle{
	private:
    int weigth;
    Biketype Bike_Type;
	public:
    bike(Vehicletype vehicle_Type,string brand,string model,string color,float price,float mileage,Biketype Bike_Type,int weigth)
	:vehicle(vehicle_Type,brand,model,color,price,mileage){
		this->Bike_Type=Bike_Type;
		this->weigth=weigth;
	}
    void getNoOFWheels(){
		cout<<"No of Wheels = 2"<<endl;
	}
};
int main(){
	car cobj1(petrol,"Susiki","E10","Black",12,13,7,suv);
	car cobj2(diesel,"Toyata","E11","white",10,15,7,sedan);
	bike bobj1(petrol,"Honda","E12","blue",9,20,scooter,45);
	bike bobj2(electric,"Tvs","E13","greem",11,14,MotorCycle,35);
	// << overloading 
	cout<<cobj1;
	cout<<cobj2;
	cout<<bobj1;
	cout<<bobj2;

	// get no of wheels function
	cobj1.getNoOFWheels();
	cobj2.getNoOFWheels();
	bobj1.getNoOFWheels();
	bobj2.getNoOFWheels();

	// < & > overloading
	if(cobj1>cobj2){
		cout<<"Susiki is greater than Toyata\n";
	}else{
		cout<<"Toyata is greater than Susiki\n";
	}
	if(bobj1<bobj2){
		cout<<"Tvs is greater than Honda";
	} else {
		cout<<"Honda is greater than Tvs";
	}
    return 1;
}
