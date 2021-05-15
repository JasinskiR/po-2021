#include "Vector.hpp"

/**
 * Oznaczenie wektora jako instancji klasy szablonowej Vector dla parametru szablonu równego 3
 */
template class Vector<3>;

template std::ostream &operator<<(std::ostream &strm, const Vector<3> &Vector);
template std::istream &operator>>(std::istream &strm, Vector<3> &Vector);