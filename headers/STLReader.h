// STLReader.h
#pragma once
#include <string>
#include <vector>
#include "Triangulation.h"

namespace Shapes3D
{
    class STLReader
    {
    public:
        STLReader();
        ~STLReader();

        Triangulation readSTL(const std::string &filePath);
        void writeMirroredSTL(const std::string &filePath, Triangulation &mirroredTriangulation);

    private:
        void mirrorImage(std::vector<Point3D>& points, char mirror_plane);
    };
}
