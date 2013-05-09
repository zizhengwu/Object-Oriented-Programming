#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

class BadConversion : public std::runtime_error {
public:
  BadConversion(std::string const& s)
    : std::runtime_error(s)
    { }
};

inline long convertToLong(std::string const& s)
{
  std::istringstream i(s);
  long x;
  if (!(i >> x))
    throw BadConversion("convertToDouble(\"" + s + "\")");
  return x;
}