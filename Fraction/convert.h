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

inline int convertToInt(std::string const& s)
{
  std::istringstream i(s);
  int x;
  if (!(i >> x))
    throw BadConversion("convertToInt(\"" + s + "\")");
  return x;
}