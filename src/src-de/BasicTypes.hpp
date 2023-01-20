#include <cstdint>
#include <any>

enum IntegralTypes {
    INTEGRAL_REAL,
    INTEGRAL_INTEGER,
    INTEGRAL_FLOAT32,
    INTEGRAL_FLOAT64,
};

class basicType {};

class StaticType {};
template<typename T>
class tStaticType : public basicType {
	bool initialized = false;
	T value;
};

class dynamicType : public basicType {
	bool initialized = false;
	std::any value;
};

class INTEGRAL {};
template<typename T> 
class tINTEGRAL : tStaticType<T> {};

class INTEGRAL_INTEGER : public tINTEGRAL<int64_t>, public INTEGRAL {};
class INTEGRAL_FLOAT32 : public tINTEGRAL<float>, public INTEGRAL {};
class INTEGRAL_FLOAT64 : public tINTEGRAL<double>, public INTEGRAL {};

