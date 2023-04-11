// DSA_Stuff.cpp : This file contains the 'main' function. Program execution
// begins and ends there.
//

#include <iostream>
#include <map>
#include <vector>

namespace algorithm {

static size_t partition(std::vector<int> &a, size_t low, size_t high) {
  const size_t pivot = a[high];
  size_t return_index = low - 1;

  for (auto i = low; i < high; ++i) {
    if (a[i] <= pivot) {
      return_index++;
      if (i != return_index) {
        const auto tmp = a[i];
        a[i] = a[return_index];
        a[return_index] = tmp;
      }
    }
  }

  return_index++;
  const auto tmp = a[return_index];

  a[return_index] = a[high];
  a[high] = tmp;

  return return_index;
}

static void quick_sort_recurse(std::vector<int> &a, size_t low, size_t high) {
  if (low >= high)
    return;
  const auto pivot = partition(a, low, high);
  quick_sort_recurse(a, low, pivot - 1);
  quick_sort_recurse(a, pivot + 1, high);
}

static void quick_sort(std::vector<int> &a) {
  quick_sort_recurse(a, 0, a.size() - 1);
}

struct point {
  size_t x;
  size_t y;

  bool operator==(const point &other) const {
    return (this->x == other.x) && (this->y == other.y);
  }
};

static const int direction[4][2] = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};

static bool walk(const std::vector<std::string> &maze, const char wall,
                 const point &curr, const point &end,
                 std::vector<std::vector<bool>> &seen,
                 std::vector<point> &path) {
  // out of bounds
  if ((curr.x < 0 || curr.x >= maze[0].length()) ||
      (curr.y < 0 || curr.y >= maze.size())) {
    return false;
  }

  // hit a wall
  if (maze[curr.y][curr.x] == wall) {
    return false;
  }

  // already seen
  if (seen[curr.y][curr.x]) {
    return false;
  }

  if (curr == end) {
    path.push_back(end);
    return true;
  }

  path.push_back(curr);
  seen[curr.y][curr.x] = true;
  for (auto i = 0; i < 4; ++i) {
    point p;
    p.x = direction[i][0] + curr.x;
    p.y = direction[i][1] + curr.y;

    if (walk(maze, wall, p, end, seen, path)) {
      return true;
    }
  }
  path.pop_back();
  return false;
}

static std::vector<point> solve_maze(const std::vector<std::string> &maze,
                                     const char wall, const point start,
                                     const point end) {
  std::vector<point> path;
  std::vector<std::vector<bool>> seen;

  // create seen list
  for (auto i = 0; i < maze.size(); ++i) {
    seen.emplace_back(std::vector<bool>());
    for (auto j = 0; j < maze[i].length(); ++j) {
      seen[i].push_back(false);
    }
  }
  walk(maze, wall, start, end, seen, path);

  return path;
}

static bool binary_search(std::vector<int> hay_stack, int needle) {
  size_t lower = 0;
  size_t higher = hay_stack.size();
  do {
    auto mid = (lower + higher) / 2;
    auto value = hay_stack[mid];
    if (value == needle) {
      return true;
    } else if (value < needle) {
      lower = mid + 1;
    } else {
      higher = mid;
    }
  } while (lower < higher);
  return false;
}

static void bubble_sort(std::vector<int> &vec) {
  for (size_t i = 0; i < vec.size(); ++i) {
    for (size_t j = 0; j < vec.size() - 1 - i; ++j) {
      if (vec[j] > vec[j + 1]) {
        auto temp = vec[j];
        vec[j] = vec[j + 1];
        vec[j + 1] = temp;
      }
    }
  }
}
} // namespace algorithm

namespace data_structure {}

namespace util {

template <typename T> static void print_vector(const std::vector<T> &vec) {
  for (auto &v : vec) {
    std::cout << v << ' ';
  }
  std::cout << std::endl;
}

static int sum(int number) {
  if (number == 1) {
    return 1;
  }

  return number + sum(number - 1);
}

static void print_maze(const std::string &message,
                       const std::vector<std::string> &maze) {
  std::cout << message << std::endl;
  std::cout << "---" << std::endl << std::endl;
  for (auto &row : maze) {
    std::cout << row << std::endl;
  }
}
} // namespace util

int main() {
  std::vector<int> vec = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  util::print_vector(vec);
  algorithm::bubble_sort(vec);
  util::print_vector(vec);
  auto search = 4;
  std::cout << "The value " << search
            << (algorithm::binary_search(vec, search) ? " was " : " was not ")
            << "found" << std::endl;

  search = 11;
  std::cout << "The value " << search
            << (algorithm::binary_search(vec, search) ? " was " : " was not ")
            << "found" << std::endl;

  auto val = util::sum(3);
  std::cout << "The value of the recurse sum() is " << val << std::endl;

  std::vector<std::string> maze = {
      "######### #######",
			"#       #       #",
			"# ############# #",
      "#               #",
			"# ###############",
  };

  util::print_maze("Maze Before Solve:", maze);
  algorithm::point start{1, 4};
  algorithm::point end{9, 0};
  auto solved = algorithm::solve_maze(maze, '#', start, end);
  for (auto &p : solved) {
    auto x = p.x;
    auto y = p.y;
    maze[y][x] = '^';
  }

  util::print_maze("Maze After Solve:", maze);

  std::vector<int> a = {1, 8, 7, 2, 3, 10, 11, 12, 4, 5};

  std::cout << "Array before quicksort..." << std::endl;
  util::print_vector(a);

  algorithm::quick_sort(a);
  std::cout << "Array after quicksort..." << std::endl;
  util::print_vector(a);

  return 0;
}
