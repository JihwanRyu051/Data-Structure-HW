#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;

    list<char> genome;
    list<char>::iterator gft, glt;

    vector<string> toolBox = {"front", "back", "cut", "double", "flip","report"};

    char g;
    int N, first, last, index;
    string tool;

    fin.open("sapiens.txt");

    if(fin.is_open()){
        getline(fin, tool);
        while(fin>>g) genome.push_back(g);

        cin >> N;

        for(int i=0;i<N;i++){
            cin>>tool>>first>>last;

            if(first<=genome.size()){

                gft = genome.begin();
                advance     (gft,first-1);
                glt = gft;
                advance(glt,last-first+1);

                index = find(toolBox.begin(), toolBox.end(), tool)-toolBox.begin();

                switch(index){
                case 0:
                    genome.splice(genome.begin(), genome, gft, glt);
                    break;
                case 1:
                    genome.splice(genome.end(), genome, gft, glt);
                    break;
                case 2:
                    genome.erase(gft, glt);
                    break;
                case 3:
                    genome.insert(glt, gft,glt);
                    break;
                case 4:
                    reverse(gft,glt);
                    break;
                case 5:
                    for(gft;gft!=glt;gft++) cout <<*gft;
                    cout << endl;
                    break;
                }
            }else cout<<"NONE"<<endl;
        }fin.close();
    }
    return 0;
}
