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
 * $Id: triggerFunction.c 7805 2014-03-13 09:54:35Z geisinger $
 */

/**
 * \file
 *         Source file for function trigger in component logoutTrigger.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "sensorMonitor/adv/logoutTrigger/include/triggerFunction.h"

#include "sensorMonitor/adv/logoutTrigger/include/triggerFunctionWrapper.h"
#include "sensorMonitor/adv/logoutTrigger/include/logoutTriggerComponent.h"
#include "sensorMonitor/adv/logoutTrigger/include/logoutTriggerComponentWrapper.h"
#include "sensorMonitor/adv/logoutTrigger/include/logoutTriggerManifest.h"

#include "xme/core/logUtils.h"

// PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_C_INCLUDES) ENABLED START
#include "xme/core/plugAndPlay/include/plugAndPlayManager.h"
#include "xme/hal/include/mem.h"
// PROTECTED REGION END

/******************************************************************************/
/***   Definitions                                                          ***/
/******************************************************************************/

// PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_C_DEFINITIONS) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Variables                                                            ***/
/******************************************************************************/

// PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_C_VARIABLES) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/

// PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_C_PROTOTYPES) ENABLED START

// PROTECTED REGION END

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
sensorMonitor_adv_logoutTrigger_triggerFunction_init
(
    sensorMonitor_adv_logoutTrigger_logoutTriggerComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_INITIALIZE_C) ENABLED START
    
    // TODO: Auto-generated stub
    
    XME_UNUSED_PARAMETER(componentConfig);
    
    return XME_STATUS_SUCCESS;
    
    // PROTECTED REGION END
}

void
sensorMonitor_adv_logoutTrigger_triggerFunction_step
(
    sensorMonitor_adv_logoutTrigger_logoutTriggerComponent_config_t* const componentConfig
)
{
    
    {
        // PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_STEP_C) ENABLED START
        //counter determines the number of iteration when loggedOutNode will be send a message to log out from the ecosystem
        static int counter = 70;
        char loggedOutNode[20] = "lonelyNode";

        XME_UNUSED_PARAMETER(componentConfig);

        if (1 == counter)
        {
            xme_core_directory_nodeRegistryController_nodeIDIterator_t nodeIDIterator;
            char nodeNameBuffer[20];
            xme_core_node_nodeId_t nodeID = XME_CORE_NODE_INVALID_NODE_ID;
            xme_core_directory_nodeRegistryController_initNodeIDIterator(&nodeIDIterator);
            while (xme_core_directory_nodeRegistryController_hasNextNodeID(&nodeIDIterator))
            {
                nodeID = xme_core_directory_nodeRegistryController_nextNodeID(&nodeIDIterator);
                xme_core_directory_nodeRegistryController_getNodeName(nodeID, nodeNameBuffer, sizeof(nodeNameBuffer));
                if (0 == xme_hal_mem_compare(loggedOutNode, nodeNameBuffer, strlen(loggedOutNode)))
                {
                    break;
                }
                nodeID = XME_CORE_NODE_INVALID_NODE_ID;
            }
            xme_core_directory_nodeRegistryController_finiNodeIDIterator(&nodeIDIterator);

            if (XME_CORE_NODE_INVALID_NODE_ID != nodeID)
            {
                XME_CHECK_MSG
                (
                    XME_STATUS_SUCCESS == xme_core_pnp_pnpManager_unannounceNode(nodeID), 
                    XME_CHECK_RVAL_VOID, 
                    XME_LOG_WARNING, 
                    "[logoutTrigger/tiggerFunction] Cannot process the logout request.\n"
                );
            }
        }
        if (0 != counter)
        {
            counter--;
        }
        
        // PROTECTED REGION END
    }
    
    {
        // PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_STEP_2_C) ENABLED START
    
        // TODO: Auto-generated stub
        //       Check return values of writePort calls here
    
        // PROTECTED REGION END
    }
}

void
sensorMonitor_adv_logoutTrigger_triggerFunction_fini
(
    sensorMonitor_adv_logoutTrigger_logoutTriggerComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_TERMINATE_C) ENABLED START
    
    // Nothing to do
    
    XME_UNUSED_PARAMETER(componentConfig);
    
    // PROTECTED REGION END
}

// PROTECTED REGION ID(SENSORMONITOR_ADV_LOGOUTTRIGGER_TRIGGERFUNCTION_IMPLEMENTATION_C) ENABLED START

// PROTECTED REGION END
