#include <iostream>
#include "CentralPolygonalNumbers.h"

int main() {
    CentralPolygonalNumbers cpn(10);
    cpn.display();
    cpn.save("CPN");
}