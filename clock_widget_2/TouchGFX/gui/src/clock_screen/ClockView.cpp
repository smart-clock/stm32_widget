#include <gui/clock_screen/ClockView.hpp>

ClockView::ClockView() :
    gaugeClickCallback(this, &ClockView::gaugeClickHandler)
{
    this->timerWidgetDrag = false;
    this->timerMinute = 0;
    this->timerOfCurAng = 0;
    this->timerOfPreAng = 0;
    this->timerMax = false;
    this->timerMin = false;
    this->timerStart = false;
    this->timerCounter = 0;

    this->alarmHour = 0;
    this->alarmMinute = 0;

    this->homeTimeCounter = 0;
    this->secondHome = 0;

    this->isAlarmOn = true;
    this->isAlarmAm = true;
    this->alarmActive = false;
    this->alarmCleared = false;

    this->background = 0;
    this->battery = 0;

    this->station = 0;
    this->busPredictTime1 = 0;
    this->busPredictTime2 = 0;
}

void ClockView::setupScreen()
{
    ClockViewBase::setupScreen();

    stopWatchHours = digitalClock.getCurrentHour();
    stopWatchMinutes = digitalClock.getCurrentMinute();
    stopWatchSeconds = digitalClock.getCurrentSecond();

    gaugeTimer.setClickAction(gaugeClickCallback);
    graphStock.clear();
}

void ClockView::tearDownScreen()
{
    ClockViewBase::tearDownScreen();
}

void ClockView::handleTickEvent()
{
    if(isStopWatchPlay)
    {
        tickCounter++;
        if(tickCounter % 60 == 0)
        {
            if(++stopWatchSeconds >= 60)
            {
                stopWatchSeconds = 0;
                if(++stopWatchMinutes >= 60)
                {
                    stopWatchMinutes = 0;
                    if(++stopWatchHours >= 24)
                    {
                        stopWatchHours = 0;
                    }
                }
            }
        }
    }

    if(timerStart)
    {
        timerCounter++;
        if(timerCounter % 60 == 0)
        {
            if(timerMinute > 0 && timerSecond == 0)
            {
                timerMinute--;
                timerSecond = 59;
            }
            else if(timerMinute == 0)
            {
                timerStart = false;
            }
            else
            {
                timerSecond--;
            }
        }
    }

    if(isTimeUpdated)
    {
    	homeTimeCounter++;
        if(homeTimeCounter % 60 == 0)
        {
            if(++secondHome >= 60)
            {
            	secondHome = 0;
                if(++minuteHome >= 60)
                {
                	minuteHome = 0;
                    if(++hourHome >= 24)
                    {
                    	hourHome = 0;
                    }
                }
            }
        }
    }

    if(isAlarmOn && isTimeUpdated && !alarmCleared)
    {
    	if(isAlarmAm)
    	{
			if(hourHome == alarmHour)
				if(minuteHome == alarmMinute)
					this->alarmActive = true;
    	}
    	else // PM
    	{
			if(hourHome == (alarmHour + 12))
				if(minuteHome == alarmMinute)
					this->alarmActive = true;
    	}
    }

    if(this->alarmActive) presenter->clockToggleBuzzer();

    // hourCurrent = presenter->getHour();
    // minuteCurrent = presenter->getMinute();

    // Update the clock
    digitalClock.setTime24Hour(stopWatchHours, stopWatchMinutes, stopWatchSeconds);

    // Update timer
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
    textTimer.invalidate();
    Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%02d", timerSecond);
    textTimer.invalidate();
    gaugeTimer.setValue(timerMinute*6);

    // Home Hour
    Unicode::snprintf(textHomeClockBuffer1, TEXTHOMECLOCKBUFFER1_SIZE, "%02d", hourHome);
    textHomeClock.invalidate();

    // Home Minute
    Unicode::snprintf(textHomeClockBuffer2, TEXTHOMECLOCKBUFFER2_SIZE, "%02d", minuteHome);
    textHomeClock.invalidate();

    // Home Second
    Unicode::snprintf(textHomeSecBuffer, TEXTHOMESEC_SIZE, "%02d", secondHome);
    textHomeSec.invalidate();

    // textClockUpper Hour
    Unicode::snprintf(textClockUpperBuffer1, TEXTCLOCKUPPERBUFFER1_SIZE, "%02d", hourHome);
    textClockUpper.invalidate();

    // textClockUpper Minute
    Unicode::snprintf(textClockUpperBuffer2, TEXTCLOCKUPPERBUFFER2_SIZE, "%02d", minuteHome);
    textClockUpper.invalidate();
}

