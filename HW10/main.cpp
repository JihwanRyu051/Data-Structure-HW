#include <iostream>
#include <utility>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int k, p, boarding,index,nominate;
    vector<queue<int>> airport;
    cin >> k;
    for(int i=0; i<k; i++){
        queue<int> airline;
        do{
            cin >> p;
            airline.push(p);
        }while(p>0);
        airport.push_back(airline);
    }

    while(true){
        nominate = 0;
        index = 0;
        pair<int,int> minplane = make_pair(0,10001);
        for(auto& line: airport){
            boarding = line.front();
            nominate += boarding;
            if((boarding>0)&&(boarding<minplane.second)){
                get<0>(minplane) = index;
                get<1>(minplane) = boarding;
            }
            index++;
        }
        if(nominate != 0){
            cout << airport.at(minplane.first).front()<<endl;
            airport.at(minplane.first).pop();
        }
        else
            break;
    }

    return 0;
}
