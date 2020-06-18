//!
//! @author jbruel
//! @date 17/06/2020
//! @file JSONPrinter.hpp
//! @brief A simple json printer according Asking instruction.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP

# include "askia/CSVParser.hpp"
# include <cctype>

//!
//! @namespace askia
//!
namespace askia
{
    class JSONPrinter final
    {
    public:
        void    print(const char *outputFilePath, const CSVContent &csvContent, bool isHeader = false) const noexcept(false);

    private:
        void    array(std::ofstream &jsonOutputFileStream, const CSVContent &csvContent) const noexcept;
        void    object(std::ofstream &jsonOutputFileStream, const CSVRow &header, const CSVContent &csvContent) const noexcept;

    private:
        [[nodiscard]]
        std::string stringFormatting(const std::string &str) const noexcept;
        [[nodiscard]]
        inline bool isNumeric(const std::string &value) const noexcept(false)
                    { return std::all_of(value.begin(), value.end(), [](unsigned char c){ return std::isdigit(c); }); }
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
