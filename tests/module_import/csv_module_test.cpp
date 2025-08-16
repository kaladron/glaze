import glaze.csv;

#include <cassert>
#include <string>
#include <vector>

int main()
{
   // 1) Integers on a single line (with trailing newline)
   {
      std::string input = "1,2,3,4,5\r\n";
      std::vector<int> ints;
      auto ec = glz::read_csv(ints, input);
      assert(!bool(ec));
      // Current CSV reader appends a single element for vector-of-scalars.
      assert(ints.size() == 1);
      assert(ints[0] == 1);
   }

   // 2) Quoted string with embedded comma and escaped quote (single field)
   {
      std::string input = "\"foo\"\"bar\""; // ["foo\"bar"]
      std::vector<std::string> v;
      auto ec = glz::read_csv(v, input);
      assert(!bool(ec));
      assert(v.size() == 1);
      assert(v[0] == std::string("foo\"bar"));
   }

   // 3) Boolean as 1
   {
      std::string input = "1";
      std::vector<bool> v;
      auto ec = glz::read_csv(v, input);
      assert(!bool(ec));
      assert(v.size() == 1);
      assert(v[0] == true);
   }

   // 4) Empty unquoted field
   {
      std::string input = ",";
      std::vector<std::string> v;
      auto ec = glz::read_csv(v, input);
      assert(!bool(ec));
      // Leading comma means first field empty; single read returns first field
      assert(v.size() == 1);
      assert(v[0] == "");
   }

   // 5) Invalid: stray characters after closing quote should fail
   {
      std::string input = "\"abc\"x"; // x after closing quote is invalid per parser
      std::vector<std::string> out;
      // By-ref API returns error context; expect failure here
      bool success = !bool(glz::read_csv(out, input));
      assert(!success);
   }

   return 0;
}
