/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/clock_screen/ClockViewBase.hpp>
#include <touchgfx/canvas_widget_renderer/CanvasWidgetRenderer.hpp>
#include <touchgfx/Color.hpp>
#include <images/BitmapDatabase.hpp>
#include <texts/TextKeysAndLanguages.hpp>

ClockViewBase::ClockViewBase() :
    updateItemCallback(this, &ClockViewBase::updateItemCallbackHandler),
    buttonCallback(this, &ClockViewBase::buttonCallbackHandler)
{
    touchgfx::CanvasWidgetRenderer::setupBuffer(canvasBuffer, CANVAS_BUFFER_SIZE);
    
    __background.setPosition(0, 0, 480, 272);
    __background.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    add(__background);

    background.setXY(0, 0);
    background.setBitmap(touchgfx::Bitmap(BITMAP_MANGGOM_ID));
    add(background);

    swipeContainerWidget.setXY(0, 0);
    swipeContainerWidget.setPageIndicatorBitmaps(touchgfx::Bitmap(BITMAP_LIGHT_THEME_IMAGES_WIDGETS_SWIPECONTAINER_MEDIUM_OFF_NORMAL_ID), touchgfx::Bitmap(BITMAP_CLAY_THEME_IMAGES_WIDGETS_SWIPECONTAINER_MEDIUM_ON_NORMAL_ID));
    swipeContainerWidget.setPageIndicatorXY(160, 250);
    swipeContainerWidget.setSwipeCutoff(50);
    swipeContainerWidget.setEndSwipeElasticWidth(50);

    home.setWidth(480);
    home.setHeight(272);
    textHomeClock.setXY(170, 83);
    textHomeClock.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textHomeClock.setLinespacing(0);
    touchgfx::Unicode::snprintf(textHomeClockBuffer1, TEXTHOMECLOCKBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_3NT3).getText());
    textHomeClock.setWildcard1(textHomeClockBuffer1);
    touchgfx::Unicode::snprintf(textHomeClockBuffer2, TEXTHOMECLOCKBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_IB3Y).getText());
    textHomeClock.setWildcard2(textHomeClockBuffer2);
    textHomeClock.resizeToCurrentText();
    textHomeClock.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TBRP));
    home.add(textHomeClock);

    textHomeDate.setXY(174, 160);
    textHomeDate.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textHomeDate.setLinespacing(0);
    touchgfx::Unicode::snprintf(textHomeDateBuffer1, TEXTHOMEDATEBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_1INA).getText());
    textHomeDate.setWildcard1(textHomeDateBuffer1);
    touchgfx::Unicode::snprintf(textHomeDateBuffer2, TEXTHOMEDATEBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_L5KR).getText());
    textHomeDate.setWildcard2(textHomeDateBuffer2);
    textHomeDate.resizeToCurrentText();
    textHomeDate.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XXQ4));
    home.add(textHomeDate);

    textHomeDay.setXY(255, 160);
    textHomeDay.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textHomeDay.setLinespacing(0);
    Unicode::snprintf(textHomeDayBuffer, TEXTHOMEDAY_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_4YYQ).getText());
    textHomeDay.setWildcard(textHomeDayBuffer);
    textHomeDay.resizeToCurrentText();
    textHomeDay.setTypedText(touchgfx::TypedText(T___SINGLEUSE_DGOO));
    home.add(textHomeDay);

    buttonSetting.setXY(0, 25);
    buttonSetting.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_SETTINGS_APPLICATIONS_55_55_6B6B6B_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_SETTINGS_APPLICATIONS_55_55_000000_SVG_ID));
    buttonSetting.setAction(buttonCallback);
    home.add(buttonSetting);

    buttonDebugIn.setXY(1, 215);
    buttonDebugIn.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_BUG_REPORT_55_55_6B6B6B_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_BUG_REPORT_55_55_000000_SVG_ID));
    buttonDebugIn.setAction(buttonCallback);
    home.add(buttonDebugIn);

    swipeContainerWidget.add(home);

    whether.setWidth(480);
    whether.setHeight(272);
    boxBlurWhether.setPosition(0, -1, 480, 274);
    boxBlurWhether.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurWhether.setAlpha(150);
    whether.add(boxBlurWhether);

    textTemp.setXY(77, 120);
    textTemp.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTemp.setLinespacing(0);
    Unicode::snprintf(textTempBuffer, TEXTTEMP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_5ECF).getText());
    textTemp.setWildcard(textTempBuffer);
    textTemp.resizeToCurrentText();
    textTemp.setTypedText(touchgfx::TypedText(T___SINGLEUSE_EI1R));
    whether.add(textTemp);

    textDegree.setXY(155, 133);
    textDegree.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textDegree.setLinespacing(0);
    textDegree.setTypedText(touchgfx::TypedText(T___SINGLEUSE_VQ07));
    whether.add(textDegree);

    textC.setXY(171, 118);
    textC.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textC.setLinespacing(0);
    textC.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AQKR));
    whether.add(textC);

    textWhether.setXY(239, -56);
    textWhether.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textWhether.setLinespacing(0);
    textWhether.setTypedText(touchgfx::TypedText(T___SINGLEUSE_CW4O));
    whether.add(textWhether);

    textRegion.setPosition(110, 74, 116, 29);
    textRegion.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textRegion.setLinespacing(0);
    Unicode::snprintf(textRegionBuffer, TEXTREGION_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_PX5Y).getText());
    textRegion.setWildcard(textRegionBuffer);
    textRegion.setTypedText(touchgfx::TypedText(T___SINGLEUSE_AL19));
    whether.add(textRegion);

    textWeather.setPosition(336, 47, 116, 29);
    textWeather.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textWeather.setLinespacing(0);
    Unicode::snprintf(textWeatherBuffer, TEXTWEATHER_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_PNB4).getText());
    textWeather.setWildcard(textWeatherBuffer);
    textWeather.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RQJH));
    whether.add(textWeather);

    imageSnow.setXY(267, 78);
    imageSnow.setBitmap(touchgfx::Bitmap(BITMAP_SNOW_128X128_ID));
    imageSnow.setVisible(false);
    whether.add(imageSnow);

    imageRain.setXY(267, 78);
    imageRain.setBitmap(touchgfx::Bitmap(BITMAP_RAIN_128X128_ID));
    imageRain.setVisible(false);
    whether.add(imageRain);

    imageDrizzel.setXY(267, 78);
    imageDrizzel.setBitmap(touchgfx::Bitmap(BITMAP_DRIZZEL_128X128_ID));
    imageDrizzel.setVisible(false);
    whether.add(imageDrizzel);

    imageThunder.setXY(267, 78);
    imageThunder.setBitmap(touchgfx::Bitmap(BITMAP_THUNDER_128X128_ID));
    imageThunder.setVisible(false);
    whether.add(imageThunder);

    imageFog.setXY(267, 78);
    imageFog.setBitmap(touchgfx::Bitmap(BITMAP_FOG_128X128_ID));
    imageFog.setVisible(false);
    whether.add(imageFog);

    imageClear.setXY(267, 78);
    imageClear.setBitmap(touchgfx::Bitmap(BITMAP_SUN_128X128_ID));
    imageClear.setVisible(false);
    whether.add(imageClear);

    imageCloud.setXY(267, 78);
    imageCloud.setBitmap(touchgfx::Bitmap(BITMAP_CLOUD_128X128_ID));
    imageCloud.setVisible(false);
    whether.add(imageCloud);

    imageLocation.setXY(73, 77);
    imageLocation.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_MAPS_LOCATION_PIN_30_30_FFFFFF_SVG_ID));
    whether.add(imageLocation);

    swipeContainerWidget.add(whether);

    StopWatch.setWidth(480);
    StopWatch.setHeight(272);
    boxBlurStop.setPosition(0, -1, 480, 274);
    boxBlurStop.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurStop.setAlpha(150);
    StopWatch.add(boxBlurStop);

    digitalClock.setPosition(97, 58, 285, 107);
    digitalClock.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    digitalClock.setTypedText(touchgfx::TypedText(T___SINGLEUSE_PQN4));
    digitalClock.displayLeadingZeroForHourIndicator(true);
    digitalClock.setDisplayMode(touchgfx::DigitalClock::DISPLAY_24_HOUR);
    digitalClock.setTime24Hour(0, 0, 0);
    StopWatch.add(digitalClock);

    buttonReset.setXY(290, 166);
    buttonReset.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_REPLAY_CIRCLE_FILLED_60_60_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_LOOP_60_60_FFFFFF_SVG_ID));
    buttonReset.setAction(buttonCallback);
    StopWatch.add(buttonReset);

    buttonStop.setXY(210, 166);
    buttonStop.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_PAUSE_CIRCLE_FILLED_60_60_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_PAUSE_CIRCLE_OUTLINE_60_60_FFFFFF_SVG_ID));
    buttonStop.setAction(buttonCallback);
    StopWatch.add(buttonStop);

    buttonPlay.setXY(128, 165);
    buttonPlay.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_PLAY_CIRCLE_FILLED_60_60_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_AV_PLAY_CIRCLE_OUTLINE_60_60_FFFFFF_SVG_ID));
    buttonPlay.setAction(buttonCallback);
    StopWatch.add(buttonPlay);

    swipeContainerWidget.add(StopWatch);

    Timer.setWidth(480);
    Timer.setHeight(272);
    boxBlurTimer.setPosition(0, -1, 480, 274);
    boxBlurTimer.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurTimer.setAlpha(150);
    Timer.add(boxBlurTimer);

    buttonTimerMax.setXY(60, 170);
    buttonTimerMax.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_ADD_CIRCLE_50_50_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_ADD_CIRCLE_OUTLINE_50_50_FFFFFF_SVG_ID));
    buttonTimerMax.setAction(buttonCallback);
    Timer.add(buttonTimerMax);

    buttonTimerMin.setXY(370, 170);
    buttonTimerMin.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_REMOVE_CIRCLE_50_50_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_CONTENT_REMOVE_CIRCLE_OUTLINE_50_50_FFFFFF_SVG_ID));
    buttonTimerMin.setAction(buttonCallback);
    Timer.add(buttonTimerMin);

    circleGaugeBackground.setPosition(140, 24, 200, 200);
    circleGaugeBackground.setCenter(100, 100);
    circleGaugeBackground.setRadius(100);
    circleGaugeBackground.setLineWidth(0);
    circleGaugeBackground.setArc(0, 360);
    circleGaugeBackgroundPainter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    circleGaugeBackground.setPainter(circleGaugeBackgroundPainter);
    Timer.add(circleGaugeBackground);

    gaugeTimer.setBackground(touchgfx::Bitmap(BITMAP_CLOCK_ID));
    gaugeTimer.setPosition(140, 24, 200, 200);
    gaugeTimer.setCenter(100, 100);
    gaugeTimer.setStartEndAngle(-2, 358);
    gaugeTimer.setRange(0, 360);
    gaugeTimer.setValue(0);
    gaugeTimer.setNeedle(BITMAP_ALTERNATE_THEME_IMAGES_WIDGETS_GAUGE_MEDIUM_NEEDLES_SMOOTH_ID, 7, 67);
    gaugeTimer.setMovingNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    gaugeTimer.setSteadyNeedleRenderingAlgorithm(touchgfx::TextureMapper::BILINEAR_INTERPOLATION);
    gaugeTimer.setArcVisible();
    gaugeTimerPainter.setColor(touchgfx::Color::getColorFromRGB(255, 64, 64));
    gaugeTimer.getArc().setPainter(gaugeTimerPainter);
    gaugeTimer.getArc().setRadius(0);
    gaugeTimer.getArc().setLineWidth(140);
    gaugeTimer.getArc().setCapPrecision(180);
    Timer.add(gaugeTimer);

    textTimer.setXY(320, 30);
    textTimer.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textTimer.setLinespacing(0);
    touchgfx::Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_T1W6).getText());
    textTimer.setWildcard1(textTimerBuffer1);
    touchgfx::Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_HY8M).getText());
    textTimer.setWildcard2(textTimerBuffer2);
    textTimer.resizeToCurrentText();
    textTimer.setTypedText(touchgfx::TypedText(T___SINGLEUSE_S02A));
    Timer.add(textTimer);

    swipeContainerWidget.add(Timer);

    Alarm.setWidth(480);
    Alarm.setHeight(272);
    boxBlurAlarm.setPosition(0, -1, 480, 274);
    boxBlurAlarm.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurAlarm.setAlpha(150);
    Alarm.add(boxBlurAlarm);

    hourScrollWheel.setPosition(60, 61, 110, 150);
    hourScrollWheel.setHorizontal(false);
    hourScrollWheel.setCircular(false);
    hourScrollWheel.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    hourScrollWheel.setSwipeAcceleration(10);
    hourScrollWheel.setDragAcceleration(10);
    hourScrollWheel.setNumberOfItems(12);
    hourScrollWheel.setSelectedItemOffset(45);
    hourScrollWheel.setSelectedItemExtraSize(0, 0);
    hourScrollWheel.setSelectedItemMargin(0, 0);
    hourScrollWheel.setDrawableSize(60, 0);
    hourScrollWheel.setDrawables(hourScrollWheelListItems, updateItemCallback,
    
                          hourScrollWheelSelectedListItems, updateItemCallback);
    hourScrollWheel.animateToItem(0, 0);
    Alarm.add(hourScrollWheel);

    minuteScrollWheel.setPosition(190, 61, 110, 150);
    minuteScrollWheel.setHorizontal(false);
    minuteScrollWheel.setCircular(false);
    minuteScrollWheel.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    minuteScrollWheel.setSwipeAcceleration(10);
    minuteScrollWheel.setDragAcceleration(10);
    minuteScrollWheel.setNumberOfItems(60);
    minuteScrollWheel.setSelectedItemOffset(45);
    minuteScrollWheel.setSelectedItemExtraSize(0, 0);
    minuteScrollWheel.setSelectedItemMargin(0, 0);
    minuteScrollWheel.setDrawableSize(60, 0);
    minuteScrollWheel.setDrawables(minuteScrollWheelListItems, updateItemCallback,
    
                          minuteScrollWheelSelectedListItems, updateItemCallback);
    minuteScrollWheel.animateToItem(0, 0);
    Alarm.add(minuteScrollWheel);

    toggleButtonON.setXY(341, 80);
    toggleButtonON.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_TOGGLE_TOGGLE_OFF_70_70_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_TOGGLE_TOGGLE_ON_70_70_FFFFFF_SVG_ID));
    Alarm.add(toggleButtonON);

    toggleButtonAM.setXY(341, 160);
    toggleButtonAM.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_TOGGLE_TOGGLE_OFF_70_70_FFFFFF_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_TOGGLE_TOGGLE_ON_70_70_FFFFFF_SVG_ID));
    Alarm.add(toggleButtonAM);

    textAreaON.setXY(340, 61);
    textAreaON.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaON.setLinespacing(0);
    textAreaON.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T9QU));
    Alarm.add(textAreaON);

    textAreaAM.setXY(341, 143);
    textAreaAM.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaAM.setLinespacing(0);
    textAreaAM.setTypedText(touchgfx::TypedText(T___SINGLEUSE_KHJB));
    Alarm.add(textAreaAM);

    textAreaColon.setXY(174, 83);
    textAreaColon.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAreaColon.setLinespacing(0);
    textAreaColon.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LRH2));
    Alarm.add(textAreaColon);

    swipeContainerWidget.add(Alarm);

    calendar.setWidth(480);
    calendar.setHeight(272);
    boxBlurCal.setPosition(0, -1, 480, 274);
    boxBlurCal.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurCal.setAlpha(150);
    calendar.add(boxBlurCal);

    scrollList1.setPosition(203, 30, 150, 200);
    scrollList1.setHorizontal(false);
    scrollList1.setCircular(false);
    scrollList1.setEasingEquation(touchgfx::EasingEquations::backEaseOut);
    scrollList1.setSwipeAcceleration(10);
    scrollList1.setDragAcceleration(10);
    scrollList1.setNumberOfItems(10);
    scrollList1.setPadding(0, 0);
    scrollList1.setSnapping(false);
    calendar.add(scrollList1);

    boxScheduleBack.setPosition(43, 86, 116, 77);
    boxScheduleBack.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    calendar.add(boxScheduleBack);

    textScheduleTime.setXY(53, 100);
    textScheduleTime.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textScheduleTime.setLinespacing(0);
    textScheduleTime.setTypedText(touchgfx::TypedText(T___SINGLEUSE_UXV2));
    calendar.add(textScheduleTime);

    textSchedule.setXY(53, 130);
    textSchedule.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textSchedule.setLinespacing(0);
    textSchedule.setTypedText(touchgfx::TypedText(T___SINGLEUSE_1ZAU));
    calendar.add(textSchedule);

    swipeContainerWidget.add(calendar);

    Bus.setWidth(480);
    Bus.setHeight(272);
    boxBlurBus.setPosition(0, -1, 480, 274);
    boxBlurBus.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurBus.setAlpha(150);
    Bus.add(boxBlurBus);

    busRoute.setXY(58, 74);
    busRoute.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    busRoute.setLinespacing(0);
    busRoute.setTypedText(touchgfx::TypedText(T___SINGLEUSE_458W));
    Bus.add(busRoute);

    busStation.setXY(88, 165);
    busStation.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    busStation.setLinespacing(0);
    busStation.setTypedText(touchgfx::TypedText(T___SINGLEUSE_LCF4));
    Bus.add(busStation);

    busTime1.setXY(240, 88);
    busTime1.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    busTime1.setLinespacing(0);
    touchgfx::Unicode::snprintf(busTime1Buffer1, BUSTIME1BUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_JREN).getText());
    busTime1.setWildcard1(busTime1Buffer1);
    busTime1.setWildcard2(touchgfx::TypedText(T___SINGLEUSE_1MSQ).getText());
    busTime1.resizeToCurrentText();
    busTime1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_05J5));
    Bus.add(busTime1);

    busTime2.setXY(353, 88);
    busTime2.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    busTime2.setLinespacing(0);
    touchgfx::Unicode::snprintf(busTime2Buffer1, BUSTIME2BUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_S0SF).getText());
    busTime2.setWildcard1(busTime2Buffer1);
    busTime2.setWildcard2(touchgfx::TypedText(T___SINGLEUSE_G9NH).getText());
    busTime2.resizeToCurrentText();
    busTime2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_BW3Y));
    Bus.add(busTime2);

    imageBus1.setXY(254, 136);
    imageBus1.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_MAPS_DEPARTURE_BOARD_65_65_FFFFFF_SVG_ID));
    Bus.add(imageBus1);

    imageBus2.setXY(367, 133);
    imageBus2.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_MAPS_DEPARTURE_BOARD_65_65_FFFFFF_SVG_ID));
    Bus.add(imageBus2);

    swipeContainerWidget.add(Bus);

    stock.setWidth(480);
    stock.setHeight(272);
    boxBlurStock.setPosition(0, -1, 480, 274);
    boxBlurStock.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxBlurStock.setAlpha(150);
    stock.add(boxBlurStock);

    dynamicGraph1.setPosition(-129, 65, 609, 206);
    dynamicGraph1.setScale(1);
    dynamicGraph1.setGraphRangeX(0, 50);
    dynamicGraph1.setGraphAreaMargin(0, 0, 0, 0);
    dynamicGraph1.setGraphAreaPadding(0, 0, 0, 0);
    dynamicGraph1.setGraphRangeY(0, 100);
    dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dynamicGraph1Line1.setPainter(dynamicGraph1Line1Painter);
    dynamicGraph1Line1.setLineWidth(3);
    dynamicGraph1.addGraphElement(dynamicGraph1Line1);

    dynamicGraph1Area1Painter.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dynamicGraph1Area1.setPainter(dynamicGraph1Area1Painter);
    dynamicGraph1Area1.setBaseline(0);
    dynamicGraph1Area1.setAlpha(130);
    dynamicGraph1.addGraphElement(dynamicGraph1Area1);


    dynamicGraph1.addDataPoint(59.13118f);
    dynamicGraph1.addDataPoint(73.09195f);
    dynamicGraph1.addDataPoint(86.25677f);
    dynamicGraph1.addDataPoint(95.62959f);
    dynamicGraph1.addDataPoint(98.94006f);
    dynamicGraph1.addDataPoint(95.19841f);
    dynamicGraph1.addDataPoint(84.94493f);
    dynamicGraph1.addDataPoint(70.13266f);
    dynamicGraph1.addDataPoint(53.67144f);
    dynamicGraph1.addDataPoint(38.74407f);
    dynamicGraph1.addDataPoint(28.06082f);
    dynamicGraph1.addDataPoint(23.23352f);
    dynamicGraph1.addDataPoint(24.42094f);
    dynamicGraph1.addDataPoint(30.33071f);
    dynamicGraph1.addDataPoint(38.57568f);
    dynamicGraph1.addDataPoint(46.29585f);
    dynamicGraph1.addDataPoint(50.89213f);
    dynamicGraph1.addDataPoint(50.69098f);
    dynamicGraph1.addDataPoint(45.37597f);
    dynamicGraph1.addDataPoint(36.07987f);
    dynamicGraph1.addDataPoint(25.11399f);
    dynamicGraph1.addDataPoint(15.40091f);
    dynamicGraph1.addDataPoint(9.74945f);
    dynamicGraph1.addDataPoint(10.14977f);
    dynamicGraph1.addDataPoint(17.26198f);
    dynamicGraph1.addDataPoint(30.22426f);
    dynamicGraph1.addDataPoint(46.82883f);
    dynamicGraph1.addDataPoint(64.02394f);
    dynamicGraph1.addDataPoint(78.6207f);
    dynamicGraph1.addDataPoint(88.03306f);
    dynamicGraph1.addDataPoint(90.87164f);
    dynamicGraph1.addDataPoint(87.24738f);
    dynamicGraph1.addDataPoint(78.71227f);
    dynamicGraph1.addDataPoint(67.85286f);
    dynamicGraph1.addDataPoint(57.63718f);
    dynamicGraph1.addDataPoint(50.67571f);
    dynamicGraph1.addDataPoint(48.57795f);
    dynamicGraph1.addDataPoint(51.56206f);
    dynamicGraph1.addDataPoint(58.41327f);
    dynamicGraph1.addDataPoint(66.80061f);
    dynamicGraph1.addDataPoint(73.87363f);
    dynamicGraph1.addDataPoint(76.9921f);
    dynamicGraph1.addDataPoint(74.40861f);
    dynamicGraph1.addDataPoint(65.73567f);
    dynamicGraph1.addDataPoint(52.0812f);
    dynamicGraph1.addDataPoint(35.81778f);
    dynamicGraph1.addDataPoint(20.04046f);
    dynamicGraph1.addDataPoint(7.84431f);
    dynamicGraph1.addDataPoint(1.59727f);
    dynamicGraph1.addDataPoint(2.38504f);
    dynamicGraph1.addDataPoint(9.76294f);
    dynamicGraph1.addDataPoint(21.87482f);
    dynamicGraph1.addDataPoint(35.90952f);
    dynamicGraph1.addDataPoint(48.78295f);
    dynamicGraph1.addDataPoint(57.87921f);
    dynamicGraph1.addDataPoint(61.66959f);
    dynamicGraph1.addDataPoint(60.05912f);
    dynamicGraph1.addDataPoint(54.37653f);
    dynamicGraph1.addDataPoint(47.0117f);
    dynamicGraph1.addDataPoint(40.79074f);
    dynamicGraph1.addDataPoint(38.24327f);
    dynamicGraph1.addDataPoint(40.94293f);
    dynamicGraph1.addDataPoint(49.08427f);
    dynamicGraph1.addDataPoint(61.40098f);
    dynamicGraph1.addDataPoint(75.44696f);
    dynamicGraph1.addDataPoint(88.17248f);
    dynamicGraph1.addDataPoint(96.65539f);
    dynamicGraph1.addDataPoint(98.80881f);
    dynamicGraph1.addDataPoint(93.89248f);
    dynamicGraph1.addDataPoint(82.70252f);
    dynamicGraph1.addDataPoint(67.39272f);
    dynamicGraph1.addDataPoint(50.97058f);
    dynamicGraph1.addDataPoint(36.59055f);
    dynamicGraph1.addDataPoint(26.81618f);
    dynamicGraph1.addDataPoint(23.0307f);
    dynamicGraph1.addDataPoint(25.13857f);
    dynamicGraph1.addDataPoint(31.62964f);
    dynamicGraph1.addDataPoint(39.98852f);
    dynamicGraph1.addDataPoint(47.34739f);
    dynamicGraph1.addDataPoint(51.22081f);
    dynamicGraph1.addDataPoint(50.14158f);
    dynamicGraph1.addDataPoint(44.0406f);
    dynamicGraph1.addDataPoint(34.27709f);
    dynamicGraph1.addDataPoint(23.31116f);
    dynamicGraph1.addDataPoint(14.09873f);
    dynamicGraph1.addDataPoint(9.35699f);
    dynamicGraph1.addDataPoint(10.88076f);
    dynamicGraph1.addDataPoint(19.07773f);
    dynamicGraph1.addDataPoint(32.8376f);
    dynamicGraph1.addDataPoint(49.76809f);
    dynamicGraph1.addDataPoint(66.74178f);
    dynamicGraph1.addDataPoint(80.62121f);
    dynamicGraph1.addDataPoint(88.98644f);
    dynamicGraph1.addDataPoint(90.68855f);
    dynamicGraph1.addDataPoint(86.09508f);
    dynamicGraph1.addDataPoint(76.9688f);
    dynamicGraph1.addDataPoint(66.01063f);
    dynamicGraph1.addDataPoint(56.17981f);
    dynamicGraph1.addDataPoint(49.95836f);
    dynamicGraph1.addDataPoint(48.74036f);
    stock.add(dynamicGraph1);

    textStock.setXY(20, 47);
    textStock.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStock.setLinespacing(0);
    textStock.setTypedText(touchgfx::TypedText(T___SINGLEUSE_A88N));
    stock.add(textStock);

    textStockValue.setXY(20, 85);
    textStockValue.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textStockValue.setLinespacing(0);
    textStockValue.setTypedText(touchgfx::TypedText(T___SINGLEUSE_WA0J));
    stock.add(textStockValue);

    swipeContainerWidget.add(stock);

    swipeContainerWidget.setSelectedPage(1);
    add(swipeContainerWidget);

    boxInfoBG.setPosition(0, 0, 480, 24);
    boxInfoBG.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    boxInfoBG.setAlpha(71);
    add(boxInfoBG);

    textBattery.setXY(435, 0);
    textBattery.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textBattery.setLinespacing(0);
    textBattery.setWildcard(touchgfx::TypedText(T___SINGLEUSE_OW5R).getText());
    textBattery.resizeToCurrentText();
    textBattery.setTypedText(touchgfx::TypedText(T___SINGLEUSE_6CI5));
    add(textBattery);

    textClockUpper.setXY(2, 0);
    textClockUpper.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textClockUpper.setLinespacing(0);
    touchgfx::Unicode::snprintf(textClockUpperBuffer1, TEXTCLOCKUPPERBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_O7C8).getText());
    textClockUpper.setWildcard1(textClockUpperBuffer1);
    touchgfx::Unicode::snprintf(textClockUpperBuffer2, TEXTCLOCKUPPERBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_6C3U).getText());
    textClockUpper.setWildcard2(textClockUpperBuffer2);
    textClockUpper.resizeToCurrentText();
    textClockUpper.setTypedText(touchgfx::TypedText(T___SINGLEUSE_70FQ));
    add(textClockUpper);

    textDayUpper.setXY(55, 0);
    textDayUpper.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textDayUpper.setLinespacing(0);
    Unicode::snprintf(textDayUpperBuffer, TEXTDAYUPPER_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_FUME).getText());
    textDayUpper.setWildcard(textDayUpperBuffer);
    textDayUpper.resizeToCurrentText();
    textDayUpper.setTypedText(touchgfx::TypedText(T___SINGLEUSE_3ZNK));
    add(textDayUpper);

    textAlarm.setXY(361, 0);
    textAlarm.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    textAlarm.setLinespacing(0);
    touchgfx::Unicode::snprintf(textAlarmBuffer1, TEXTALARMBUFFER1_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_ILR7).getText());
    textAlarm.setWildcard1(textAlarmBuffer1);
    touchgfx::Unicode::snprintf(textAlarmBuffer2, TEXTALARMBUFFER2_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_YTIP).getText());
    textAlarm.setWildcard2(textAlarmBuffer2);
    textAlarm.resizeToCurrentText();
    textAlarm.setTypedText(touchgfx::TypedText(T___SINGLEUSE_TJPS));
    add(textAlarm);

    imageAlarm.setXY(336, 2);
    imageAlarm.setBitmap(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_ALARM_ON_22_22_FFFFFF_SVG_ID));
    add(imageAlarm);

    modalWindowSetting.setBackground(touchgfx::BitmapId(BITMAP_ALTERNATE_THEME_IMAGES_CONTAINERS_MEDIUM_NARROW_OUTLINED_LIGHT_ID), 120, 1);
    modalWindowSetting.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    modalWindowSetting.setShadeAlpha(150);
    modalWindowSetting.hide();
    textAreaIP.setPosition(17, 187, 196, 23);
    textAreaIP.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaIP.setLinespacing(0);
    Unicode::snprintf(textAreaIPBuffer, TEXTAREAIP_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_0UUT).getText());
    textAreaIP.setWildcard(textAreaIPBuffer);
    textAreaIP.setTypedText(touchgfx::TypedText(T___SINGLEUSE_GWB9));
    modalWindowSetting.add(textAreaIP);

    textAreaWiFi.setPosition(17, 109, 196, 23);
    textAreaWiFi.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaWiFi.setLinespacing(0);
    Unicode::snprintf(textAreaWiFiBuffer, TEXTAREAWIFI_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_BSU9).getText());
    textAreaWiFi.setWildcard(textAreaWiFiBuffer);
    textAreaWiFi.setTypedText(touchgfx::TypedText(T___SINGLEUSE_XHNO));
    modalWindowSetting.add(textAreaWiFi);

    textArea1.setXY(17, 73);
    textArea1.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea1.setLinespacing(0);
    textArea1.setTypedText(touchgfx::TypedText(T___SINGLEUSE_4VYD));
    modalWindowSetting.add(textArea1);

    textArea2.setXY(17, 154);
    textArea2.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textArea2.setLinespacing(0);
    textArea2.setTypedText(touchgfx::TypedText(T___SINGLEUSE_B3UH));
    modalWindowSetting.add(textArea2);

    buttonClock.setXY(8, 11);
    buttonClock.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_SETTINGS_APPLICATIONS_55_55_6B6B6B_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_SETTINGS_APPLICATIONS_55_55_6B6B6B_SVG_ID));
    buttonClock.setAction(buttonCallback);
    modalWindowSetting.add(buttonClock);

    add(modalWindowSetting);

    modalWindowDebug.setBackground(touchgfx::BitmapId(BITMAP_ALTERNATE_THEME_IMAGES_CONTAINERS_MEDIUM_WIDE_OUTLINED_LIGHT_ID), 55, 1);
    modalWindowDebug.setShadeColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    modalWindowDebug.setShadeAlpha(150);
    modalWindowDebug.hide();
    textAreaPacket.setPosition(15, 19, 339, 230);
    textAreaPacket.setColor(touchgfx::Color::getColorFromRGB(0, 0, 0));
    textAreaPacket.setLinespacing(0);
    Unicode::snprintf(textAreaPacketBuffer, TEXTAREAPACKET_SIZE, "%s", touchgfx::TypedText(T___SINGLEUSE_E0MB).getText());
    textAreaPacket.setWildcard(textAreaPacketBuffer);
    textAreaPacket.setTypedText(touchgfx::TypedText(T___SINGLEUSE_74KH));
    modalWindowDebug.add(textAreaPacket);

    buttonDebugOut.setXY(2, 214);
    buttonDebugOut.setBitmaps(touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_BUG_REPORT_55_55_6B6B6B_SVG_ID), touchgfx::Bitmap(BITMAP_ICON_THEME_IMAGES_ACTION_BUG_REPORT_55_55_000000_SVG_ID));
    buttonDebugOut.setAction(buttonCallback);
    modalWindowDebug.add(buttonDebugOut);

    add(modalWindowDebug);
}

