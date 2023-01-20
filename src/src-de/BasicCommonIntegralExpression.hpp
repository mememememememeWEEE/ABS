#include <type_traits>
#include "Expression.hpp"
#include "BasicTypes.hpp"

enum EIntegralOperatorTypes {
    INTEGRAL_EXPRESSION_TYPE_ADD,
    INTEGRAL_EXPRESSION_TYPE_SUB,
    INTEGRAL_EXPRESSION_TYPE_MUL,
    INTEGRAL_EXPRESSION_TYPE_DIV,
    INTEGRAL_EXPRESSION_TYPE_MOD,
    INTEGRAL_EXPRESSION_TYPE_POW,
};

template<typename T>
concept _bcie = std::is_base_of_v<INTEGRAL, T>;
template<_bcie T>
class BasicCommonIntegralExpression : public Expression<T, EIntegralOperatorTypes> {
public:
};
