#include <fstream>
#include <map>
#include <iomanip>
using namespace std;
int main() {
  ifstream ifst("input.txt");
  ofstream ofst("output.txt");
  map<long, long> numbers;
  size_t n;
  ifst >> n;
  auto insert_value = [&numbers](long number, long count) {
    auto it = numbers.find(number);
    if (it == numbers.end())
      numbers.insert(make_pair(number, count));
    else
      it->second += count;
  };
  for (size_t i = 0; i < n; ++i) {
    long number;
    ifst >> number;
    insert_value(number, 1);
  }
  double cost = 0;
  while (true) {
    if (numbers.size() < 2 && numbers.begin()->second < 2)
      break;
    auto it_first = numbers.begin();
    long first_value = it_first->first;
    if (it_first->second > 1) {
      long pairs_count = it_first->second / 2;
      it_first->second %= 2;
      insert_value(first_value*2, pairs_count);
      cost += first_value*pairs_count*2;
      if (it_first->second == 0)
        numbers.erase(it_first);
      continue;
    }
    if (numbers.size() > 1) {
      auto it_second = next(it_first);
      long second_value = it_second->first;
      cost += first_value + second_value;
      it_second->second--;
      if (it_second->second == 0)
        numbers.erase(it_first, next(it_second));
      else
        numbers.erase(it_first);
      insert_value(first_value+second_value, 1);
    }
  }
  ofst << setprecision(2) << std::fixed << cost*0.05;
}