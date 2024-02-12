#pragma once


class Point3D
{
public:
    Point3D();
    Point3D(double inX, double inY, double inZ);
    ~Point3D();

    double x() const;
    double y() const;
    double z() const;

    void setX(double newX);
    void setY(double newY);
    void setZ(double newZ);

private:
    double mX;
    double mY;
    double mZ;
};


