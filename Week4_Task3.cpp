#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    vector<string>st;
    
    st.push_back("visible");         //pushing the controlstates
    st.push_back("invisible");       //pushing the controlstates
    st.push_back("disabled");        //pushing the controlstates
    st.push_back("invisible");       //pushing the controlstates
    st.push_back("visible");          //pushing the controlstates 
    st.push_back("disabled");          //pushing the controlstates

    cout<<"States in the vector are:"<<endl;
    for(auto it=st.begin(); it!=st.end();++it){   //display the states in vector
        cout<<*it<<endl;
    }
    vector<string> cpy(st.begin(),st.end());        //copying the states from the vector
    copy(st.begin(),st.end(),cpy.begin());
    cout<<"States after copying in the vector are:"<<endl;
    for(auto it=cpy.begin(); it!=cpy.end();++it){
        cout<<*it<<endl;
    }
    fill(st.begin(),st.end(),"disabled");       //fill all the states with disabled
    cout<<"Vector after Filling the all states with the disabled state:"<<endl;
    for(auto it=st.begin(); it!=st.end();++it){
        cout<<*it<<endl;
    }
    // std::replace(st.begin(),st.end(),"disabled","enabled");
    // cout<<"Vector after replacing the disabled states with the enabled state:"<<endl;
    // for(auto it=st.begin(); it!=st.end();++it){
    //     cout<<*it<<endl;
    // }
  
    transform(st.begin(),st.end(),st.begin(),[](string x){ return "invisible";});
    cout<<"Vector after transforming the all states with the invisible state:"<<endl;       //transforming the all states with the invisible state
    for(auto it=st.begin(); it!=st.end();++it){
        cout<<*it<<endl;
    }
    remove_if(cpy.begin(),cpy.end(),[](string re){return re=="invisible";});    //removing the invisible states from the copy vector
    cout<<"Vector after removing the invisible states from the copy vector:"<<endl;
    for(auto it=cpy.begin(); it!=cpy.end();it++){
        cout<<*it<<endl;
    }
    reverse(cpy.begin(),cpy.end());     //reverse the copy vector
    cout<<"Vector after reversing the  controlstates from the copy vector:"<<endl;
    for(auto it=cpy.begin(); it!=cpy.end();it++){
        cout<<*it<<endl;
    }
    partition(cpy.begin(),cpy.end(),[](string str){return str=="invisible";});      //partition the  controlstates
    cout<<"Vector after partition the  controlstates from the copy vector:"<<endl;
    for(auto it=cpy.begin(); it!=cpy.end();it++){
        cout<<*it<<endl;
    }
}
