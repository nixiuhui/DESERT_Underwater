//
// Copyright (c) 2017 Regents of the SIGNET lab, University of Padova.
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
// are met:
// 1. Redistributions of source code must retain the above copyright
//    notice, this list of conditions and the following disclaimer.
// 2. Redistributions in binary form must reproduce the above copyright
//    notice, this list of conditions and the following disclaimer in the
//    documentation and/or other materials provided with the distribution.
// 3. Neither the name of the University of Padova (SIGNET lab) nor the
//    names of its contributors may be used to endorse or promote products
//    derived from this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
// TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
// PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
// EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
// PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
// OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
// WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
// ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

/**
 * @file   uwicrp-hdr-status.h
 * @author Giovanni Toso
 * @version 1.0.0
 *
 * \brief Provides the Status Messages header description.
 *
 */

#ifndef UWICRP_HDR_STATUS_H
#define UWICRP_HDR_STATUS_H

#include "uwicrp-common.h"

#include <module.h>

#define HDR_UWICRP_STATUS(p) (hdr_uwicrp_status::access(p))

extern packet_t PT_UWICRP_STATUS;

/**
 * <i>hdr_uwicrp_status</i> describes status packets used by <i>UWICRP</i>
 */
typedef struct hdr_uwicrp_status {

	nsaddr_t list_of_hops_
			[MAX_HOP_NUMBER]; /**< List of IPs saved in the header */
	int pointer_to_list_of_hops_; /**< Pointer used to keep track of the last
									 IPs processed */
	int list_of_hops_length_; /**< Current number of IPs stored in the header */
	double creation_time_; /**< Creation time of the packet */
	static int offset_; /**< Required by the PacketHeaderManager */

	/**
	 * Reference to the offset_ variable
	 */
	inline static int &
	offset()
	{
		return offset_;
	}

	inline static struct hdr_uwicrp_status *
	access(const Packet *p)
	{
		return (struct hdr_uwicrp_status *) p->access(offset_);
	}

	/**
	 * Pointer to the list_of_hops_ variable
	 */
	nsaddr_t *
	list_of_hops()
	{
		return list_of_hops_;
	}

	/**
	 * Reference to the pointer_to_list_of_hops_ variable
	 */
	int &
	pointer_to_list_of_hops()
	{
		return pointer_to_list_of_hops_;
	}

	/**
	 * Reference to the list_of_hops_length_ variable
	 */
	int &
	list_of_hops_length()
	{
		return list_of_hops_length_;
	}

	/**
	 * Reference to the creation_time_ variable
	 */
	double &
	creation_time()
	{
		return creation_time_;
	}

} hdr_uwicrp_status;

#endif // UWICRP_HDR_STATUS_H
