#pragma once

#include "CGAL/Simple_cartesian.h"

namespace Geometry {
	using Kernel = CGAL::Simple_cartesian<double>;

	using Point2 = Kernel::Point_2;
	using Point2Vector = std::vector<Point2>;
	using Point3 = Kernel::Point_3;
	using Point3Vector = std::vector<Point3>;

	using Segment2 = Kernel::Segment_2;
	using Segment3 = Kernel::Segment_3;

	using Vector2 = Kernel::Vector_2;
	using Vector3 = Kernel::Vector_3;

	using Direction2 = Kernel::Direction_2;
	using Direction3 = Kernel::Direction_3;

	using Line2 = Kernel::Line_2;
	using Line3 = Kernel::Line_3;

	using Plane3 = Kernel::Plane_3;
	using Triangle2 = Kernel::Triangle_2;
	using Triangle3 = Kernel::Triangle_3;

	using Circle2 = Kernel::Circle_2;
	using Circle3 = Kernel::Circle_3;
	using Sphere3 = Kernel::Sphere_3;

	inline double SquaredDistance(Point2 p, Point2 q) {
		return CGAL::squared_distance(p, q);
	}

	inline double SquaredDistance(Point3 p, Point3 q) {
		return CGAL::squared_distance(p, q);
	}

} // namespace Geometry