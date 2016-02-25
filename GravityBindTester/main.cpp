#include <iostream>
#include <Vector2.h>
#include <gtest\gtest.h>

using namespace std;
using GravityBind::Vector2;

void main(int argc, char* argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();
}