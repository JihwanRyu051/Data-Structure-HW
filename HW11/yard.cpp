#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<vector<int>> field;
    vector<vector<int>>::iterator vi;
    int N, s, container, maxyard, minyard;
    int max_index, min_index;

    cin >> N;
    for(int i=0; i<N; i++){
        cin >> s;
        vector<int> yard;
        yard.push_back(0);
        for(int i=0; i<s; i++){
            cin >> container;
            yard.push_back(container);
        }
        field.push_back(yard);
    }

    while(true){
        maxyard = 0;
        minyard = 9999;
        for(vi = field.begin(); vi<field.end(); vi++){
            int size_y = (*vi).size();
            int index = vi - field.begin();
            if(maxyard<size_y){
                maxyard = size_y;
                max_index = index;
            }
            else if(maxyard == size_y){
                if(field.at(max_index).back()<field.at(index).back()){
                    max_index = index;
                }
            }
            if(minyard>size_y){
                minyard = size_y;
                min_index = index;
            }
        }

        if((maxyard-minyard)<=1)
            break;
        container = field.at(max_index).back();
        field.at(min_index).push_back(container);
        field.at(max_index).pop_back();
    }

    for(vi = field.begin(); vi<field.end(); vi++){
        int index = vi - field.begin();
        cout << index+1 << " >";
        for(auto c: *vi){
            if(c != 0)
                cout <<" "<<c;
        }
        cout <<endl;
    }

    return 0;
}
