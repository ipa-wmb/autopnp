/*
 * Copyright (c) 2011-2014, fortiss GmbH.
 * Licensed under the Apache License, Version 2.0.
 *
 * Use, modification and distribution are subject to the terms specified
 * in the accompanying license file LICENSE.txt located at the root directory
 * of this software distribution. A copy is available at
 * http://chromosome.fortiss.org/.
 *
 * This file is part of CHROMOSOME.
 *
 * $Id: detectorManifest.c 7769 2014-03-11 15:27:13Z geisinger $
 */

/**
 * \file
 *         Defines function for creation of component type manifest
 *         for 'detector'.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "detector/adv/detector/include/detectorManifest.h"

#include "../include/detectorComponentWrapper.h"
#include "detector/adv/detector/include/detectDevicesFunction.h"
#include "detector/adv/detector/include/detectDevicesFunctionWrapper.h"
#include "detector/adv/detector/include/detectorComponent.h"
#include "xme/core/log.h"
#include "xme/hal/include/time.h"

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
detector_adv_detector_manifest_createComponentTypeManifest
(
    xme_core_componentManifest_t* componentManifest
)
{
    XME_CHECK
    (
        NULL != componentManifest,
        XME_STATUS_INVALID_PARAMETER
    );

    (void)xme_hal_mem_set(componentManifest, 0U, sizeof(xme_core_componentManifest_t));

    componentManifest->componentType = (xme_core_componentType_t)4097;
    componentManifest->componentWrapperInit = detector_adv_detector_detectorComponentWrapper_init;
    componentManifest->componentWrapperReceivePort = NULL;
    componentManifest->componentWrapperFini = detector_adv_detector_detectorComponentWrapper_fini;
    componentManifest->componentInit = (xme_core_componentManifest_componentInit_t)detector_adv_detector_detectorComponent_init;
    (void)xme_hal_safeString_strncpy(componentManifest->name, "detector", sizeof(componentManifest->name));
    componentManifest->configStructSize = sizeof(detector_adv_detector_detectorComponent_config_t);

    {
        uint32_t functionArrayLength = sizeof(componentManifest->functionManifests) / sizeof(componentManifest->functionManifests[0]);

        // Function 'detectDevices'
        {
            if (0U >= functionArrayLength) // Check generated by tool (which does not know about the array size)
            {
                if (0U == functionArrayLength) // Only trigger warning once
                {
                    XME_LOG
                    (
                        XME_LOG_WARNING,
                        "%s:%d Component type 'detector' defines more functions (%d) than can be stored in the manifest data structure (%d).\n",
                        __FILE__,
                        __LINE__,
                       1,
                       functionArrayLength
                    );
                }
            }
            else
            {
                xme_core_functionManifest_t* functionManifest;
                
                functionManifest = &componentManifest->functionManifests[0];
                functionManifest->functionId = (xme_core_component_functionId_t)1;
                functionManifest->wcet = xme_hal_time_timeIntervalFromMilliseconds(5ull);
                functionManifest->alphaCurve.alphaCurve = 0;
                functionManifest->completion = true;
                functionManifest->requiredPortIndicesLength = 0;
                functionManifest->optionalPortIndicesLength = 0;
                functionManifest->functionInit = (xme_core_exec_initCallback_t)detector_adv_detector_detectDevicesFunction_init;
                functionManifest->functionFini = (xme_core_exec_finiCallback_t)detector_adv_detector_detectDevicesFunction_fini;
                functionManifest->functionWrapperExecute = detector_adv_detector_detectDevicesFunctionWrapper_execute;
            }
        }
    }

    return XME_STATUS_SUCCESS;
}