void ClockView::buttonPlayClicked()
{
    isStopWatchPlay = true;
}

void ClockView::buttonStopClicked()
{
    isStopWatchPlay = false;
}

void ClockView::buttonResetClicked()
{
    isStopWatchPlay = false;
    stopWatchHours = 0;
    stopWatchMinutes = 0;
    stopWatchSeconds = 0;
}

void ClockView::buttonTimerMaxClicked()
{
    gaugeTimer.setValue(360);
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 60);
    textTimer.invalidate();
    timerMinute = 60;
    timerSecond = 0;
}

void ClockView::bottonTimerMinClicked()
{
    gaugeTimer.setValue(0);
    Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", 0);
    textTimer.invalidate();
    timerMinute = 0;
    timerSecond = 0;
}

void ClockView::toggleButtonOn()
{
	if(toggleButtonON.getState()) // Alarm OFF
	{
		imageAlarmOn.setVisible(false);
		imageAlarmOff.setVisible(true);

		this->isAlarmOn = false;
	}
	else // Alarm ON
	{
		imageAlarmOn.setVisible(true);
		imageAlarmOff.setVisible(false);

		this->isAlarmOn = true;
	}

	imageAlarmOn.invalidate();
	imageAlarmOff.invalidate();
}
void ClockView::toggleButtonAm()
{
	if(toggleButtonAM.getState()) // Alarm PM
	{
		Unicode::snprintf(textAlarmAMPMBuffer, TEXTALARMAMPM_SIZE, "PM", 0);
		textAlarmAMPM.invalidate();

		this->isAlarmAm = false;
	}
	else // Alarm AM
	{
		Unicode::snprintf(textAlarmAMPMBuffer, TEXTALARMAMPM_SIZE, "AM", 0);
		textAlarmAMPM.invalidate();

		this->isAlarmAm = true;
	}
}

void ClockView::gaugeClickHandler(const Gauge& g, const ClickEvent& e)
{
    if(&g == &gaugeTimer)
    {
        if(e.getType() == ClickEvent::PRESSED)
        {
            timerWidgetDrag = true;
        }
        else if(e.getType() == ClickEvent::RELEASED)
        {
            timerWidgetDrag = false;
            timerMax = false;
            timerMin = false;
            timerStart = true;
        }
    }
}

//handleDragEvent 오버라이딩 시에 Scroll Wheel 위젯 애니매이션 자연스럽지 않음 #20
void ClockView::handleDragEvent(const DragEvent& Event)
{
    if(timerWidgetDrag)
    {
        int16_t timerDragX = Event.getNewX();
        int16_t timerDragY = Event.getNewY();

        timerOfCurAng = CWRUtil::angle<int>(timerDragX - 240, timerDragY - 124);

        if(timerOfPreAng > 340 && timerOfCurAng < 20)
        {
            timerMax = true;
        }
        else if(timerOfPreAng < 20 && timerOfCurAng > 340)
        {
            timerMin = true;
        }

        if(timerMax)
        {
            gaugeTimer.setValue(360);
            timerMinute = 60;
        }
        else if(timerMin)
        {
            gaugeTimer.setValue(0);
            timerMinute = 0;
        }
        else
        {
            gaugeTimer.setValue(timerOfCurAng);
            timerMinute = timerOfCurAng/6;
        }

        Unicode::snprintf(textTimerBuffer1, TEXTTIMERBUFFER1_SIZE, "%02d", timerMinute);
        textTimer.invalidate();

        timerSecond = 0;
        Unicode::snprintf(textTimerBuffer2, TEXTTIMERBUFFER2_SIZE, "%02d", timerSecond);
        textTimer.invalidate();

        timerOfPreAng = timerOfCurAng;
    }
}

