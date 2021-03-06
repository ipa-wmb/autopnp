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
 * $Id$
 */

/**
 * \file
 *         Source file for function removeComponent in component capabilitiesView.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include "autoPnP/adv/capabilitiesView/include/removeComponentFunction.h"

#include "autoPnP/adv/capabilitiesView/include/removeComponentFunctionWrapper.h"
#include "autoPnP/adv/capabilitiesView/include/capabilitiesViewComponent.h"
#include "autoPnP/adv/capabilitiesView/include/capabilitiesViewComponentWrapper.h"
#include "autoPnP/adv/capabilitiesView/include/capabilitiesViewManifest.h"

#include "xme/core/logUtils.h"

#include "xme/hal/include/mem.h"

// PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_C_INCLUDES) ENABLED START
#include <stdbool.h>

#include "xme/hal/include/safeString.h" //TODO
// PROTECTED REGION END

/******************************************************************************/
/***   Definitions                                                          ***/
/******************************************************************************/

// PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_C_DEFINITIONS) ENABLED START
// PROTECTED REGION END

/******************************************************************************/
/***   Variables                                                            ***/
/******************************************************************************/

// PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_C_VARIABLES) ENABLED START
// PROTECTED REGION END

/******************************************************************************/
/***   Prototypes                                                           ***/
/******************************************************************************/

// PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_C_PROTOTYPES) ENABLED START
void autoPnP_adv_capabilitiesView_removeComponentFunction_childComponents(autoPnP_adv_capabilitiesView_capabilitiesViewComponent_config_t* const config, char* parent);
// PROTECTED REGION END

/******************************************************************************/
/***   Implementation                                                       ***/
/******************************************************************************/
xme_status_t
autoPnP_adv_capabilitiesView_removeComponentFunction_init
(
    autoPnP_adv_capabilitiesView_capabilitiesViewComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_INITIALIZE_C) ENABLED START
	XME_UNUSED_PARAMETER(componentConfig);

	return XME_STATUS_SUCCESS;
    // PROTECTED REGION END
}

void
autoPnP_adv_capabilitiesView_removeComponentFunction_step
(
    autoPnP_adv_capabilitiesView_capabilitiesViewComponent_config_t* const componentConfig
)
{
    xme_status_t status[1];
    
    AutoPnP_topic_remove_component_t portRemoveComponentData; // Required port.
    
    (void)xme_hal_mem_set(&portRemoveComponentData, 0u, sizeof(AutoPnP_topic_remove_component_t));
    
    status[0] = autoPnP_adv_capabilitiesView_capabilitiesViewComponentWrapper_readPortRemoveComponent(&portRemoveComponentData);
    
    {
        // PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_STEP_C) ENABLED START
		XME_UNUSED_PARAMETER(status);

		bool found = false;

		XME_HAL_TABLE_ITERATE_BEGIN
		(
			componentConfig->components,
			xme_hal_table_rowHandle_t, handle,
			autoPnP_adv_capabilitiesView_capabilitiesViewComponent_component_t, component
		);
		{
			if (!strcmp(portRemoveComponentData.name, component->component.name)) //TODO
			{
				found = true;

				component->status = COMPONENT_STATUS_REMOVED;
				component->timeHandle = xme_hal_time_getCurrentTime();
				autoPnP_adv_capabilitiesView_removeComponentFunction_childComponents(componentConfig, portRemoveComponentData.name);
				break;
			}
		}
		XME_HAL_TABLE_ITERATE_END();

		if (!found)
		{
			printf("Component '%s' doesn't exists!\n", portRemoveComponentData.name);
		}
        // PROTECTED REGION END
    }
    
    {
        // PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_STEP_2_C) ENABLED START
        // PROTECTED REGION END
    }
}

void
autoPnP_adv_capabilitiesView_removeComponentFunction_fini
(
    autoPnP_adv_capabilitiesView_capabilitiesViewComponent_config_t* const componentConfig
)
{
    // PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_TERMINATE_C) ENABLED START
    XME_UNUSED_PARAMETER(componentConfig);
    // PROTECTED REGION END
}

// PROTECTED REGION ID(AUTOPNP_ADV_CAPABILITIESVIEW_REMOVECOMPONENTFUNCTION_IMPLEMENTATION_C) ENABLED START
void autoPnP_adv_capabilitiesView_removeComponentFunction_childComponents(autoPnP_adv_capabilitiesView_capabilitiesViewComponent_config_t* const config, char* parent)
{
	bool deleted;

	do
	{
		deleted = false;

		XME_HAL_TABLE_ITERATE_BEGIN
		(
			config->components,
			xme_hal_table_rowHandle_t, handle,
			autoPnP_adv_capabilitiesView_capabilitiesViewComponent_component_t, component
		);
		{
			if (!strcmp(parent, component->component.parent)) //TODO
			{
				component->status = COMPONENT_STATUS_REMOVED;
				component->timeHandle = xme_hal_time_getCurrentTime();
				autoPnP_adv_capabilitiesView_removeComponentFunction_childComponents(config, component->component.name /*tmp*/);
				deleted = true;
				break;
			}
		}
		XME_HAL_TABLE_ITERATE_END();
	} while (deleted);
}
// PROTECTED REGION END
