/***************************************************************************
 *   Copyright (C) 2014, IBM                                               *
 *                                                                         *
 *   Author:                                                        *
 *   Bharani C.V : bharanve@in.ibm.com                                    *
 *                                                                         *
 *   See 'COPYING' for License of this code.                               *
 ***************************************************************************/
#ifndef LSVPDPLATFORMCOLLECTOR_H_
#define LSVPDPLATFORMCOLLECTOR_H_

#include <string>
#include <errno.h>
#include <cstring>
#include <cerrno>
#include <sstream>
#include <fstream>

#define PLATFORM_FILE "/proc/cpuinfo"

using namespace std;

namespace lsvpd {

	enum platform { PF_NULL, PF_POWERVM_LPAR, PF_POWERKVM_HOST , PF_POWERKVM_PSERIES_GUEST, PF_ERROR };

	class PlatformCollector {
		public:
			/**
			 * Checks if it running on pSeries or PowerNV and
			 * stores platform type.
			 */
	                static platform platform_type;
		        static void get_platform();
			static string get_platform_name();

			/**
			 * Returns dynamic object pointing to RtasCollector if
			 * it is running on pSeries or OpalCollector if it is
			 * running on PowerNV.
			 */
		        static void get_collector(PlatformCollector **p);

			/**
			 * Interface to add platform VPD data defined in RtasCollector
		         * and OpalCollector.
			 */

			virtual int addPlatformVPD(const string& yl, char** data){};
	};
}

#endif /*LSVPDPLATFORMCOLLECTOR_H_*/
