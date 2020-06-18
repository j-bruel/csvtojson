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
    //!
    //! @class JSONPrinter
    //! @brief A simple json printer according Asking instruction.
    //!
    class JSONPrinter final
    {
    public:
        //!
        //! @brief JSONPrinter default constructor.
        //!
        JSONPrinter() = default;
        //!
        //! @brief Copy constructor.
        //! @warning Not available.
        //!
        JSONPrinter(const JSONPrinter &) = delete;
        //!
        //! @brief Equal operator overload.
        //! @warning Not available.
        //!
        JSONPrinter &operator=(const JSONPrinter &) = delete;
        //!
        //! @brief JSONPrinter destructor.
        //!
        ~JSONPrinter() = default;

    public:
        //!
        //! @brief Print csv data into a target json file.
        //! @param outputFilePath Output json file path.
        //! @param csvContent CSV data to write into the target file.
        //! @param isHeader Tell if CSV data has a header to define object.
        //! @throw If output file is not correctly set.
        //!
        void    print(const char *outputFilePath, const CSVContent &csvContent, bool isHeader = false) const noexcept(false);

    private:
        //!
        //! @brief Stream data into a array in JSON format.
        //! @param jsonOutputFileStream JSON output file stream.
        //! @param csvContent Data to stream into the target json file.
        //!
        void    array(std::ofstream &jsonOutputFileStream, const CSVContent &csvContent) const noexcept;
        //!
        //! @brief Stream data into object format in JSON.
        //! @param jsonOutputFileStream JSON output file stream.
        //! @param header Object header, define each field.
        //! @param csvContent Data to stream into the target json file.
        //!
        void    object(std::ofstream &jsonOutputFileStream, const CSVRow &header, const CSVContent &csvContent) const noexcept;

    private:
        //!
        //! @brief Formatting the string field into the target json format.
        //! @param str Input string to format.
        //! @param isHeaderField Tell if the string if a header field. If this is the case, number will be into quotes.
        //! @return Formatted string.
        //!
        [[nodiscard]]
        std::string stringFormatting(const std::string &str, bool isHeaderField = false) const noexcept;
        //!
        //! @brief Check if the input string is a numeric value.
        //! @param value String to check.
        //! @return State, true if is a numeric, false if not.
        //!
        [[nodiscard]]
        inline bool isNumeric(const std::string &value) const noexcept(false)
                    { return (!value.empty() && std::all_of(value.begin(), value.end(), [](unsigned char c){ return std::isdigit(c); })); }
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
