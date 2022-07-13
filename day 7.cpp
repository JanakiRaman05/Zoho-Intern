#include<iostream>
#include<vector>
#include<tuple>
using namespace std;
//vector to store state of sensor
vector<tuple <float,bool,float,bool,bool,bool,bool,bool,bool>> status;
enum sensor{
    Temprature_Sensor,
    Water_level_Sensor,
    Motion_Sensor,
    Gas_Detections_Sensor,
    Fan,
    Light,
    Door    
};
string sensors[]={"Temprature_Sensor","Water_level_Sensor","Motion_Sensor","Gas_Detections_Sensor","Fan","Light","Door"};
// pairing class deals with connecting and disconnecting sensor
class pairing{
    private:
            bool connect = false;
    public:
    void connection(int x){
        if(connect){
            cout<<sensors[x]<<" Already connected"<<endl;
        } else {
            cout<<sensors[x]<<" Connecting"<<endl;
            connect=true;
        }
    }
    void disconnection(int x){
        if(connect){
            cout<<sensors[x]<<" disconnecting "<<endl;
            connect=false;
        } else {
            cout<<sensors[x]<<" Already disconnected"<<endl;
            connect=false;
        }
    }   
    bool checkconnections(){
        return connect;
    }
};
// Temprature Sensor
class Temprature : public pairing{
    private:
        float curtemp;
        bool state=true;
    public:
        bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
        void setcurtemp(float val){
            curtemp=val;
        }
        float getcurtemp(){
            return curtemp;
        }
        void on(){
        if(checkconnections()){
            cout<<"Temprature_Sensor Turned ON"<<endl;
            state=true;
        } else {
            connection(0);
            cout<<"Temprature_Sensor Turned ON"<<endl;
            state=true;
        }
     }
        void off(){
        if(checkconnections()){
            cout<<"Temprature_Sensor Turned OFF"<<endl;
            state=false;
        } else {
            connection(0);
            cout<<"Temprature_Sensor Turned OFF"<<endl;
            state=false;
        }
     }
}t1;
// Waterlevel sensor
class Waterlevel : public pairing{
    private:
        float waterheight;
        bool state = true;
    public:
        void setheight(float height) {
            waterheight=height;
        }
        float getheight(){
            return waterheight;
        }
        bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
        void on(){
        if(checkconnections()){
            cout<<"Water_level_Sensor Turned ON"<<endl;
            state=true;
        } else {
            connection(1);
            cout<<"Water_level_Sensor Turned ON"<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
            cout<<"Water_level_Sensor Turned OFF"<<endl;
            state=false;
        } else {
            connection(1);
            cout<<"Water_level_Sensor Turned OFF"<<endl;
            state=false;
        }
     }
}w1;
// Motion Sensor
class Motion : public pairing{
    private:
        bool state=true;
    public:
        bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
        void on(){
        if(checkconnections()){
            cout<<"Motion_Sensor Turned ON"<<endl;
            state=true;
        } else {
            connection(2);
            cout<<"Motion_Sensor Turned ON"<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
            cout<<"Motion_Sensor Turned OFF"<<endl;
            state=false;
        } else {
            connection(2);
            cout<<"Motion_Sensor Turned OFF"<<endl;
            state=false;
        }
     }
}m1;
// Gas sensor
class gas : public pairing{
    private:
        bool state=true;
    public:
        bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
        void on(){
        if(checkconnections()){
            cout<<"Gas_Detections_Sensor Turned ON"<<endl;
            state=true;
        } else {
            connection(3);
            cout<<"Gas_Detections_Sensor Turned ON"<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
            cout<<"Gas_Detections_Sensor Turned OFF"<<endl;
            state=false;
        } else {
            connection(3);
            cout<<"Gas_Detections_Sensor Turned OFF"<<endl;
            state=false;
        }
     }
}g1;
// Light Sensor class
class light : public pairing{
    private:
        bool state=false;
    public:
        bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
     void on(){
        if(checkconnections()){
            cout<<"Light Turned ON"<<endl;
            state=true;
        } else {
            connection(5);
            cout<<"Light Turned ON"<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
            cout<<"Light Turned OFF"<<endl;
            state=false;
        } else {
            connection(5);
            cout<<"Light Turned OFF"<<endl;
            state=false;
        }
     }
}l1;
// Fan Class
class fan : public pairing{
    private:
        bool state=false;
    public:
     bool getstate(){
            return state;
        }
        void setstate(bool state){
            this->state=state;
        }
     void on(){
        if(checkconnections()){
            cout<<"Fan Turned ON"<<endl;
            state=true;
        } else {
            connection(4);
            cout<<"Fan Turned ON"<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
            cout<<"Fan Turned OFF"<<endl;
            state=false;
        } else {
            connection(4);
            cout<<"Fan Turned OFF"<<endl;
            state=false;
        }
     }
}f1;
// Door class
class door : public pairing{
    private:
        bool state=false;
    public:
     bool getstate(){
            return state;
     }
     void on(){
        if(checkconnections()){
            cout<<"Door  Opened "<<endl;
            state=true;
        } else {
            connection(6);
            cout<<"Door  Opened "<<endl;
            state=true;
        }
     }
     void off(){
        if(checkconnections()){
             cout<<"Door Closed "<<endl;
            state=false;
        } else {
            connection(6);
             cout<<"Door Closed "<<endl;
            state=false;
        }
     }
}d1;
class device : public Temprature,public Waterlevel,public Motion,public gas,public light,public fan,public door{
    public:
        void config(float temperature, float waterheight,bool motion,bool Gas,Temprature *t1,Waterlevel *w1,Motion *m1,gas *g1,fan *f1,light *l1,door *d1){
            // Feeding values
            t1->setcurtemp(temperature);
            t1->setstate(true);
            w1->setheight(waterheight);
            w1->setstate(true);
            m1->setstate(motion);
            g1->setstate(Gas);
            // Manipulation values
            // If temperature more than 22 turn on fan 
            if(temperature > 22.0)
                f1->on();
            else  
                f1->off();
            // If Motion detected turn on light
            if(motion)
                l1->on();
            else 
                l1->off();
            // If gas leak found open Door 
            if(Gas)
                d1->on();
            else 
                d1->off();
            status.push_back(tuple <float,bool,float,bool,bool,bool,bool,bool,bool> (temperature,t1->getstate(),waterheight,w1->getstate(),motion,Gas,f1->getstate(),l1->getstate(),d1->getstate()));
        }
        string ans(int x){
            if(x)
                return "ON";
            else
                return "OFF";
        }
        void getlastconfig(){
            int n=status.size()-1;
            cout<<"Temprature_Sensor "<<ans(get<1>(status[n]))<<" Temprature : "<<get<0>(status[n])<<endl;
            cout<<"Water_level_Sensor "<<ans(get<3>(status[n]))<<" Heigth : "<<get<2>(status[n])<<endl;
            cout<<"Motion_Sensor "<<ans(get<4>(status[n]))<<endl;
            cout<<"Gas_Detections_Sensor "<<ans(get<5>(status[n]))<<endl;
            cout<<"Fan "<<ans(get<6>(status[n]))<<endl;
            cout<<"Light "<<ans(get<7>(status[n]))<<endl;
            cout<<"Door";
            if(get<8>(status[n]))
                cout<<" Opened"<<endl;
            else  
                cout<<" Closed"<<endl;
        }
}device1;
int main(){

    device1.config(13,10,false,true,&t1,&w1,&m1,&g1,&f1,&l1,&d1);
    cout<<"\n\n";
    device1.getlastconfig();
    cout<<"\n\n";

    //Door sensor
    d1.connection(6);
    d1.on();
    d1.disconnection(6);
    d1.off();
    cout<<"\n\n";

    //Fan sensor
    f1.connection(4);
    f1.on();
    f1.disconnection(4);
    f1.off();
    cout<<"\n\n";

    //Gas sensor
    g1.connection(3);
    g1.on();
    g1.disconnection(3);
    g1.off();
    cout<<"\n\n";

    //Motion sensor
    m1.connection(2);
    m1.on();
    m1.disconnection(2);
    m1.off();
    cout<<"\n\n";
    
    //Waterlevel functions
    w1.connection(1);
    w1.on();
    w1.disconnection(1);
    w1.off();
    w1.setheight(10.7);
    cout<<"Water_level_Sensor Height = "<<w1.getheight()<<endl;
    cout<<"\n\n";
 
    //Temprature functions
    t1.connection(0);
    t1.on();
    t1.disconnection(0);
    t1.off();
    t1.setcurtemp(22.5);
    cout<<"Temprature functions Temprature = "<<t1.getcurtemp()<<endl;
    cout<<"\n\n";

    //light Functions
    l1.connection(5);
    l1.on();
    l1.disconnection(5);
    l1.off();
    cout<<"\n\n";

    return  0;
}
