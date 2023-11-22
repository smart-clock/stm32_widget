// 4.22.1 0x1f846649
// Generated by imageconverter. Please, do not edit!

#include <images/BitmapDatabase.hpp>
#include <touchgfx/Bitmap.hpp>

extern const unsigned char image_play_pressed_64x64[]; // BITMAP_PLAY_PRESSED_64X64_ID = 0, Size: 64x64 pixels
extern const unsigned char image_play_released_64x64[]; // BITMAP_PLAY_RELEASED_64X64_ID = 1, Size: 64x64 pixels
extern const unsigned char image_reset_pressed_64x64[]; // BITMAP_RESET_PRESSED_64X64_ID = 2, Size: 64x64 pixels
extern const unsigned char image_reset_released_64x64[]; // BITMAP_RESET_RELEASED_64X64_ID = 3, Size: 64x64 pixels
extern const unsigned char image_stop_pressed_64x64[]; // BITMAP_STOP_PRESSED_64X64_ID = 4, Size: 64x64 pixels
extern const unsigned char image_stop_released_64x64[]; // BITMAP_STOP_RELEASED_64X64_ID = 5, Size: 64x64 pixels

const touchgfx::Bitmap::BitmapData bitmap_database[] = {
    { image_play_pressed_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_play_released_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_reset_pressed_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_reset_released_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_stop_pressed_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 },
    { image_stop_released_64x64, 0, 64, 64, 4, 4, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) >> 3, 56, ((uint8_t)touchgfx::Bitmap::ARGB8888) & 0x7 }
};

namespace BitmapDatabase
{
const touchgfx::Bitmap::BitmapData* getInstance()
{
    return bitmap_database;
}

uint16_t getInstanceSize()
{
    return (uint16_t)(sizeof(bitmap_database) / sizeof(touchgfx::Bitmap::BitmapData));
}
} // namespace BitmapDatabase
