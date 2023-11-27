/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#ifndef TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
#define TOUCHGFX_APPLICATIONFONTPROVIDER_HPP

#include <touchgfx/FontManager.hpp>

namespace touchgfx
{
class FlashDataReader;
}

struct Typography
{
    static const touchgfx::FontId DEFAULT = 0;
    static const touchgfx::FontId LARGE = 1;
    static const touchgfx::FontId SMALL = 2;
    static const touchgfx::FontId DUBAIBOLD_70 = 3;
    static const touchgfx::FontId LIGHT_60 = 4;
    static const touchgfx::FontId DUBAIBOLD_30 = 5;
    static const touchgfx::FontId DUBAIMEDIUM_20 = 6;
    static const touchgfx::FontId DUBAIBOLD_20 = 7;
    static const touchgfx::FontId DUBAIMEDIUM_20_EN = 8;
    static const touchgfx::FontId DUBAIMEDIUM_100 = 9;
    static const touchgfx::FontId MEDIUM_25 = 10;
    static const touchgfx::FontId LIGHT_25 = 11;
};

struct TypographyFontIndex
{
    static const touchgfx::FontId DEFAULT = 0;           // verdana_20_4bpp
    static const touchgfx::FontId LARGE = 1;             // verdana_40_4bpp
    static const touchgfx::FontId SMALL = 2;             // verdana_10_4bpp
    static const touchgfx::FontId DUBAIBOLD_70 = 3;      // DUBAI_BOLD_TTF_70_8bpp
    static const touchgfx::FontId LIGHT_60 = 4;          // DUBAI_LIGHT_TTF_60_8bpp
    static const touchgfx::FontId DUBAIBOLD_30 = 5;      // DUBAI_BOLD_TTF_30_4bpp
    static const touchgfx::FontId DUBAIMEDIUM_20 = 6;    // DUBAI_MEDIUM_TTF_20_4bpp
    static const touchgfx::FontId DUBAIBOLD_20 = 7;      // DUBAI_BOLD_TTF_20_4bpp
    static const touchgfx::FontId DUBAIMEDIUM_20_EN = 0; // verdana_20_4bpp
    static const touchgfx::FontId DUBAIMEDIUM_100 = 8;   // DUBAI_MEDIUM_TTF_250_4bpp
    static const touchgfx::FontId MEDIUM_25 = 9;         // DUBAI_MEDIUM_TTF_25_4bpp
    static const touchgfx::FontId LIGHT_25 = 10;          // DUBAI_LIGHT_TTF_25_4bpp
    static const uint16_t NUMBER_OF_FONTS = 11;
};

class ApplicationFontProvider : public touchgfx::FontProvider
{
public:
    virtual touchgfx::Font* getFont(touchgfx::FontId typography);

    static void setFlashReader(touchgfx::FlashDataReader* /*flashReader*/)
    {
    }

    static touchgfx::FlashDataReader* getFlashReader()
    {
        return 0;
    }
};

#endif // TOUCHGFX_APPLICATIONFONTPROVIDER_HPP
