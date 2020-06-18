//!
//! @author jbruel
//! @date 12/06/2020
//! @file CSVParser.hpp
//! @brief Askia parser according instruction from the technical test.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP

# include <vector>
# include <string>
# include <sstream>
# include <regex>

//!
//! @namespace askia
//!
namespace askia
{
    using CSVField = std::string; //!< A single csv field is translated into a string.
    using CSVRow = std::vector<CSVField>; //!< A csv row is a sequence of field.
    using CSVContent = std::vector<CSVRow>; //!< A csv content is a sequence of row. This type can contain a full csv file.

    //!
    //! @class CSVParser
    //! @brief Askia parser according instruction from the technical test.
    //!
    class   CSVParser final
    {
    private:
        char    mSeparator; //!< Single character used to split csv field.

    public:
        //!
        //! @brief CSVParser default constructor.
        //!
        CSVParser() : mSeparator(',') {}
        //!
        //! @brief Copy constructor.
        //! @warning Not available.
        //!
        CSVParser(const CSVParser &) = delete;
        //!
        //! @brief Equal operator overload.
        //! @warning Not available.
        //!
        CSVParser  &operator=(const CSVParser &) = delete;
        //!
        //! @brief CSVParser destructor.
        //!
        ~CSVParser() = default;

    public:
        //!
        //! @brief Initialize the field separator.
        //! @param separator Single character used to split csv field.
        //!
        inline void setFieldSeparator(char separator) noexcept { mSeparator = separator; }
        //!
        //! @brief Extract the field separator.
        //! @return Single character used to split csv field.
        //!
        [[nodiscard]]
        inline char getFieldSeparator() const noexcept { return (mSeparator); }

    public:
        //!
        //! @brief Parse a csv file.
        //! @param filePath File path used to find the file and parse it.
        //! @return The csv file content into a structured format.
        //! @throw Raise if the file path is invalid.
        //!
        [[nodiscard]]
        askia::CSVContent   parse(const char *filePath) const noexcept(false);

    private:
        //!
        //! @brief Parse a csv row according a already open file.
        //! @param csvInputFile CSV input file already opened.
        //! @return A csv row is a sequence of field.
        //!
        [[nodiscard]]
        askia::CSVRow   parseRow(std::istream &csvInputFile) const noexcept;
        //!
        //! @brief Add field into the csv row and clear it.
        //! @param row Where to add the field.
        //! @param field Field to add into the row if valid.
        //! @return Row in parameter, use full for chaining.
        //!
        [[maybe_unused]]
        askia::CSVRow   &addFieldIntoRow(askia::CSVRow &row, askia::CSVField &field) const noexcept;
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
