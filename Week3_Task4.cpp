#include<iostream>
#include<string>
#include<map>
using namespace std;
class Theme {
    public:    //declaring the variables backgroundColor, fontColor,fontSize,iconStyle
    string backgroundColor, fontColor;
    int fontSize;
    string iconStyle;
    Theme(string bg,string fcol, int fsize,string iconsty): backgroundColor(bg),fontColor(fcol),fontSize(fsize),iconStyle(iconsty) {}
    //constructor 
    //displaying the variables
    void displayTheme(){
        cout<<"Background color : "<<backgroundColor<<endl;
        cout<<"fontColor : "<<fontColor<<endl;
        cout<<"fontsize : "<<fontSize<<endl;
        cout<<"iconStyle : "<<iconStyle<<endl;
    }
};

int main() {
    map<string,Theme*>m;
    m.emplace("Classic",new Theme ("white","blue",34,"lorew")); //assigning values for the classic theme
    m.emplace("Sport", new Theme ("Red","white",30,"epslaw")); //assigning values for the Sport theme
    m.emplace("Eco" ,new Theme ("black","yellow",41,"lowz"));  //assigning values for the Eco theme
    bool b=true;
    while(b){
        int ch;
        cout<<"Enter the theme of a car\n1.Classic\n2.Sport\n3.Eco\n4.Exit"<<endl;
        cin>>ch;
        if(ch==1){
            m["Classic"]->displayTheme();
            b=true;
        }
        else if(ch==2){
            m["Sport"]->displayTheme();
            b=true;
        }
      else if(ch==3){
            m["Eco"]->displayTheme();
            b=true;
        }
        else if(ch==4){
            cout<<"Exit";
            b=false;
        }
        else  cout<<"Please enter the valid option"<<endl;
    }
    return 0;
}
