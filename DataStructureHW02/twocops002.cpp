#include <iostream>
#define FOR(i,a) for (int i=0; i < int(a); i++)

using namespace std;

class Point{
private:
    int x;
    int y;
public:
    Point(): x(0), y(0){}
    void Move(int mvx, int mvy);
    void Set(int px, int py);
    int Coor_x()  {   return x;   }
    int Coor_y()  {   return y;   }
    bool operator == (Point p);
};

void Point::Set(int px, int py){
    this->x = px;
    this->y = py;
    return;
}

bool Point::operator==(Point p){
    if(this->x == p.x && this->y == p.y)
        return true;
    else    return false;
}

void Point::Move(int mvx, int mvy){
    x += mvx;
    y += mvy;
}

class Robo : public Point{
private:
    Point Start;
    Point* Target;
    int dir_x;
    int dir_y;
    int index;
    int len;
    int vel;

public:
    Robo(Point* p, int K, int I, int V) : Target(p), dir_x(0), dir_y(0),
     index(I), len(K), vel(V) {
         Set(Target[index].Coor_x(), Target[index].Coor_y());
    }
    void SetDir();
    void Step();
    bool operator ==(Robo& rb);
    void Reflection();
    friend ostream& operator <<(ostream& os, Robo& rb);
};

bool Robo::operator==(Robo &rb){
    if(this->Coor_x()==rb.Coor_x() && this->Coor_y()==rb.Coor_y())
        return true;
    else    return false;
}

void Robo::SetDir(){
    dir_x = Target[index].Coor_x() - this->Coor_x();
    dir_y = Target[index].Coor_y() - this->Coor_y();

    if(dir_x!=0)
        dir_x /= abs(dir_x);
    else
        dir_y /= abs(dir_y);
    return;
}

void Robo::Reflection(){
    this->vel *= -1;
    this->index += vel;
    SetDir();
    return ;
}

void Robo::Step(){
    if(Target[index] == (Point)(*this)){
        Start.Set(Target[index].Coor_x(),Target[index].Coor_y());
        index = index + vel;
        if(index < 0)
            index = len-1;
        index %= len;
        SetDir();
    }
   Move(dir_x, dir_y);
    return ;
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
    int time;

    FOR(i,K)
        FOR(j,2)
            cin >> coor[i][j];
    cin >> time;

    FOR(i,K)
        track[i].Set(coor[i][0], coor[i][1]);

    Robo rb1(track, K, 0, 1);
    Robo rb2(track, K, K/2-1, -1);


    FOR(i,time){
        if(rb1 == rb2){
            rb1.Reflection();
            rb2.Reflection();
        }
        rb1.Step();
        if(rb1 == rb2){
            rb1.Reflection();
            rb2.Reflection();
            rb1.Step();
        }
        else
            rb2.Step();
    }

    cout<<rb1;
    cout<<rb2;

    free(track);

    return 0;
}
