#include "Pong.h"
#include "Physics/Vec2.h"
#include "Game/GameInfo.h"
#include <boost/python.hpp>
using namespace boost::python;

BOOST_PYTHON_MODULE(pong_ext)
{
    class_<PongGame::Vec2>("Vec2", init<>())
        .def_readwrite("x", &PongGame::Vec2::x)
        .def_readwrite("y", &PongGame::Vec2::y)
        ;
    class_<PongGame::GameInfo>("GameInfo", init<>())
        .def_readwrite("p1score", &PongGame::GameInfo::player1Score)
        .def_readwrite("p2score", &PongGame::GameInfo::player2Score)
        .def_readwrite("maxScore", &PongGame::GameInfo::maxScore)
        .def_readwrite("ballPos", &PongGame::GameInfo::ballPos)
        .def_readwrite("p1Pos", &PongGame::GameInfo::p1Pos)
        .def_readwrite("p2Pos", &PongGame::GameInfo::p2Pos)
        .def_readwrite("fieldWidth", &PongGame::GameInfo::fieldWidth)
        .def_readwrite("fieldHeight", &PongGame::GameInfo::fieldHeight)
        .def_readwrite("ballSize", &PongGame::GameInfo::ballSize)
        .def_readwrite("paddle1Length", &PongGame::GameInfo::paddle1Length)
        .def_readwrite("paddle2Length", &PongGame::GameInfo::paddle2Length)
        .def_readwrite("initialSpeed", &PongGame::GameInfo::initialSpeed)
        ;
    class_<Pong>("Pong", init<>())
        .def("setWidth", &Pong::setWidth)
        .def("setHeight", &Pong::setHeight)
        .def("setBallVelocity", &Pong::setBallVelocity)
        .def("setBallPosition", &Pong::setBallPosition)
        .def("get", &Pong::get)
        .def("run", &Pong::run)
        .def("p1input", &Pong::p1input)
        .def("p2input", &Pong::p2input)
        .def("p1score", &Pong::p1score)
        .def("p2score", &Pong::p2score)
		;
}