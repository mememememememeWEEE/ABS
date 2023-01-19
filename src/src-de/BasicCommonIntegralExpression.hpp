#include "Expression.hpp"

enum EIntegralTypes {
    INTEGRAL_REAL,
    INTEGRAL_INTEGER,
    INTEGRAL_FLOAT32,
    INTEGRAL_FLOAT64,
};

enum EIntegralOperatorTypes {
    INTEGRAL_EXPRESSION_TYPE_ADD,
    INTEGRAL_EXPRESSION_TYPE_SUB,
    INTEGRAL_EXPRESSION_TYPE_MUL,
    INTEGRAL_EXPRESSION_TYPE_DIV,
    INTEGRAL_EXPRESSION_TYPE_MOD,
    INTEGRAL_EXPRESSION_TYPE_POW,
};

class BasicCommonIntegralExpression : public Expression<EIntegralTypes, EIntegralOperatorTypes> {

};