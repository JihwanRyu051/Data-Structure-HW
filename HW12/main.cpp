#include <bits/stdc++.h>

using namespace std;

int main()
{
    ifstream fin;


    list<char> genome;
    list<char> part;
    list<char>::iterator gft, glt;

    vector<string> toolBox = {"front", "back", "cut", "double", "flip","report"};

    char g;
    int N, first, last, index;
    string op;

    fin.open("sapiens.txt");

    if(fin.is_open()){
        getline(fin, op);
        while(fin>>g){
            genome.push_back(g);
        }

        cin >> N;

        for(int i=0;i<N;i++){
            cin>>op>>first>>last;

            if(first<=genome.size()){
                gft = genome.begin();
                advance(gft, first-1);
                glt = gft;

                for(int i= 0; i<=last-first; i++) glt++;

                part.splice(part.begin(), genome, gft, glt);

                index = find(toolBox.begin(), toolBox.end(),op)-toolBox.begin();

                if(index>2){
                    gft = genome.begin();
                    advance(gft, first-1);
                    }

                switch(index){
                case 0:
                    genome.splice(genome.begin(), part, part.begin(), part.end());
                    break;
                case 1:
                    genome.splice(genome.end(), part, part.begin(), part.end());
                    break;
                case 3:
                    part.insert(part.begin(),part.begin(),part.end());
                    genome.splice(gft, part, part.begin(), part.end());
                    break;
                case 4:
                    while(!part.empty())
                        genome.splice(gft, part, prev(part.end()));
                    break;
                case 5:
                    for(auto p: part) cout <<p;
                    cout << endl;
                    genome.splice(gft,part, part.begin(), part.end());
                    break;
                default:
                    part.clear();
                    break;
                }
            }else cout << "NONE" <<endl;
        }
        fin.close();
    }
    return 0;
}
