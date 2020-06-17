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

//!
//! @namespace askia
//!
namespace askia
{
    //!
    //! @class CSVParser
    //! @brief Askia parser according instruction from the technical test.
    //!
    class   CSVParser final
    {
    private:
        char    mSeparator;

    public:
        //!
        //! @brief CSVParser default constructor.
        //!
        CSVParser() : mSeparator(',') {}
        //!
        //! @brief Copy constructor.
        //! @warning Not avaiable.
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
        inline void setFieldSeparator(char separator) noexcept(false) { mSeparator = separator; }
        [[nodiscard]]
        inline char getFieldSeparator() const noexcept(false) { return (mSeparator); }

    public:
        [[nodiscard]]
        std::vector<std::string>    parseRow(std::istream &in) const noexcept(false);

    private:
//        bool    isFieldIntoQuotes() const noexcept(false) { }
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
