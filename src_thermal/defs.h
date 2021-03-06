/*! \file defs.h
  	\brief some defines
 */

#ifndef DEFS_H_
#define DEFS_H_

#include <cmath>

//#define myDEBUG

#ifdef myDEBUG
// for debug

#define trace printf("<<<<<<<<<< File: %s, Line: %d\n", __FILE__, __LINE__)

#define perr printf("<<<<<<<<<< ERROR: File: %s, Line: %d\n", __FILE__, __LINE__)

#define prval(x) std::cout<<#x<<" = "<<x<<std::endl

#else
// for release

#define trace 

#define perr printf("<<<<<<<<<< ERROR: File: %s, Line: %d\n", __FILE__, __LINE__)

#define prval(x) 

#endif


#define TIME(statement, acc_time) { timeval st, et; \
	gettimeofday(&st, NULL); \
	(statement); \
	gettimeofday(&et, NULL); \
	acc_time += difftime(st, et); }

const float eps = 1e-9;

#define Equal(a, b) (abs( (a)-(b) ) < eps ? true : false)


//#define HandleError 

#define HandleError { cudaError_t cudaError; \
	cudaError = cudaGetLastError(); \
	if(cudaError != cudaSuccess){ \
		printf("Error: %s\n", cudaGetErrorString(cudaError)); \
		exit(-1); } }


// zky
//! return the difference between \p st and \p et
/*!
  \param st start time
  \param et end time
  \return the time span in ms
 */
extern float difftime(timeval &st, timeval &et);



#endif
