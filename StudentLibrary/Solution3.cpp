#include "Solution3.h"

// Don't forget to enable the exercise in the StudentConfiguration.h file!
#include "StudentConfiguration.h"
#include <stdexcept>
#include <algorithm>
#ifdef COMPILE_EXERCICE_3

void Solution3::SetWords(const std::vector<std::string>& _words)
{
    words = _words;
}

void Solution3::SortWords()
{
    if (words.empty())
    {
        throw std::logic_error("Cannot sort an empty vector of words");
    }

    // Custom comparison function for case-insensitive alphabetical sorting
    auto caseInsensitiveCompare = [](const std::string& a, const std::string& b) {
        return std::lexicographical_compare(a.begin(), a.end(), b.begin(), b.end(), [](char c1, char c2) {
            return std::tolower(c1) < std::tolower(c2);
            });
        };

    std::sort(words.begin(), words.end(), caseInsensitiveCompare);
}

std::vector<std::string> Solution3::GetSortedWords() const
{
    return words;
}

#endif