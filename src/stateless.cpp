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
                  const std::string s = s0 + s1 + s2;
                  int idx = string_search(s, s1);
                  for (int i = 0; i < s1.length(); i++) {
                      RC_ASSERT(s1[i] == s[idx++]);
                  }
              });
    return 0;
}
