//!
//! @author jbruel
//! @date 12/06/2020
//! @file CSVParser.hpp
//! @brief Askia parser according instruction from the technical test.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP

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
    public:
        //!
        //! @brief CSVParser default constructor.
        //!
        CSVParser() = default;
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
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
