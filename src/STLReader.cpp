// STLReader.cpp
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include "../headers/STLReader.h"
#include "../headers/Triangulation.h"

using namespace std;
using namespace Shapes3D;

STLReader::STLReader() {}

STLReader::~STLReader() {}

Triangulation STLReader::readSTL(const std::string &filePath)
{
    Triangulation triangulation;

    ifstream file(filePath);

    if (!file.is_open())
    {
        cout << "Error while opening the file." << endl;
    }

    string line;
    map<Point3D, int> pointIndexMap;
    while (getline(file, line))
    {
        if (line.substr(0, 6) == "vertex")
        {
            double x, y, z;
            istringstream iss(line.substr(7));
            iss >> x >> y >> z;

            Point3D point(x, y, z);

            // Add the point to the triangulation
            triangulation.uniquePoints().push_back(point);
        }
    }

    // Perform mirror image transformation
    mirrorImage(triangulation.uniquePoints(), 'Z');

    return triangulation;
}

void STLReader::writeMirroredSTL(const std::string &filePath, Triangulation &mirroredTriangulation)
{
    ofstream outFile(filePath);

    if (!outFile.is_open())
    {
        cout << "Error while opening the file for writing." << endl;
    }

    // Write the mirrored triangulation data to the file
    for (const Point3D &point : mirroredTriangulation.uniquePoints())
    {
        outFile << "vertex " << point.x() << " " << point.y() << " " << point.z() << endl;
    }
}

void STLReader::mirrorImage(std::vector<Point3D>& points, char mirror_plane) {
    for (Point3D& point : points) {
        if (mirror_plane == 'X') {
            point.setX(-point.x());
        } else if (mirror_plane == 'Y') {
            point.setY(-point.y());
        } else if (mirror_plane == 'Z') {
            point.setZ(-point.z());
        }
    }
}

