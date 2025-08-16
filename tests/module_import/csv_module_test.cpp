import glaze.csv;

#include <cassert>
#include <deque>
#include <string>
#include <vector>

// Move to namespace scope to ensure external linkage (required by reflection machinery under modules)
struct my_struct
{
   std::vector<int> num1{};
   std::deque<float> num2{};
   std::vector<bool> maybe{};
   std::vector<std::array<int, 3>> v3s{};
};

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
      std::string input_row =
         R"(num1,11,33,55,77
num2,22,44,66,88
maybe,1,1,0,0
v3s[0],1,2,3,4
v3s[1],1,2,3,4
v3s[2],1,2,3,4)";

      my_struct obj{};
      auto ec = glz::read_csv(obj, input_row);
      assert(!bool(ec));

      assert(obj.num1[0] == 11);
      assert(obj.num2[2] == 66);
      assert(obj.maybe[3] == false);
      assert(obj.v3s[0][2] == 1);
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