ClockViewBase::~ClockViewBase()
{
    touchgfx::CanvasWidgetRenderer::resetBuffer();
}

void ClockViewBase::setupScreen()
{
    hourScrollWheel.initialize();
    for (int i = 0; i < hourScrollWheelListItems.getNumberOfDrawables(); i++)
    {
        hourScrollWheelListItems[i].initialize();
    }
    for (int i = 0; i < hourScrollWheelSelectedListItems.getNumberOfDrawables(); i++)
    {
        hourScrollWheelSelectedListItems[i].initialize();
    }
    minuteScrollWheel.initialize();
    for (int i = 0; i < minuteScrollWheelListItems.getNumberOfDrawables(); i++)
    {
        minuteScrollWheelListItems[i].initialize();
    }
    for (int i = 0; i < minuteScrollWheelSelectedListItems.getNumberOfDrawables(); i++)
    {
        minuteScrollWheelSelectedListItems[i].initialize();
    }
    scrollList1.initialize();
}

void ClockViewBase::buttonCallbackHandler(const touchgfx::AbstractButton& src)
{
    if (&src == &buttonPlay)
    {
        //stopWatchPlay
        //When buttonPlay clicked call virtual function
        //Call buttonPlayClicked
        buttonPlayClicked();
    }
    if (&src == &buttonStop)
    {
        //stopWatchStop
        //When buttonStop clicked call virtual function
        //Call buttonStopClicked
        buttonStopClicked();
    }
    if (&src == &buttonReset)
    {
        //stopWatchReset
        //When buttonReset clicked call virtual function
        //Call buttonResetClicked
        buttonResetClicked();
    }
    if (&src == &buttonTimerMax)
    {
        //timerMax
        //When buttonTimerMax clicked call virtual function
        //Call buttonTimerMaxClicked
        buttonTimerMaxClicked();
    }
    if (&src == &buttonTimerMin)
    {
        //timerMin
        //When buttonTimerMin clicked call virtual function
        //Call bottonTimerMinClicked
        bottonTimerMinClicked();
    }
    if (&src == &buttonSetting)
    {
        //showSettingWindow
        //When buttonSetting clicked show modalWindowSetting
        //Show modalWindowSetting
        modalWindowSetting.setVisible(true);
        modalWindowSetting.invalidate();
    }
    if (&src == &buttonClock)
    {
        //hideSettingWindow
        //When buttonClock clicked hide modalWindowSetting
        //Hide modalWindowSetting
        modalWindowSetting.setVisible(false);
        modalWindowSetting.invalidate();
    }
    if (&src == &buttonDebugOut)
    {
        //hideDebugWindow
        //When buttonDebugOut clicked hide modalWindowDebug
        //Hide modalWindowDebug
        modalWindowDebug.setVisible(false);
        modalWindowDebug.invalidate();
    }
    if (&src == &buttonDebugIn)
    {
        //showDebugWindow
        //When buttonDebugIn clicked show modalWindowDebug
        //Show modalWindowDebug
        modalWindowDebug.setVisible(true);
        modalWindowDebug.invalidate();
    }
}

void ClockViewBase::updateItemCallbackHandler(touchgfx::DrawableListItemsInterface* items, int16_t containerIndex, int16_t itemIndex)
{
    if (items == &hourScrollWheelListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        alarmContainer* cc = (alarmContainer*)d;
        hourScrollWheelUpdateItem(*cc, itemIndex);
    }
    if (items == &hourScrollWheelSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        alarmCenterContainer* cc = (alarmCenterContainer*)d;
        hourScrollWheelUpdateCenterItem(*cc, itemIndex);
    }

    if (items == &minuteScrollWheelListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        alarmContainer* cc = (alarmContainer*)d;
        minuteScrollWheelUpdateItem(*cc, itemIndex);
    }
    if (items == &minuteScrollWheelSelectedListItems)
    {
        touchgfx::Drawable* d = items->getDrawable(containerIndex);
        alarmCenterContainer* cc = (alarmCenterContainer*)d;
        minuteScrollWheelUpdateCenterItem(*cc, itemIndex);
    }


}
