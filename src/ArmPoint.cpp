// -*- C++ -*-
/*!
 * @file  ArmPoint.cpp
 * @brief ThisRTC to ArmRTC
 * @date $Date$
 *
 * $Id$
 */

#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include "ArmPoint.h"

using namespace std;

const int NUM_ACTUATOR = 5;

// Module specification
// <rtc-template block="module_spec">
static const char* armpoint_spec[] =
  {
    "implementation_id", "ArmPoint",
    "type_name",         "ArmPoint",
    "description",       "ThisRTC to ArmRTC",
    "version",           "1.0.0",
    "vendor",            "MasutaniLab",
    "category",          "ArmController",
    "activity_type",     "PERIODIC",
    "kind",              "DataFlowComponent",
    "max_instance",      "1",
    "language",          "C++",
    "lang_type",         "compile",
    ""
  };
// </rtc-template>

/*!
 * @brief constructor
 * @param manager Maneger Object
 */
ArmPoint::ArmPoint(RTC::Manager* manager)
    // <rtc-template block="initializer">
  : RTC::DataFlowComponentBase(manager),
    m_armStatusIn("armStatus", m_armStatus),
    m_pointIn("point", m_point),
    m_armOut("arm", m_arm)

    // </rtc-template>
{
}

/*!
 * @brief destructor
 */
ArmPoint::~ArmPoint()
{
}



RTC::ReturnCode_t ArmPoint::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("armStatus", m_armStatusIn);
  addInPort("point", m_pointIn);
  
  // Set OutPort buffer
  addOutPort("arm", m_armOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPoint::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ArmPoint::onActivated(RTC::UniqueId ec_id)
{
  m_arm.data.length(NUM_ACTUATOR + 1);
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPoint::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPoint::onExecute(RTC::UniqueId ec_id)
{
  if (m_pointIn.isNew()) {
    m_pointIn.read();
    double &pointx = m_point.data.x;
    double &pointy = m_point.data.y;
    double &pointz = m_point.data.z;
      //角度計算
    double radx, radz;
      //1軸目計算
    radx = atan2(pointy, pointx);
    //3軸目計算
    radz = atan2(pointz, pointx);

    //確認
    cout << "(pointx, pointy, pointz)" << endl;
    cout << "(" << pointx << "," << pointy << "," << pointz << ")" << endl;
    cout << "RadianX:" << radx << endl;
    cout << "RadianZ:" << radz << endl;

    //関節指令
    m_arm.data[0] = radx;
    m_arm.data[1] = 1.57;//???
    m_arm.data[2] = radz;
    m_arm.data[3] = 0;
    m_arm.data[4] = 0.1;
    m_arm.data[5] = 4;
    m_armOut.write();
    return RTC::RTC_OK;
  }
}

/*
RTC::ReturnCode_t ArmPoint::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPoint::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ArmPointInit(RTC::Manager* manager)
  {
    coil::Properties profile(armpoint_spec);
    manager->registerFactory(profile,
                             RTC::Create<ArmPoint>,
                             RTC::Delete<ArmPoint>);
  }
  
};


