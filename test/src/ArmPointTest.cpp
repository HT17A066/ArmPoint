// -*- C++ -*-
/*!
 * @file  ArmPointTest.cpp
 * @brief ThisRTC to ArmRTC
 * @date $Date$
 *
 * $Id$
 */

#include "ArmPointTest.h"

// Module specification
// <rtc-template block="module_spec">
static const char* armpoint_spec[] =
  {
    "implementation_id", "ArmPointTest",
    "type_name",         "ArmPointTest",
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
ArmPointTest::ArmPointTest(RTC::Manager* manager)
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
ArmPointTest::~ArmPointTest()
{
}



RTC::ReturnCode_t ArmPointTest::onInitialize()
{
  // Registration: InPort/OutPort/Service
  // <rtc-template block="registration">
  // Set InPort buffers
  addInPort("arm", m_armIn);
  
  // Set OutPort buffer
  addOutPort("armStatus", m_armStatusOut);
  addOutPort("point", m_pointOut);
  
  // Set service provider to Ports
  
  // Set service consumers to Ports
  
  // Set CORBA Service Ports
  
  // </rtc-template>

  // <rtc-template block="bind_config">
  // </rtc-template>
  
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPointTest::onFinalize()
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onStartup(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onShutdown(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/


RTC::ReturnCode_t ArmPointTest::onActivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPointTest::onDeactivated(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}


RTC::ReturnCode_t ArmPointTest::onExecute(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}

/*
RTC::ReturnCode_t ArmPointTest::onAborting(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onError(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onReset(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onStateUpdate(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/

/*
RTC::ReturnCode_t ArmPointTest::onRateChanged(RTC::UniqueId ec_id)
{
  return RTC::RTC_OK;
}
*/



extern "C"
{
 
  void ArmPointTestInit(RTC::Manager* manager)
  {
    coil::Properties profile(armpoint_spec);
    manager->registerFactory(profile,
                             RTC::Create<ArmPointTest>,
                             RTC::Delete<ArmPointTest>);
  }
  
};


