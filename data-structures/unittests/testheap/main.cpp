/**
 * Simple C++ main for launching heap test.
 *
 * @author
 *   Amal Feriani
 */

#include "gtest/gtest.h"

int main(int argc, char **argv){
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
