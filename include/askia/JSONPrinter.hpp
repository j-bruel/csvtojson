//!
//! @author jbruel
//! @date 17/06/2020
//! @file JSONPrinter.hpp
//! @brief A simple json printer according Asking instruction.
//!

#ifndef CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
# define CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP

//!
//! @namespace askia
//!
namespace askia
{
    class JSONPrinter final
    {
    public:
        static void array() noexcept(false);
        static void object() noexcept(false);
    };
}

#endif //CSVTOJSON_ASKIA_CSVTOJSON_JSONPRINTER_HPP
