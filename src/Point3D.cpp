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

Point3D::Point3D() : mX(0), mY(0), mZ(0) {}
Point3D::Point3D(double inX, double inY, double inZ) : mX(inX), mY(inY), mZ(inZ) {}
Point3D::~Point3D() {}

double Point3D::x() const
{
    return mX;
}

double Point3D::y() const
{
    return mY;
}

double Point3D::z() const
{
    return mZ;
}

void Point3D::setX(double newX)
{
    mX = newX;
}

void Point3D::setY(double newY)
{
    mY = newY;
}

void Point3D::setZ(double newZ)
{
    mZ = newZ;
}
