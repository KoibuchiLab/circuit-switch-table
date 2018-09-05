//
//  traffic-pattern-generator.h
//
//  Oct-02-1999     jouraku@am.ics.keio.ac.jp
//
//  $Log: mkpkt.h,v $
//  Revision 1.2  2003/03/29 06:22:12  jouraku
//
//  1. $B6a@\8r?.$N%H%i%U%#%C%/%Q%?!<%s(B 'only_neighbor($B2>(B)'$B$rDI2C(B
//      $B$3$l$O!"(B90%$B$N3NN($GNY@\%N!<%I$,L\E*%N!<%I$H$J$j!";D$j(B10%$B$G!"(B
//      $B%i%s%@%`$KA*Br$5$l$?%N!<%I$,L\E*%N!<%I$H$J$k!#(B
//
//  Revision 1.1.1.1  2001/02/10 13:37:03  jouraku
//
//  1. ������ INS(Interconnection Network Simulator)�⥸�塼��
//
//  Revision 1.3  2000/08/21 09:34:01  jouraku
//
//  1. ����Τ٤�������ޥ��� POW(x,y)���ɲ�
//
//  Revision 1.2  2000/08/21 07:02:49  jouraku
//
//  1. #include <assert.h>���ɲ�
//
//  Revision 1.1.1.1  2000/07/20 05:47:11  jouraku
//
//  torus(k-ary n-cube) simulator
//
//  Revision 1.4  1999/12/04 22:19:47  jouraku
//
//  �ؿ�bitreversal��,�ͥåȥ����������MAX_NODE�Ǥʤ�Npu*Npu
//  ��ɽ�����Ȥˤ��,�ͥåȥ�������������ꤵ����Զ�����
//
//  Revision 1.3  1999/12/04 03:08:32  jouraku
//
//  �ؿ�bitreversal�ˤ�������ǥ��ƥ��͡������Ρ����ֹ椬������
//  �Ρ����ֹ�ΥӥåȤ�ս�ˤ�����ΤˤʤäƤ��ʤ��ְ㤤����
//
//  Revision 1.2  1999/10/15 17:13:09  jouraku
//
//  ʸ�������ɤ�EUC���ѹ�
//

#ifndef _MKPKT_H_
#define _MKPKT_H_

#include <iostream>
#include <iomanip>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>
#include <assert.h>

#include <list>
#include <vector>

// HP(PA-RISC)
#if defined(__hpux__)
#define SYSTEM "HPUX"
#include <unistd.h>
#include <time.h>

// SunOS 5.x
#elif defined(__sun__) && defined(__svr4__)
#define SYSTEM "SunOS 5.x"
#include <time.h>

// SunOS 4.x
#elif defined(__sun__)
#define SYSTEM "SunOS 4.x"
#include <sys/types.h>
#include <sys/time.h>
extern "C"
{
	void	srand48(long);
	double	drand48();
	int	getopt(int, char**, char*);
	extern	char	*optarg;
	extern	int	optind, opterr;
}

// FreeBSD(x86)
#elif defined(__FreeBSD__)
#define SYSTEM "FreeBSD"
#include <time.h>
#include <unistd.h>  // for 3.x RELEASE

// Linux(x86)
#elif defined(__linux__)
#define SYSTEM "Linux"
#include <time.h>
#include <unistd.h>
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE	1
#define EXIT_SUCCESS	0
#endif

#ifndef VERSION
#define VERSION		__DATE__
#endif

#define TYPE_DATA 2

#define	POW(x,y)	int(pow((double)(x),(double)(y)))

#endif /* _MKPKT_H_ */




