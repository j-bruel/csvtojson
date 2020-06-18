//!
//! @author jbruel
//! @date 17/06/2020
//! @file JSONPrinter.hpp
//! @brief A simple json printer according Asking instruction.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP

# include "askia/CSVParser.hpp"

//!
//! @namespace askia
//!
namespace askia
{
    class JSONPrinter final
    {
    public:
        static void print(const char *outputFilePath, const CSVContent &csvContent, bool isHeader = false) noexcept(false);

    private:
        static void array(std::ofstream &jsonOutputFileStream, const CSVContent &csvContent) noexcept(false);
        static void object(std::ofstream &jsonOutputFileStream, const CSVRow &header, const CSVContent &csvContent) noexcept(false);
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
