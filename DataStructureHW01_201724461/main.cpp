#include <iostream>
#include <fstream>


using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    Point(int xp, int yp) : x(xp), y(yp) {}
    void Move(int xmv, int ymv);
    void Set(int rx, int ry);
    int Coor_x()  {   return x;   }
    int Coor_y()  {   return y;   }
};

void Point::Set(int rx, int ry){
    x = rx;
    y = ry;
}

void Point::Move(int xmv, int ymv){
    x += xmv;
    y += ymv;
}

class Robo : public Point{
private:
    Point* Track;
    int dir_x;
    int dir_y;
    int index;
    int len;

public:
    Robo(Point* p, int K) : Track(p), dir_x(0), dir_y(0), index(0), len(K) {
        Set(Track[index].Coor_x(),Track[index].Coor_y());
    }
    void Step();
    void Reset();
    void SetDir();
    friend ostream& operator <<(ostream& os, Robo& rb);
};

void Robo::Reset(){
    Set(Track[0].Coor_x(), Track[0].Coor_y());
    index = 0;
}

void Robo::SetDir(){
    dir_x = Track[index].Coor_x() - this->Coor_x();
    dir_y = Track[index].Coor_y() - this->Coor_y();

    switch()

    if(dir_x==0 && dir_y==0){
        index = (index+1)%len;
        return ;
    }
    else{
        if(dir_x!=0){
            dir_x /= abs(dir_x);
        }
        else if(dir_y!=0){
            dir_y /= abs(dir_y);
        }
        return;
    }
}

void Robo::Step(){
    SetDir();
    if(dir_x==0 && dir_y==0)
        SetDir();
    Move(dir_x,dir_y);
}

ostream& operator<<(ostream&os, Robo& rb){
    os << rb.Coor_x() << "  "<< rb.Coor_y() << endl;
    return os;
}



int main(){

    ifstream fin("openin02.txt");
    ofstream fout("testout02.txt");
    int K;

    fin >> K;

    Point root[K];
    int coor[K][2];
    int time[5];

    for(int i=0; i<K; i++)
        for(int j=0; j<2; j++)
            fin >> coor[i][j];


    for(int i=0; i<5; i++)
        fin >> time[i];


    for( int i=0; i<K; i++)
        root[i].Set(coor[i][0], coor[i][1]);


    Robo rb(root, K);


    for(int i=0; i<5; i++){
        for(int j = 0; j<time[i]; j++){
            rb.Step();
        }
        fout<<rb;
        rb.Reset();
    }

    fin.close();
    fout.close();

    return 0;
}
