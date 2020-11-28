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

bool Point::operator==(Point p){
    if(this->x == p.x && this->y == p.y)
        return true;
    else    return false;
}

void Point::Set(int rx, int ry){
    x = rx;
    y = ry;
}

void Point::Move(int mvx, int mvy){
    x += mvx;
    y += mvy;
}

class Robo : public Point{
private:
    Point* Target;
    int dir_x;
    int dir_y;
    int index;
    int len;

public:
    Robo(Point* p, int K) : Target(p), dir_x(0), dir_y(0), index(0), len(K) {
        Set(Target[index].Coor_x(),Target[index].Coor_y());

    }
    void Step();
    void Reset();
    friend ostream& operator <<(ostream& os, Robo& rb);
};

void Robo::Reset(){
    index = 0;
    Set(Target[index].Coor_x(), Target[index].Coor_y());

}

void Robo::Step(){
    if(Target[index] == (Point)(*this)){
        index = (index+1)%len;
        dir_x = Target[index].Coor_x() - this->Coor_x();
        dir_y = Target[index].Coor_y() - this->Coor_y();

        if(dir_x!=0){
           dir_x /= abs(dir_x);
        }
        else
            dir_y /= abs(dir_y);
    }
    Move(dir_x, dir_y);

}

ostream& operator<<(ostream&os, Robo& rb){
    os << " "<<rb.Coor_x() << "  "<< rb.Coor_y() << endl;
    return os;
}

int main(){

    int K;
    cin >> K;

    Point* track = new Point[K];
    int coor[K][2];
    int time[5];

    FOR(i,K)
        FOR(j,2)
            cin >> coor[i][j];

    FOR(i,5)
        cin >> time[i];


    FOR(i,K)
        track[i].Set(coor[i][0], coor[i][1]);

    Robo rb(track, K);

    FOR(i,5){
        FOR(j,time[i]){
            rb.Step();
        }
        cout<<rb;
        rb.Reset();
    }

    free(track);

    return 0;
}
