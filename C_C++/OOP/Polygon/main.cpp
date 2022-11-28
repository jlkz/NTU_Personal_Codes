#include <iostream>

using namespace std;

class Polygon{
    public:
        enum KindofPolygon { POLY_PLAIN, POLY_RECT,POLY_TRIANG};
    protected:
        string name;
        float width;
        float height;
        KindofPolygon polytype;
    public:
        Polygon(string theName, float theWidth, float theHeight, KindofPolygon x){
            name = theName;
            width = theWidth;
            height = theHeight;
            polytype = x;
        }
        KindofPolygon getPolytype() {
            return polytype;
        }
        void setPolytype(KindofPolygon value) {
            polytype = value;
        }
        string getName() { return name; }
        virtual float calArea() {return 0;}
        void printWidthHeight( ) {
            cout<<"Width = " << width << " Height = "<<height<<endl;
        }

};

class Rectangle : public Polygon{
    public:
        //Rectangle():Polygon("rectangle", 2, 10, KindofPolygon::POLY_RECT){
        //}

        Rectangle (string theName, float theWidth, float theHeight)
        : Polygon(theName, theWidth, theHeight, KindofPolygon::POLY_RECT){}

        float calArea(){
            return height* width;
        }

        void printArea(Rectangle r){
            cout<< "Area is " << r.calArea()<<endl;
        }

};

class Triangle : public Polygon{
    public:
        Triangle():Polygon("triangle", 2, 10, KindofPolygon::POLY_TRIANG){
        }
        Triangle (string theName, float theWidth, float theHeight)
        : Polygon(theName, theWidth, theHeight, KindofPolygon::POLY_TRIANG){}

        float calArea(){
            return 0.5*height* width;
        }

        void printArea(Triangle t){
            cout<< "Area is " << t.calArea()<<endl;
        }

};

int main()
{
    Rectangle r("dog", 50, 2);
    Triangle t;
    Triangle * p1 = &t;
    Rectangle *p = &r;
    p1->printArea(t);
    p->printArea(r);
    delete p;
    delete p1;
    return 0;
}
