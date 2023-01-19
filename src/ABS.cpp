#include <stdio.h>
#include <vector>																	
#include <type_traits>

#include "basicCommonIntegralTypes.hpp"
#include "abstractSyntaxTree.hpp"

int main(void) {
	basicIntegralBinaryExpression<FLOAT32, ADDITION> is;
	AST ast{{is}};
	ast.printSummary();
	return 0;
}

