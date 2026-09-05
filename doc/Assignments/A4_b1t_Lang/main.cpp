#include "main.h"

main {
  detach_C();

  int count;
  out << "How many numbers do you want to calculate? ";
  in >> count;

  if (count <= 0) {
    out << "Invalid count! Please enter a number > 0." << endl;
    return 0;
  }

  vector<double> nums(count);
  loop(i, 0, count, i++) {
    out << "Enter number " << (i + 1) << ": ";
    in >> nums[i];
  }

  out << "\n--- Calculation Results (From Dynamic Input) ---" << endl;
  out << "JOG Hocche: " << sum(nums) << endl;
  out << "BIYOG Hocche: " << sub(nums) << endl;
  out << "GUN Hocche: " << mul(nums) << endl;
  out << "VAG Hocche: " << divi(nums) << endl;
  out << "MAX Hocche: " << mx(nums) << endl;
  out << "MIN Hocche: " << mn(nums) << endl;

  out << "\n--- Additional DSL Function Demonstrations ---" << endl;
  out << "Variadic Max mx(10, 45, 22, 99, 5): " << mx(10, 45, 22, 99, 5)
      << endl;
  out << "Variadic Min mn(10, 45, 22, 99, 5): " << mn(10, 45, 22, 99, 5)
      << endl;
  out << "Modulo rem(17, 5): " << rem(17, 5) << endl;
  out << "Power pwr(2, 5): " << pwr(2, 5) << endl;
  out << "Square sqr(6): " << sqr(6) << endl;
  out << "Cube cube(3): " << cube(3) << endl;
  out << "Absolute abs_val(-15): " << abs_val(-15) << endl;
  out << "Factorial fact(5): " << fact(5) << endl;
  out << "Sum 1 to 10 sum_n(10): " << sum_n(10) << endl;
  out << "Is 8 Even is_even(8): " << (is_even(8) ? "True" : "False") << endl;
  out << "Is 7 Odd is_odd(7): " << (is_odd(7) ? "True" : "False") << endl;
  out << "Is 5 Positive is_pos(5): " << (is_pos(5) ? "True" : "False") << endl;
  out << "Is -3 Negative is_neg(-3): " << (is_neg(-3) ? "True" : "False")
      << endl;
  out << "Is Equal is_eq(10, 10): " << (is_eq(10, 10) ? "True" : "False")
      << endl;

  int a = 10, b = 20;
  swp(a, b);
  out << "Swap swp(10, 20) -> a: " << a << ", b: " << b << endl;

  return 0;
}
