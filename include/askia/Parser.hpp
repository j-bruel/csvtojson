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

//!
//! @namespace askia
//!
namespace askia
{
    //!
    //! @class Parser
    //! @brief Askia parser according instruction from the technical test.
    //!
    class   Parser final
    {
    private:
        jsoncons::json  mJsonFileResult; //!< jsoncons is a C++, header-only library for constructing JSON and JSON-like.

    public:
        //!
        //! @brief Parser default constructor.
        //!
        Parser() = default;
        //!
        //! @brief Copy constructor.
        //! @warning Not avaiable.
        //!
        Parser(const Parser &) = delete;
        //!
        //! @brief Equal operator overload.
        //! @warning Not available.
        //!
        Parser  &operator=(const Parser &) = delete;
        //!
        //! @brief Parser destructor.
        //!
        ~Parser() = default;

    public:
        //!
        //! @brief Read a CSV file.
        //! @param csvInputFilePath CSV input file path.
        //! @param hasHeader Tell if the CSV file has a header or not. Default value : false.
        //!
        void read(const char *csvInputFilePath, bool hasHeader = false) noexcept(false);
        //!
        //! @brief Print the CSV parsed file into a target file in JSON format.
        //! @param jsonOutputFilePath Path to the target JSON file.
        //!
        void print(const char *jsonOutputFilePath) const noexcept(false);

    public:
        //!
        //! @brief Check if parsed CSV file has success.
        //! @return CSV file parsing status.
        //!
        [[nodiscard]]
        inline bool isValid() const { return (!mJsonFileResult.empty()); }
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_PARSER_HPP
