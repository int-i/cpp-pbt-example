#include <string>
#include <rapidcheck.h>

int string_search(const std::string &haystack, const std::string &needle) {
    return haystack.find(needle);
}

int main() {
    rc::check("should always contain itself",
              [](const std::string &s0) {
                  RC_ASSERT(string_search(s0, s0) == 0);
              });
    rc::check("should always contain its substrings",
              [](const std::string &s0, const std::string &s1, const std::string &s2) {
                  if (s1.empty()) {
                      RC_ASSERT(string_search(s0 + s1 + s2, s1) == 0);
                  } else {
                      RC_ASSERT(string_search(s0 + s1 + s2, s1) == s0.length());
                  }
              });
    return 0;
}
