import glaze.csv;

#include <cassert>
#include <string>
#include <vector>

int main() {
  std::string input = "1";
  auto v = glz::csv::read<std::vector<int>>(input);
  assert(v.size() == 1);
  assert(v[0] == 1);
  return 0;
}
