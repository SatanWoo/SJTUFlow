#ifndef _STATICVARIBLES_H
#define _STATICVARIBLES_H

#include "boost/python.hpp"
using namespace boost::python;

class StaticVaribles
{
public:
	static std::string m_rstname;
	static std::string m_scname;

	static void ExportClass()
	{
		class_<StaticVaribles>("StaticVaribles")
			.add_static_property("m_rstname",
			make_getter(&StaticVaribles::m_rstname),
			make_setter(&StaticVaribles::m_rstname))
			.add_static_property("m_scname",
			make_getter(&StaticVaribles::m_scname),
			make_setter(&StaticVaribles::m_scname));
	}
};

#endif