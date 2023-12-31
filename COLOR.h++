
/**

    @file Color.hpp
    @brief Header file for the Color namespace, which defines color codes for text output in the console. */
#ifndef COLOR_HPP
#define COLOR_HPP
#include <ostream>


/**

    @namespace Color

    @brief Namespace that defines color codes for text output in the console.
    */

namespace Color {
    enum Code {
        NORMAL = 0,
        BOLD = 1,
        FAINT = 2,
        ITALIC = 3,
        UNDERLINE = 4,
        RIVERCED = 26,
        FG_BLACK = 30,
        FG_RED = 31,
        FG_GREEN = 32,
        FG_YELLOW = 33,
        FG_BLUE = 34,
        FG_MAGENTA = 35,
        FG_CYAN = 36,
        FG_LIGHT_GRAY = 37,
        FG_DEFAULT = 39,
        BG_RED = 41,
        BG_GREEN = 42,
        BG_BLUE = 44,
        BG_DEFAULT = 49,
        FRAMED = 51,
        FG_DARK_GRAY = 90,
        FG_LIGHT_RED = 91,
        FG_LIGHT_GREEN = 92,
        FG_LIGHT_YELLOW = 93,
        FG_LIGHT_BLUE = 94,
        FG_LIGHT_MAGENTA = 95,
        FG_LIGHT_CYAN = 96,
        FG_WHITE = 97,
    };
    std::ostream& operator<<(std::ostream& os, Code code);
}

#endif // COLOR_HPP
