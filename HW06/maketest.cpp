#include<fstream>
#include<vector>

using namespace std;

int main(){
    ofstream fout;
    fout.open("textmaximum.txt");

    vector<int> coefficient(201);
    vector<int> exponent(1001);

    for(int e = 0; e<=1000; e++)
            exponent.at(e) = e;
    for(int c = -100; c<=100;c++)
        coefficient.at(c+100) = c;
    fout << 1 <<endl;
    fout << 1 <<endl;
    for(auto e : exponent){
        for(auto c : coefficient){
            fout << c << " " << e<<endl;
        }

    }

    fout.close();

    return 0;
}
