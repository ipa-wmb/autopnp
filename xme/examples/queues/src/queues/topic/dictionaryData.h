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
 * $Id: dictionaryData.h 7836 2014-03-14 12:20:24Z wiesmueller $
 */

/**
 * \file
 *         Topic registry extension.
 *         Project specific topic data structures are defined here.
 *
 * \author
 *         This file has been generated by the CHROMOSOME Modeling Tool (XMT)
 *         (fortiss GmbH).
 */

#ifndef QUEUES_DICTIONARY_TOPICDATA_H
#define QUEUES_DICTIONARY_TOPICDATA_H

/******************************************************************************/
/***   Includes                                                             ***/
/******************************************************************************/
#include <stdint.h>

/******************************************************************************/
/***   Type definitions                                                     ***/
/******************************************************************************/
/**
 * \typedef queues_attribute_sender_t
 *
 * \brief Data type for attribute 'sender' (identifier: QUEUES_ATTRIBUTE_SENDER).
 */
typedef uint8_t queues_attribute_sender_t;

/**
 * \typedef queues_topic_data_t
 *
 * \brief Data type for topic 'data' (identifier: QUEUES_TOPIC_DATA).
 */
#pragma pack(push, 1)
typedef struct
{
    uint32_t value;
} queues_topic_data_t;
#pragma pack(pop)
#endif // #ifndef QUEUES_DICTIONARY_TOPICDATA_H
