#include <iostream>
#define FOR(i,a) for (int i = 0; i<int(a); i++)

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    void Move(int mvx, int mvy);
    void Set(int rx, int ry);
    int Coor_x()  {   return x;   }
    int Coor_y()  {   return y;   }

    bool operator == (Point p);
};

void Point::Move(int mvx, int mvy){
        x += mvx;
        y += mvy;   }

void Point::Set(int rx, int ry){
        x = rx;
        y = ry; }


bool Point::operator == (Point p){
    if(this->x == p.x && this->y == p.y)
        return true;
    else    return false;   }

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
    int SetDir();
    void Step();
    void Reset();
    friend ostream& operator <<(ostream& os, Robo& rb);
};

int Robo::SetDir(){
    if(Track[index].Coor_x() != this->Coor_x())
        return 1;
    else if(Track[index].Coor_y() != this->Coor_y())
        return 2;
    else
        return 0;
        }

void Robo::Step(){
    if(Track[index] == (Point)(*this)){
            index = (index+1)%len;
    switch(SetDir()){
        case 1:{
            dir_x = Track[index].Coor_x() - this->Coor_x();
            dir_x /= abs(dir_x);
            dir_y = 0;
            break;
            }
        case 2:{
           dir_y = Track[index].Coor_y() - this->Coor_y();
           dir_y /= abs(dir_y);
           dir_x = 0;
           break;
          }
        default:{
           cout << "Error by SetDir()!!"<<endl;
           exit(0);
           break;
        }
        }
    }
    Move(dir_x,dir_y);
    return;
}

void Robo::Reset(){
    index = 0;
    Set(Track[index].Coor_x(), Track[index].Coor_y());
}

ostream& operator <<(ostream& os, Robo& rb){
    os << " "<<rb.Coor_x() << "  "<< rb.Coor_y() << endl;
    return os;
}


int main(){

    int K;
    cin >> K;

    Point* root = new Point[K];
    int coor[K][2];
    int time[5];

    FOR(i,K)
        FOR(j,2)
            cin >> coor[i][j];

    FOR(i,5)
        cin >> time[i];


    FOR(i,K)
        root[i].Set(coor[i][0], coor[i][1]);

    Robo rb(root, K);

    FOR(i,5){
        FOR(j,time[i])
            rb.Step();

        cout<<rb;
        rb.Reset();
    }

    free(root);
    return 0;
}
