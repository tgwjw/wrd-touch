/* mbed
 * Copyright (c) 2006-2015 ARM Limited
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __ANALOG_SLIDER_H__
#define __ANALOG_SLIDER_H__

#include "mbed-drivers/mbed.h"

#if YOTTA_CFG_HARDWARE_WRD_TOUCH_PRESENT
#include "wrd-touch/AnalogSliderImplementation.h"
#else
#include "wrd-touch/AnalogSliderNotPresent.h"
#endif

using namespace mbed::util;

class AnalogSlider
{
public:
    AnalogSlider(const uint32_t* channelMap, uint32_t channelsInUse)
        :   slider(channelMap, channelsInUse)
    {}

    /*  Register callback functions
    */
    void setCallOnPress(FunctionPointer callback)
    {
        slider.setCallOnPress(callback);
    }

    template <typename T>
    void setCallOnPress(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        slider.setCallOnPress(fp);
    }

    void setCallOnChange(FunctionPointer callback)
    {
        slider.setCallOnChange(callback);
    }

    template <typename T>
    void setCallOnChange(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        slider.setCallOnChange(fp);
    }

    void setCallOnRelease(FunctionPointer callback)
    {
        slider.setCallOnRelease(callback);
    }

    template <typename T>
    void setCallOnRelease(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        slider.setCallOnRelease(fp);
    }

    void calibrate(FunctionPointer callback)
    {
        slider.calibrate(callback);
    }

    template <typename T>
    void calibrate(T* object, void (T::*member)(void))
    {
        FunctionPointer fp(object, member);
        slider.calibrate(fp);
    }

    void cancelCalibration(void)
    {
        slider.cancelCalibration();
    }

    uint32_t getLocation(void) const
    {
        return slider.getLocation();
    }

    int32_t getSpeed(void) const
    {
        return slider.getSpeed();
    }

    int32_t getAcceleration(void) const
    {
        return slider.getAcceleration();
    }

    bool isPressed(void) const
    {
        return slider.isPressed();
    }

    uint32_t getTimestamp(void) const
    {
        return slider.getTimestamp();
    }

    void setIdleFrequency(uint32_t freqHz)
    {
        slider.setIdleFrequency(freqHz);
    }

    void setActiveFrequency(uint32_t freqHz)
    {
        slider.setActiveFrequency(freqHz);
    }

    void pause(void)
    {
        slider.pause();
    }

    void resume(void)
    {
        slider.resume();
    }

private:
#if YOTTA_CFG_HARDWARE_WRD_TOUCH_PRESENT
    AnalogSliderImplementation slider;
#else
    AnalogSliderNotPresent slider;
#endif
};

#endif // __ANALOG_SLIDER_H__
