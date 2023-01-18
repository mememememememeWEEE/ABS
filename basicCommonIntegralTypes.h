#pragma once

class basicCommonIntegralType {};

class INTEGER : public basicCommonIntegralType {
public:
    long long value;
    INTEGER(long long value) {
        this->value = value;
    }
};

class FLOAT32 : public basicCommonIntegralType {
public:
    float value;
    FLOAT32(float value) {
        this->value = value;
    }
};

class FLOAT64 : public basicCommonIntegralType {
public:
    double value;
    FLOAT64(double value) {
        this->value = value;
    }
};

