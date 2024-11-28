#include<vector>
#include<iostream>
#include<set>
#include<algorithm>
#include<string>
using namespace std;

int main(){
    vector<string>v;       //creating a vector
    set<string>s;          //creating a set
    v.push_back("Speedometer"); //pushing the elements
    v.push_back("Tachometer");
    v.push_back("Speedometer");
    v.push_back("Tachometer");
    s.insert("Logo");       //inserting the elements
    s.insert("WarningLights");
     cout<<"Widgets  in the vector are:"<<endl;
    for(auto it=v.begin(); it!=v.end(); ++it){
       cout<<*it<<endl;       //iterating the elements from the vector
    }
    if(s.find("WarningLights")!=s.end())        //checking whether the string is found or nott
    cout<<"WarningLights is found in the set "<<endl;
    else 
    cout<<"WarningLights is not found in the set "<<endl;
    //vector<string>vs=vector(s);
    copy(s.begin(),s.end(),std::back_inserter(v));      //copying elements in set to vector 
    cout<<"Widegets in the vector after copying"<<endl;
    for(auto it=v.begin(); it!=v.end(); ++it){
       cout<<*it<<endl;
    }
    string st="WarningLights";
    auto search = find(v.begin(), v.end(), st);         //checking whether the string is found or not
    if (search != v.end()) {
        cout << "Found: " << *search << endl;
    } else {
       cout << "Not found" << endl;
    }
    return 0;
}