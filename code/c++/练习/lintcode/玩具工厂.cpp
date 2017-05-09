#include <iostream>
#include <string>
using namespace std;
/*
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
/**
 * Your object will be instantiated and called as such:
 * ToyFactory* tf = new ToyFactory();
 * Toy* toy = tf->getToy(type);
 * toy->talk();
 */
/**
 * Your object will be instantiated and called as such:
 * ShapeFactory* sf = new ShapeFactory();
 * Shape* shape = sf->getShape(shapeType);
 * shape->draw();
 
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
    void draw()
    {
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    }
    // Write your code here
};

class Triangle: public Shape {
    // Write your code here
    void draw()
    {
        cout<<"  /\\ "<<endl;
        cout<<" /  \\"<<endl;
        cout<<"/____\\"<<endl;
    }
};

class Square: public Shape {
    // Write your code here
        void draw()
    {
        cout<<" ---- "<<endl;
        cout<<"|    |"<<endl;
        cout<<" ---- "<<endl;
    }
};

class ShapeFactory 
{
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape

    Shape* getShape(int shapeType)
    {
        // Write your code here
        if(shapeType==1)
            return new Rectangle();
        else if (shapeType==2)
            return new Triangle();
        else if (shapeType==3)
            return new Square();
    };
};


*/
class Shape {
public:
    virtual void draw() const=0;
};

class Rectangle: public Shape {
public:
    void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class Square: public Shape {
public:
    void draw() const {
        cout << " ---- " << endl;
        cout << "|    |" << endl;
        cout << "|    |" << endl;
        cout << " ---- " << endl;
    }
};

class Triangle: public Shape {
public:
    void draw() const {
        cout << "  /\\ " << endl;
        cout << " /  \\ " << endl;
        cout << "/____\\ " << endl;
    }
};

class ShapeFactory {
public:
    /**
     * @param shapeType a string
     * @return Get object of type Shape
     */
    Shape* getShape(int shapeType) {
        if (shapeType == 1) return new Square();
        else if (shapeType == 2) return new Triangle();
        else if (shapeType == 3) return new Rectangle();
        else return NULL;
    }
};

int main()
{
	ShapeFactory * sf = new ShapeFactory();
	Shape* shape = sf->getShape(3);
	shape->draw();
	return 0;
}
