#include <sstream>

#include "opengl/Shapefile.hh"

using namespace std;

int main() {
  Shapefile counties = Shapefile("res/us_counties/USA_Counties.shp");
  counties.init();
  vector<ESRIShape*> shapes = ESRIShape::convertSHPObjects(counties.getShapeVector());
  stringstream buf;
  for (ESRIShape* shape : shapes) {
    vector<vector<double>> points = shape->dumpPoints();
    for (vector<double> i : points) {
      buf << "(" << i[0] << ", " << i[1] << ")\n";
    }
    buf << points.size() << "\n";
  }
  std::cout << buf.rdbuf();
}