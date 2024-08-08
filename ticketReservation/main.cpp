//
//  main.cpp
//  ticketReservation
//
//  Created by akanksha on 30/07/24.
//
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

class TourBus{
    int bid;
    char destination[200];
    char time[50];
    int max_seats;
    int booked;
public:
    TourBus(){
        bid=0;
        max_seats=50;
        booked=0;
        strcpy(time,"9:10am");
        strcpy(destination, "");
        
    }
    void input(){
    
        cout<<"Enter bus id";
        cin>>bid;
        cout<<"Enter bus Destination ";
        cin>>destination;
        cout<<"Enter time of bus";
        cin>>time;
        
    }
    
    void show(){
        
    }
    void display(){
        cout<<bid<<"\t"<<destination<<"\t"<<time<<"\t"<<max_seats<<"\t"<<booked<<endl;
    }
    
    int getid(){
        return bid;
    }
    
    char* getDestination(){
        return destination;
    }
    
    char* getTime(){
        return time;
    }
    
    int getBooked(){
        return booked;
    }
    
    int getMax(){
        return max_seats;
    }
    
};

int main(int argc, const char * argv[]) {
    int ch;
    fstream F;
    TourBus b;
    do{
        cout<<"1. Add a new Tour bus "<<endl;
        cout<<"2. Show selected bus "<<endl;
        cout<<"3. Display all buses "<<endl;
        cout<<"4. Delete a bus "<<endl;
        cout<<"5. Book a ticket "<<endl;
        cout<<"6. Display booked tickets"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice ";
        cin>>ch;
        switch(ch)
        {
            case 1:
                F.open("tour.dat",ios::app | ios::binary);
                b.input();
                F.write((char*)&b, sizeof(b));
                F.close();
                cout<<"Bus added Successfully "<<endl;
                break;
            case 3:
                F.open("tour.dat", ios::in | ios::binary);
                if(F.fail())
                    cout<<"Can't open file"<<endl;
                else{
                    while(F.read((char*)&b, sizeof(b)))
                        b.display();
                }
                F.close();
                cout<<"Press a key to continue ";
                break;
                
        }
    }while(ch!=7);
    return 0;
}
