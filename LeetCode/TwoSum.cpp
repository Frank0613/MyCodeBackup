#include <unordered_map>
#include <utility>
#include <vector>
std::vector<int> twoSum(std::vector<int> &nums, int target) {
  std::unordered_map<int, int> m;
  for (int i = 0; i < nums.size(); i++) {
    if (auto search = m.find(nums[i]); search != m.end())
      return {i, search->second};
    m.insert(std::pair<int, int>(target - nums[i], i));
  }
}