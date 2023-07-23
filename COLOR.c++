#include "COLOR.h++"

namespace Color {

    /**
     * @brief Overloaded stream insertion operator to apply color codes.
     * @param os The output stream object.
     * @param code The Code enum representing the color code.
     * @return Reference to the modified output stream with color code applied.
     */
    std::ostream& operator<<(std::ostream& os, Code code) {
        // Apply the color code to the output stream using ANSI escape sequences.
        return os << "\033[" << static_cast<int>(code) << "m";
    }
}
