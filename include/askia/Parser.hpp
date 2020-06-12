//!
//! @author jbruel
//! @date 12/06/2020
//! @file Parser.hpp
//! @brief Askia parser according instruction from the technical test.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP

# include "jsoncons/json.hpp"
# include <string>

namespace askia
{
    class   Parser final
    {
    private:
        jsoncons::json  mJsonFileResult;

    public:
        Parser() = default;
        Parser(const Parser &) = delete;
        Parser  &operator=(const Parser &) = delete;
        ~Parser() = default;

    public:
        void read(const char *csvInputFilePath, bool hasHeader = false) noexcept(false);
        void print(const char *jsonOutputFilePath) const noexcept(false);
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
