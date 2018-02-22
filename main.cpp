#include <cassert>
#include <string>
#include <iostream>
#include <vector>

/// Implementation of is_prime main function
int do_main(const std::vector<std::string>& args)
{
  if (args.size() != 2)
  {
    return 1;
  }
  try
  {
    const int value = std::stoi(args[1]);
    if(value < 2){
    std::cout << "false\n"; return 0;
    }
    if(value ==2){
    std::cout << "true\n"; return 1;
    }
    //Complex cases
    for (int denominator=2; denominator!=value-1; ++denominator)
    {
      if (value % denominator == 0)
      {
        std::cout << "false\n"; return 0;
      }
    }
   std::cout << "true\n"; return 1;
  }
  catch (const std::invalid_argument&)
  {
    return 1;
  }
  catch (const std::out_of_range&)
  {
    return 1;
  }
  return 0;
}

/// is_prime main function, that also tests its implementation
int main(int argc, char* argv[])
{
    assert(do_main( { "is_prime" } ) == 1);
    assert(do_main( { "is_prime", "4" } ) == 0);
    assert(do_main( { "is_prime", "3" } ) == 0);
    assert(do_main( { "is_prime", "2" } ) == 0);
    assert(do_main( { "is_prime", "123456789101112131415161718" } ) == 1);
    assert(do_main( { "is_prime", "nonsense" } ) == 1);
    assert(do_main( { "is_prime", "7","42" } ) == 1);
    assert(do_main( { "is_prime", "-4" } ) == 0);

    const std::vector<std::string> args (argv, argv + argc);
    return do_main(args);
}
