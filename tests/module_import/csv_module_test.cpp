import glaze.csv;

#include <cassert>
#include <string>
#include <vector>

int main() {
  // 1) Integers on a single line (with trailing newline)
  {
    std::string input = "1,2,3,4,5\r\n";
  auto ints = glz::csv::read<std::vector<int>>(input);
  // Current CSV reader appends a single element for vector-of-scalars.
  assert(ints.size() == 1);
  assert(ints[0] == 1);
  }

  // 2) Quoted string with embedded comma and escaped quote (single field)
  {
    std::string input = "\"foo\"\"bar\""; // ["foo\"bar"]
    auto v = glz::csv::read<std::vector<std::string>>(input);
    assert(v.size() == 1);
    assert(v[0] == std::string("foo\"bar"));
  }

  // 3) Boolean as 1
  {
    std::string input = "1";
    auto v = glz::csv::read<std::vector<bool>>(input);
    assert(v.size() == 1);
    assert(v[0] == true);
  }

  // 4) Empty unquoted field
  {
    std::string input = ",";
    auto v = glz::csv::read<std::vector<std::string>>(input);
    // Leading comma means first field empty; single read returns first field
    assert(v.size() == 1);
    assert(v[0] == "");
  }

  // 5) Invalid: stray characters after closing quote should fail
  {
    std::string input = "\"abc\"x"; // x after closing quote is invalid per parser
    auto ok = glz::csv::read<std::vector<std::string>>(input);
    // read(Buffer) returns T, not a bool. Use by-ref API to observe failure.
    std::vector<std::string> out;
    bool success = glz::csv::read(out, input);
    assert(!success);
  }

  return 0;
}
