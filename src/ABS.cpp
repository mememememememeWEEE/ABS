#include <iostream>
#include <vector>																	
#include <type_traits>

#include "basicCommonIntegralTypes.hpp"
#include "abstractSyntaxTree.hpp"

int main(void) {
	basicIntegralBinaryExpression<FLOAT32, ADDITION> is;
	basicIntegralBinaryExpression<FLOAT32, DIVISION> os;
	AST ast{{is, os}};
	ast.name = "Is";
	ast.printSummary();
	std::cout << nameOfBasicIntegralBinaryOperations(ADDITION);
	return 0;
}

