#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <sstream>
#include "..\headers\Point3D.h"
#include "..\headers\mirror.h"
using namespace std;
 mirror::mirror()
    {
    }

    mirror::~mirror()
    {
    }
std::vector<Point3D> readFile()
{
    std::ifstream in("C:\\Users\\Om Bothe\\Desktop\\1.STLReader\\textFiles\\Cube1.txt");
    std::ofstream out("../Text_files/original.txt");
    std::vector<Point3D> readvector;
    std::string s;
    std::vector<Point3D> vertexPoint3Ds;
    std::string line;
    while (std::getline(in, line))
    {
        if (line.find("vertex") != std::string::npos)
        {
            std::istringstream iss(line);
            std::string token;
            double x, y, z;
            iss >> token >> x >> y >> z;
            out << x << " " << y << " " << z << std::endl;
            vertexPoint3Ds.push_back({x, y, z});
        }
    }
    in.close();
    out.close();
    return vertexPoint3Ds;
}

std::vector<Point3D> getPlane(std::vector<Point3D> &readvector)
{
    double vx=2, vy=2, vz=2, px=5, py=5, pz=5;
    Point3D Plane_Point3Ds(px, py, pz);
    Point3D Vector_Point3Ds(vx, vy, vz);
    readvector.insert(readvector.begin(), Vector_Point3Ds);
    readvector.insert(readvector.begin() + 1, Plane_Point3Ds);
    return readvector;
}

std::vector<Point3D> reflectPoint3D(std::vector<Point3D> &Point3D_vector)
{
    const double a = Point3D_vector[0].x();
    const double b = Point3D_vector[0].y();
    const double c = Point3D_vector[0].z();
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));
    Point3D normalised_vector(a / div, b / div, c / div);
    double x1 = Point3D_vector[1].x(), y1 = Point3D_vector[1].y(), z1 = Point3D_vector[1].z();
    std::vector<Point3D> reflected_shape;
    for (int i = 2; i < Point3D_vector.size(); i++)
    {
        double tx = Point3D_vector[i].x();

        double ty = Point3D_vector[i].y();

        double tz = Point3D_vector[i].z();

        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));

        reflected_shape.push_back(Point3D(Point3D_vector[i].x() + (2 * dist * normalised_vector.x()), Point3D_vector[i].y() + (2 * dist * normalised_vector.y()), Point3D_vector[i].z() + (2 * dist * normalised_vector.z())));

    }

    return reflected_shape;

}

void plotPlane(std::vector<Point3D> &reflect)
{
    std::ofstream out("../Text_files/plane.txt");
    for (auto i : reflect)
    {
        out << i.x() << " " << i.y() << " " << i.z() << std::endl;
    }
    out.close();
}
std::vector<Point3D> writePlane(std::vector<Point3D> Point3D_vector)
{
    const double a = Point3D_vector[0].x();
    const double b = Point3D_vector[0].y();
    const double c = Point3D_vector[0].z();
    const double div = sqrt(pow(a, 2.0) + pow(b, 2.0) + pow(c, 2.0));
    Point3D normalised_vector(a / div, b / div, c / div);
    double x1 = Point3D_vector[1].x(), y1 = Point3D_vector[1].y(), z1 = Point3D_vector[1].z();
    std::vector<Point3D> planar_shape;
    for (int i = 2; i < Point3D_vector.size(); i++)
    {
        double tx = Point3D_vector[i].x();
        double ty = Point3D_vector[i].y();
        double tz = Point3D_vector[i].z();
        double dist = abs(((a * tx) + (b * ty) + (c * tz) - (a * x1) - (b * y1) - (c * z1)) / (div));
        planar_shape.push_back(Point3D(Point3D_vector[i].x() + (dist * normalised_vector.x()), Point3D_vector[i].y() + (dist * normalised_vector.y()), Point3D_vector[i].z() + (dist * normalised_vector.z())));
    }
    plotPlane(planar_shape);
    return planar_shape;
}

void plot(std::vector<Point3D> reflect)
{
    std::ofstream out("../Text_files/reflection.txt");
    for (auto i : reflect)
    {
        out << i.x() << " " << i.y() << " " << i.z() << std::endl;
    }
    out.close();
}