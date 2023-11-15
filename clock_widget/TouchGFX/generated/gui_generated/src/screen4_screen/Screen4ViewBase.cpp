/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/screen4_screen/Screen4ViewBase.hpp>
#include <touchgfx/Color.hpp>
#include <videos/VideoDatabase.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

Screen4ViewBase::Screen4ViewBase() :
    buttonCallback(this, &Screen4ViewBase::buttonCallbackHandler)
{
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    videoConfused.setPosition(0, 0, 480, 272);
    videoConfused.setVideoData(video_confused_bin_start, video_confused_bin_length);
    videoConfused.setRepeat(true);
    videoConfused.play();
    add(videoConfused);

    buttonPrev.setXY(12, 223);
    buttonPrev.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_PRESSED_ID));
    buttonPrev.setAction(buttonCallback);
    add(buttonPrev);

    buttonNext.setXY(431, 223);
    buttonNext.setBitmaps(touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_NORMAL_ID), touchgfx::Bitmap(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_BUTTON_ICON_ROUND_MICRO_FILL_PRESSED_ID));
    buttonNext.setAction(buttonCallback);
    add(buttonNext);

    textVideo.setXY(147, 0);
    textVideo.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textVideo.setLinespacing(0);
    textVideo.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S74C));
    add(textVideo);
}

Screen4ViewBase::~Screen4ViewBase()
{

}

void Screen4ViewBase::setupScreen()
{

}

void Screen4ViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonPrev)
    {
        //Prev
        //When buttonPrev clicked change screen to Screen3
        //Go to Screen3 with no screen transition
        application().gotoScreen3ScreenNoTransition();
    }
    if (&src == &buttonNext)
    {
        //Next
        //When buttonNext clicked change screen to Screen5
        //Go to Screen5 with no screen transition
        application().gotoScreen5ScreenNoTransition();
    }
}
