#pragma once

#include "BSPViewer/Exception.hpp"

class AccessOutOfBoundsException : public Exception {
public:
    AccessOutOfBoundsException() : Exception("AccessOutOfBoundsException") {}
};
