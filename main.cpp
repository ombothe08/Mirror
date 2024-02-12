#include <iostream>
#include "./headers/Triangulation.h"
#include "./headers/Triangle.h"
#include "./headers/STLReader.h"
#include "./headers/STLWriter.h"
#include "./headers/mirror.h"

using namespace Shapes3D;
// Define a typedef for a vector of Triangle objects
typedef vector<Triangle> Triangles;

int main()
{
    std::string inputFilePath = "stlFiles/cube.stl";
    std::string outputFilePath = "textFiles/Cube1.txt";  

    Shapes3D::STLReader stlReader;
    mirror m;
    // Read triangulation data from the input STL file
    Triangulation triangulation = stlReader.readSTL(inputFilePath);

    Shapes3D::STLWriter stlWriter;
    // Write triangulation data to the output text file

    vector<Point3D> one=stlWriter.writeSTL(outputFilePath, triangulation);
    
    //vector<Point3D> one = m.readFile(); 
    vector<Point3D> second = m.getPlane(one);
    m.writePlane(second);
    vector<Point3D> third = m.reflectPoint(second);
    m.plot(third);
    return 0;
}
