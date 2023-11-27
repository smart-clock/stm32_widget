/* DO NOT EDIT THIS FILE */
/* This file is autogenerated by the text-database code generator */

#include <fonts/ApplicationFontProvider.hpp>
#include <fonts/GeneratedFont.hpp>
#include <texts/TypedTextDatabase.hpp>

touchgfx::Font* ApplicationFontProvider::getFont(touchgfx::FontId typography)
{
    switch (typography)
    {
    case Typography::DEFAULT:
        // verdana_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::LARGE:
        // verdana_40_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[1]);
    case Typography::SMALL:
        // verdana_10_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[2]);
    case Typography::DUBAIBOLD_70:
        // DUBAI_BOLD_TTF_70_8bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[3]);
    case Typography::LIGHT_60:
        // DUBAI_LIGHT_TTF_60_8bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[4]);
    case Typography::DUBAIBOLD_30:
        // DUBAI_BOLD_TTF_30_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[5]);
    case Typography::DUBAIMEDIUM_20:
        // DUBAI_MEDIUM_TTF_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[6]);
    case Typography::DUBAIBOLD_20:
        // DUBAI_BOLD_TTF_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[7]);
    case Typography::DUBAIMEDIUM_20_EN:
        // verdana_20_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[0]);
    case Typography::DUBAIMEDIUM_100:
        // DUBAI_MEDIUM_TTF_250_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[8]);
    case Typography::MEDIUM_25:
        // DUBAI_MEDIUM_TTF_25_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[9]);
    case Typography::LIGHT_25:
        // DUBAI_LIGHT_TTF_25_4bpp
        return const_cast<touchgfx::Font*>(TypedTextDatabase::getFonts()[10]);
    default:
        return 0;
    }
}
