#include "Pong.h"
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(pong_ext)
{
	class_<Pong>("Pong", init<int>())
		.def("get", &Pong::get)
		.def("run", &Pong::run)
		;
}