#include "ASTNode.hpp"
#include "Expression.hpp"
#include <string>

template<typename varType>
class VaribleAssignmentNode : public ASTNode {
    std::string VariableName;
    varType assignTo;
};