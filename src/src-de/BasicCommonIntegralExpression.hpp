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

template<class T>
concept _bcie = requires(const T& t) {[]<class U>(const INTEGRAL<U>&){}(t);};
template<_bcie T>
class BasicCommonIntegralExpression : public Expression<T, EIntegralOperatorTypes> {
public:
};
