#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
struct Control {
    int id;
    string type,state;
};
int main(){
    vector<Control>control;
    control.push_back({1,"sliders","visible"});
    control.push_back({2,"button","invisible"});
    control.push_back({3,"button","visible"});
    control.push_back({4,"sliders","disabled"});
    control.push_back({5,"button","visible"});
    control.push_back({6,"sliders","invisible"});
    control.push_back({7,"button","visible"});
    control.push_back({8,"sliders","visible"});
    control.push_back({9,"button","visible"});
    control.push_back({10,"sliders","disabled"});
    
    for(auto it=control.begin(); it!=control.end(); ++it){
        cout<<"ID : "<<it->id<<endl;
        cout<<"Type : "<<it->type<<endl;
        cout<<"State : "<<it->state<<endl;
    }
//    vector<int>idv; 
//    for(Control a: control){
//        idv.push_back(a.id);
//    }
//   for(auto i : idv){
//       cout<<i;
//   }
   
    Control targetControl = {2, "", ""};
    auto fi = find(control.begin(), control.end(), targetControl);
    if (fi != control.end()) {
        cout << "Found control with ID 2: Type: " << fi->type << ", State: " << fi->state << endl;
    } else {
        cout << "Control with ID 2 not found." << endl;
    }
    cout << endl;

    // auto iter=find_if(control.begin(),control.end(),[] (Control &a){ return a.state=="invisible";});
    // if (iter != control.end()) {
    //     cout << "First invisible control: " << iter->id << " " << iter->type << " " << iter->state << endl;
    // } else {
    //     cout << "No invisible controls found." << endl;
    // }
     auto it1=adjacent_find(control.begin(),control.end(),[] (Control &a,Control &b){ return a.state==b.state;});
     if(it1!=control.end()){
    cout<<"Controls with same consecutive states found at :"<<it1->id<<" and "<<(it1+1)->id<<endl;
     }
     else cout<<"Consecutive states not found"<<endl;


    Control targetControlVisible = {0, "", "visible"};
    int visibleCount = count(control.begin(), control.end(), targetControlVisible);
    cout<<"No of Visible states in the Control are:"<<visibleCount;

    int coun=count_if(control.begin(),control.end(),[] (Control &a){ return a.state=="disabled";});
     cout<<"Number of disabled states in vector are:"<<coun<<endl;
     bool eq=equal(control.begin(),control.begin()+1,control.end(),[](Control &a,Control &b){
         {
             return a.state==b.state && a.type==b.type;
         }
     });
     if(eq){
     cout<<"Sub ranges are Equal:"<<endl;
     }
     else 
     cout<<"Sub ranges are not equal";
}
