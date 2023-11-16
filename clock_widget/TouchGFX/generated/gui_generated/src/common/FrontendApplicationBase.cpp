/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <new>
#include <gui_generated/common/FrontendApplicationBase.hpp>
#include <gui/common/FrontendHeap.hpp>
#include <touchgfx/transitions/NoTransition.hpp>
#include <texts/TextKeysAndLanguages.hpp>
#include <touchgfx/Texts.hpp>
#include <touchgfx/hal/HAL.hpp>
#include <platform/driver/lcd/LCD16bpp.hpp>
#include <gui/screen1_screen/Screen1View.hpp>
#include <gui/screen1_screen/Screen1Presenter.hpp>
#include <gui/screen2_screen/Screen2View.hpp>
#include <gui/screen2_screen/Screen2Presenter.hpp>
#include <gui/screen3_screen/Screen3View.hpp>
#include <gui/screen3_screen/Screen3Presenter.hpp>
#include <gui/screen4_screen/Screen4View.hpp>
#include <gui/screen4_screen/Screen4Presenter.hpp>
#include <gui/screen5_screen/Screen5View.hpp>
#include <gui/screen5_screen/Screen5Presenter.hpp>
#include <gui/screen6_screen/Screen6View.hpp>
#include <gui/screen6_screen/Screen6Presenter.hpp>
#include <gui/screen7_screen/Screen7View.hpp>
#include <gui/screen7_screen/Screen7Presenter.hpp>
#include <gui/robottheme_screen/robotThemeView.hpp>
#include <gui/robottheme_screen/robotThemePresenter.hpp>
#include <gui/customtheme_screen/customThemeView.hpp>
#include <gui/customtheme_screen/customThemePresenter.hpp>

using namespace touchgfx;

FrontendApplicationBase::FrontendApplicationBase(Model& m, FrontendHeap& heap)
    : touchgfx::MVPApplication(),
      transitionCallback(),
      frontendHeap(heap),
      model(m)
{
    touchgfx::HAL::getInstance()->setDisplayOrientation(touchgfx::ORIENTATION_LANDSCAPE);
    touchgfx::Texts::setLanguage(GB);
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableTextureMapperAll();
    reinterpret_cast<touchgfx::LCD16bpp&>(touchgfx::HAL::lcd()).enableDecompressorL8_All();
}

/*
 * Screen Transition Declarations
 */

// Screen1

void FrontendApplicationBase::gotoScreen1ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen1ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen1ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen1View, Screen1Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen1ScreenSlideTransitionNorth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen1ScreenSlideTransitionNorthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen1ScreenSlideTransitionNorthImpl()
{
    touchgfx::makeTransition<Screen1View, Screen1Presenter, touchgfx::SlideTransition<NORTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen2

void FrontendApplicationBase::gotoScreen2ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen2ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen2ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen2View, Screen2Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen2ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen2ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen2ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen2View, Screen2Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen3

void FrontendApplicationBase::gotoScreen3ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen3ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen3ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen3View, Screen3Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen3ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen3ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen3ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen3View, Screen3Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen4

void FrontendApplicationBase::gotoScreen4ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen4ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen4ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen4View, Screen4Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen4ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen4ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen4ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen4View, Screen4Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen5

void FrontendApplicationBase::gotoScreen5ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen5ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen5ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen5View, Screen5Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen5ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen5ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen5ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen5View, Screen5Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen6

void FrontendApplicationBase::gotoScreen6ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen6ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen6ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen6View, Screen6Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotoScreen6ScreenSlideTransitionWest()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen6ScreenSlideTransitionWestImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen6ScreenSlideTransitionWestImpl()
{
    touchgfx::makeTransition<Screen6View, Screen6Presenter, touchgfx::SlideTransition<WEST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// Screen7

void FrontendApplicationBase::gotoScreen7ScreenSlideTransitionEast()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotoScreen7ScreenSlideTransitionEastImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotoScreen7ScreenSlideTransitionEastImpl()
{
    touchgfx::makeTransition<Screen7View, Screen7Presenter, touchgfx::SlideTransition<EAST>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// robotTheme

void FrontendApplicationBase::gotorobotThemeScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotorobotThemeScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotorobotThemeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<robotThemeView, robotThemePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

void FrontendApplicationBase::gotorobotThemeScreenSlideTransitionSouth()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotorobotThemeScreenSlideTransitionSouthImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotorobotThemeScreenSlideTransitionSouthImpl()
{
    touchgfx::makeTransition<robotThemeView, robotThemePresenter, touchgfx::SlideTransition<SOUTH>, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}

// customTheme

void FrontendApplicationBase::gotocustomThemeScreenNoTransition()
{
    transitionCallback = touchgfx::Callback<FrontendApplicationBase>(this, &FrontendApplicationBase::gotocustomThemeScreenNoTransitionImpl);
    pendingScreenTransitionCallback = &transitionCallback;
}

void FrontendApplicationBase::gotocustomThemeScreenNoTransitionImpl()
{
    touchgfx::makeTransition<customThemeView, customThemePresenter, touchgfx::NoTransition, Model >(&currentScreen, &currentPresenter, frontendHeap, &currentTransition, &model);
}