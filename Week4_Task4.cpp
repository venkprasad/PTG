#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <set>

using namespace std;

struct Control {
    int id;
    string type;
    string state;

  // comparison operators for sorting
    bool operator<(const Control& other) const {
        return id < other.id;  // Sort by ID
    }

};

void printControls(const vector<Control>& controls) {
    for (const auto& ctrl : controls) {
        cout << "Control ID: " << ctrl.id << ", Type: " << ctrl.type << ", State: " << ctrl.state << endl;
    }
}

int main() {
    vector<Control> controlList1 = {
        {5, "sliders", "visible"},
        {3, "button", "invisible"},
        {1, "sliders", "disabled"},
        {2, "button", "visible"},
        {6, "sliders", "enabled"}
    };

    vector<Control> controlList2 = {
        {7, "button", "invisible"},
        {3, "sliders", "visible"},
        {4, "sliders", "disabled"},
        {2, "button", "enabled"},
        {8, "button", "visible"}
    };

    cout << "\nSorting controlList1 using sort:" << endl;
    sort(controlList1.begin(), controlList1.end()); // Sorting by ID
    printControls(controlList1);

    cout << "\nSorting controlList2 using stable_sort:" << endl;
    stable_sort(controlList2.begin(), controlList2.end()); // Stable sort to preserve relative order of equal IDs
    printControls(controlList2);

    // Binary search using lower_bound and upper_bound
    int search;  // Let's search for Control with ID = 3
    cout<<"Enter the number to find the lower bound :"<<endl;
    cin>>search;
    auto lower = lower_bound(controlList1.begin(), controlList1.end(), Control{search, "", ""});
    if (lower != controlList1.end()) {
        cout << "Found control with ID " << search << " in controlList1 (lower_bound): "
             << "Type: " << lower->type << ", State: " << lower->state << endl;
    } else {
        cout << "\nControl with ID " << search << " not found in controlList1 using lower_bound." << endl;
    }

    auto upper = upper_bound(controlList1.begin(), controlList1.end(), Control{search, "", ""});
    if(upper!=controlList1.end()){
    cout << "upper_bound for ID " << search << " is at ID " << upper->id<<"Type: " << lower->type << ", State: " << lower->state << endl;
    }
    else {
        cout << "Control with ID " << search << " not found in controlList1 using upper_bound." << endl;
    }
    // Merging two sorted control lists using merge
    vector<Control> mergedControls(controlList1.size() + controlList2.size());
    merge(controlList1.begin(), controlList1.end(), controlList2.begin(), controlList2.end(), mergedControls.begin());
    cout << "\nMerged controls using merge:" << endl;
    printControls(mergedControls);

    // Merging two segments of the same list using inplace_merge
    cout << "\nMerging two segments of controlList1 using inplace_merge:" << endl;
    inplace_merge(controlList1.begin(), controlList1.begin() + 3, controlList1.end());  // Merging first 3 elements with last 2
    printControls(controlList1);

    //  Set operations set_union and set_intersection
    vector<Control> unionControls;
    vector<Control> intersectionControls;

    // Using set_union to find unique controls in both lists
    set_union(controlList1.begin(), controlList1.end(), controlList2.begin(), controlList2.end(),
              back_inserter(unionControls));

    // Using set_intersection to find common controls in both lists
    set_intersection(controlList1.begin(), controlList1.end(), controlList2.begin(), controlList2.end(),
                     back_inserter(intersectionControls));

    cout << "\nSet union (unique controls in both lists):" << endl;
    printControls(unionControls);

    cout << "\nSet intersection (common controls in both lists):" << endl;
    printControls(intersectionControls);

    return 0;
}