void ClockView::hourScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
}

void ClockView::hourScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
    alarmHour = itemIndex - 1;

    // 상단 알람 표시 업데이트
    Unicode::snprintf(textAlarmBuffer1, TEXTALARMBUFFER1_SIZE, "%02d", alarmHour);
    textAlarm.invalidate();
}

void ClockView::minuteScrollWheelUpdateItem(alarmContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
}

void ClockView::minuteScrollWheelUpdateCenterItem(alarmCenterContainer& item, int16_t itemIndex)
{
    item.setText(itemIndex);
    alarmMinute = itemIndex - 1;

    // 상단 알람 표시 업데이트
    Unicode::snprintf(textAlarmBuffer2, TEXTALARMBUFFER2_SIZE, "%02d", alarmMinute);
    textAlarm.invalidate();
}

void ClockView::uart_Data(char *data)
{
	// Show esp2stmPacket at modalWindowDebug
	textAreaPacket.setWideTextAction(touchgfx::WIDE_TEXT_WORDWRAP);
	Unicode::strncpy(textAreaPacketBuffer, data, TEXTAREAPACKET_SIZE);
	textAreaPacket.invalidate();

    esp2stmPacket.assign(data, data + 256);

    string temp = "";
    int index = 0;
    int eofIndex = 0;
    if(esp2stmPacket[1] == 'W' && esp2stmPacket[2] == 'F')
    {
		for(index = 4; index < 257; index++)
		{
			if(data[index] != '\r') wifiID[index - 4] = data[index];
			else if(data[index] == '\r') break;
		}
		wifiID[index] = '\0';
		Unicode::strncpy(textAreaWiFiBuffer, wifiID, TEXTAREAWIFI_SIZE);
		textAreaWiFi.invalidate();
    }
    else if(esp2stmPacket[1] == 'I' && esp2stmPacket[2] == 'P')
    {
		for(index = 4; index < 257; index++)
		{
			if(data[index] != '\r') ipAddress[index - 4] = data[index];
			else if(data[index] == '\r') break;
		}
		ipAddress[index] = '\0';
		Unicode::strncpy(textAreaIPBuffer, ipAddress, TEXTAREAIP_SIZE);
		textAreaWiFi.invalidate();
    }
    else if(esp2stmPacket[1] == 'B' && esp2stmPacket[2] == 'T')
    {
    	temp = esp2stmPacket.substr(4, 2);
    	battery = stoi(temp);

		Unicode::snprintf(textBatteryBuffer, TEXTBATTERY_SIZE, "%02d", battery);
		textBattery.invalidate();
    }
    else if(esp2stmPacket[1] == 'D' && esp2stmPacket[2] == 'A')
    {
        temp = esp2stmPacket.substr(9, 2);
        monthHome = stoi(temp);
        
        temp = esp2stmPacket.substr(12, 2);
        dateHome = stoi(temp);

        // temp = esp2stmPacket.substr(15, 17) + "\0";
        dayHome[0] = data[15];
        dayHome[1] = data[16];
        dayHome[2] = data[17];
        dayHome[3] = '\0';

        temp = esp2stmPacket.substr(19, 2);
        hourHome = stoi(temp);

        temp = esp2stmPacket.substr(22, 2);
        minuteHome = stoi(temp);

        temp = esp2stmPacket.substr(25, 2);
        secondHome = stoi(temp);

        // Home Hour 
        Unicode::snprintf(textHomeClockBuffer1, TEXTHOMECLOCKBUFFER1_SIZE, "%02d", hourHome);
        textHomeClock.invalidate();

        // Home Minute
        Unicode::snprintf(textHomeClockBuffer2, TEXTHOMECLOCKBUFFER2_SIZE, "%02d", minuteHome);
        textHomeClock.invalidate();

        // Home Second
        Unicode::snprintf(textHomeSecBuffer, TEXTHOMESEC_SIZE, "%02d", secondHome);
        textHomeSec.invalidate();

        // Home Month
        Unicode::snprintf(textHomeDateBuffer1, TEXTHOMEDATEBUFFER1_SIZE, "%02d", monthHome);
        textHomeDate.invalidate();

        // Home Date
        Unicode::snprintf(textHomeDateBuffer2, TEXTHOMEDATEBUFFER2_SIZE, "%02d", dateHome);
        textHomeDate.invalidate();

        // Home Day
        Unicode::strncpy(textHomeDayBuffer, dayHome, TEXTHOMEDAY_SIZE);
        textHomeDay.invalidate();

        // textClockUpper Hour 
        Unicode::snprintf(textClockUpperBuffer1, TEXTCLOCKUPPERBUFFER1_SIZE, "%02d", hourHome);
        textClockUpper.invalidate();

        // textClockUpper Minute
        Unicode::snprintf(textClockUpperBuffer2, TEXTCLOCKUPPERBUFFER2_SIZE, "%02d", minuteHome);
        textClockUpper.invalidate();

        // textDayUpper
        Unicode::strncpy(textDayUpperBuffer, dayHome, TEXTDAYUPPER_SIZE);
        textDayUpper.invalidate();

        isTimeUpdated = true;
    }
    else if(esp2stmPacket[1] == 'W' && esp2stmPacket[2] == 'T')
    {
    	// City
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(4, eofIndex - 4);
    	strncpy(weatherRegion, temp.c_str(), TEXTREGION_SIZE);

    	// Weather
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	strncpy(weather, temp.c_str(), TEXTWEATHER_SIZE);

    	// Temp
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find('\r');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	weatherTemp = stoi(temp);

    	// City Text
		Unicode::strncpy(textRegionBuffer, weatherRegion, TEXTREGION_SIZE);
    	textRegion.invalidate();

		// Weather Text
		Unicode::strncpy(textWeatherBuffer, weather, TEXTWEATHER_SIZE);
		textWeather.invalidate();

		// Temp Text
        Unicode::snprintf(textTempBuffer, TEXTTEMP_SIZE, "%02d", weatherTemp);
        textTemp.invalidate();

        // Weather Image
        if(strcmp(weather, "Snow") == 0)
        {
        	imageSnow.setVisible(true); // This
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(false);
        	imageClear.setVisible(false);
        	imageCloud.setVisible(false);
        	imageFog.setVisible(false);
        }
        else if(strcmp(weather, "Rain") == 0)
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(true); // This
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(false);
        	imageClear.setVisible(false);
        	imageCloud.setVisible(false);
        	imageFog.setVisible(false);
        }
        else if(strcmp(weather, "Drizzel") == 0)
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(true); // This
        	imageThunder.setVisible(false);
        	imageClear.setVisible(false);
        	imageCloud.setVisible(false);
        	imageFog.setVisible(false);
        }
        else if(strcmp(weather, "Thunderstorm") == 0)
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(true); // This
        	imageClear.setVisible(false);
        	imageCloud.setVisible(false);
        	imageFog.setVisible(false);
        }
        else if(strcmp(weather, "Clear") == 0)
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(false);
        	imageClear.setVisible(true); // This
        	imageCloud.setVisible(false);
        	imageFog.setVisible(false);
        }
        else if(strcmp(weather, "Clouds") == 0)
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(false);
        	imageClear.setVisible(false);
        	imageCloud.setVisible(true); // This
        	imageFog.setVisible(false);
        }
        else
        {
        	imageSnow.setVisible(false);
        	imageRain.setVisible(false);
        	imageDrizzel.setVisible(false);
        	imageThunder.setVisible(false);
        	imageClear.setVisible(false);
        	imageCloud.setVisible(false);
        	imageFog.setVisible(true); // This
        }

        imageSnow.invalidate();
        imageRain.invalidate();
        imageDrizzel.invalidate();
        imageThunder.invalidate();
        imageClear.invalidate();
        imageCloud.invalidate();
        imageFog.invalidate();
    }
    else if(esp2stmPacket[1] == 'B' && esp2stmPacket[2] == 'S')
    {
    	// Bus Name
    	esp2stmPacket.erase(0, 4);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	strncpy(busName, temp.c_str(), 10);

    	// Station
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	station = stoi(temp);

    	// Predict Time1
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	busPredictTime1 = stoi(temp);

    	// Predict Time2
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	busPredictTime2 = stoi(temp);

    	// Bus Name
		Unicode::strncpy(busRouteBuffer, busName, BUSROUTE_SIZE);
		busRoute.invalidate();

    	// Station
        Unicode::snprintf(busStationBuffer, BUSSTATION_SIZE, "%02d", station);
        busStation.invalidate();

        // Predict Time1
        Unicode::snprintf(busTime1Buffer, BUSTIME1_SIZE, "%02d", busPredictTime1);
        busTime1.invalidate();

        // Predict Time2
        Unicode::snprintf(busTime2Buffer, BUSTIME2_SIZE, "%02d", busPredictTime2);
        busTime2.invalidate();
    }
    else if(esp2stmPacket[1] == 'S' && esp2stmPacket[2] == 'C')
    {
    	// Stock Name
    	esp2stmPacket.erase(0, 4);
    	eofIndex = esp2stmPacket.find(',');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	strncpy(stockName, temp.c_str(), TEXTREGION_SIZE);

    	// Stock Value
    	esp2stmPacket.erase(0, eofIndex + 1);
    	eofIndex = esp2stmPacket.find('\r');
    	temp = esp2stmPacket.substr(0, eofIndex);
    	strncpy(stockValue, temp.c_str(), TEXTREGION_SIZE);

    	// Stock Name
		Unicode::strncpy(textStockBuffer, stockName, TEXTSTOCKVALUE_SIZE);
		textStock.invalidate();

    	// Stock Value
		Unicode::strncpy(textStockValueBuffer, stockValue, TEXTSTOCKVALUE_SIZE);
		textStockValue.invalidate();

    }
    else if(esp2stmPacket[1] == 'S' && esp2stmPacket[2] == 'M')
    {
    	esp2stmPacket.erase(0, 8); // only for IBM (3 charactor)

    	for(int i = 21; i > 0; i--)
    	{
    		eofIndex = esp2stmPacket.find(',');
    		temp = esp2stmPacket.substr(0, eofIndex);
    		esp2stmPacket.erase(0, eofIndex + 1);
    		graphStock.addDataPoint(i, stoi(temp));
    	}

		eofIndex = esp2stmPacket.find('\r');
		temp = esp2stmPacket.substr(0, eofIndex);
		graphStock.addDataPoint(0, stoi(temp));
    }
    else if(esp2stmPacket[1] == 'B' && esp2stmPacket[2] == 'U')
    {
    	if(alarmActive) // Clear alarm
		{
    		alarmActive = false;
    		alarmCleared = true;
    		presenter->clockToggleBuzzerOff();
		}
    	else // Change background
    	{
    		background++;
    		if(background > 2) background = 0;
    		switch(background)
    		{
    		    case 0 :
    		    	background1.setVisible(true);
    		    	background2.setVisible(false);
    		    	background3.setVisible(false);
    		        break;
    		    case 1 :
    		    	background1.setVisible(false);
    		    	background2.setVisible(true);
    		    	background3.setVisible(false);
    		        break;
    		    case 2 :
    		    	background1.setVisible(false);
    		    	background2.setVisible(false);
    		    	background3.setVisible(true);
    		    	break;
    		    default :
    		    	break;
    		}
    		background1.invalidate();
    		background2.invalidate();
    		background3.invalidate();
    	}
    }

}
