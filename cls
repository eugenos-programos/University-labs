[33mcommit e881b40e7545423ef82f51d2e525ccb0016bcd54[m[33m ([m[1;36mHEAD -> [m[1;32mmain[m[33m)[m
Author: z <elena.samchuk.73@mail.ru>
Date:   Sun Oct 18 20:57:24 2020 +0300

    1 version

[1mdiff --git a/6lab/Project1.bpf b/6lab/Project1.bpf[m
[1mnew file mode 100644[m
[1mindex 0000000..5da8824[m
[1m--- /dev/null[m
[1m+++ b/6lab/Project1.bpf[m
[36m@@ -0,0 +1,3 @@[m
[32m+[m[32mThis file is used by the project manager only and should be treated like the project file[m[41m[m
[32m+[m
[32m+[m[32mmain[m[41m [m
\ No newline at end of file[m
[1mdiff --git a/6lab/Project1.bpr b/6lab/Project1.bpr[m
[1mnew file mode 100644[m
[1mindex 0000000..7a7c9fa[m
[1m--- /dev/null[m
[1m+++ b/6lab/Project1.bpr[m
[36m@@ -0,0 +1,116 @@[m
[32m+[m[32m<?xml version='1.0' encoding='utf-8' ?>[m
[32m+[m[32m<!-- C++Builder XML Project -->[m
[32m+[m[32m<PROJECT>[m
[32m+[m[32m  <MACROS>[m
[32m+[m[32m    <VERSION value="BCB.06.00"/>[m
[32m+[m[32m    <PROJECT value="Project1.exe"/>[m
[32m+[m[32m    <OBJFILES value="Unit1.obj"/>[m
[32m+[m[32m    <RESFILES value="Project1.res"/>[m
[32m+[m[32m    <IDLFILES value=""/>[m
[32m+[m[32m    <IDLGENFILES value=""/>[m
[32m+[m[32m    <DEFFILE value=""/>[m
[32m+[m[32m    <RESDEPEN value="$(RESFILES)"/>[m
[32m+[m[32m    <LIBFILES value=""/>[m
[32m+[m[32m    <LIBRARIES value=""/>[m
[32m+[m[32m    <SPARELIBS value="rtl.lib"/>[m
[32m+[m[32m    <PACKAGES value="vcl.bpi rtl.bpi dbrtl.bpi adortl.bpi vcldb.bpi vclx.bpi bdertl.bpi[m[41m [m
[32m+[m[32m      vcldbx.bpi ibxpress.bpi dsnap.bpi cds.bpi bdecds.bpi qrpt.bpi teeui.bpi[m[41m [m
[32m+[m[32m      teedb.bpi tee.bpi dss.bpi teeqr.bpi visualclx.bpi visualdbclx.bpi[m[41m [m
[32m+[m[32m      dsnapcrba.bpi dsnapcon.bpi bcbsmp.bpi vclie.bpi xmlrtl.bpi inet.bpi[m[41m [m
[32m+[m[32m      inetdbbde.bpi inetdbxpress.bpi inetdb.bpi nmfast.bpi webdsnap.bpi[m[41m [m
[32m+[m[32m      bcbie.bpi websnap.bpi soaprtl.bpi dclocx.bpi dbexpress.bpi dbxcds.bpi[m[41m [m
[32m+[m[32m      indy.bpi bcb2kaxserver.bpi"/>[m
[32m+[m[32m    <PATHCPP value=".;"/>[m
[32m+[m[32m    <PATHPAS value=".;"/>[m
[32m+[m[32m    <PATHRC value=".;"/>[m
[32m+[m[32m    <PATHASM value=".;"/>[m
[32m+[m[32m    <DEBUGLIBPATH value="$(BCB)\lib\debug"/>[m
[32m+[m[32m    <RELEASELIBPATH value="$(BCB)\lib\release"/>[m
[32m+[m[32m    <LINKER value="ilink32"/>[m
[32m+[m[32m    <USERDEFINES value="_DEBUG"/>[m
[32m+[m[32m    <SYSDEFINES value="NO_STRICT;_RTLDLL;USEPACKAGES"/>[m
[32m+[m[32m    <MAINSOURCE value="Project1.bpf"/>[m
[32m+[m[32m    <INCLUDEPATH value="&quot;C:\Games\6 lab&quot;;$(BCB)\include;$(BCB)\include\vcl"/>[m
[32m+[m[32m    <LIBPATH value="&quot;C:\Games\6 lab&quot;;$(BCB)\lib\obj;$(BCB)\lib"/>[m
[32m+[m[32m    <WARNINGS value="-w-par"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </MACROS>[m
[32m+[m[32m  <OPTIONS>[m
[32m+[m[32m    <IDLCFLAGS value="-I&quot;C:\Games\6 lab&quot; -I$(BCB)\include -I$(BCB)\include\vcl -src_suffix cpp[m[41m [m
[32m+[m[32m      -D_DEBUG -boa"/>[m
[32m+[m[32m    <CFLAG1 value="-tWC -tWM -Od -H=$(BCB)\lib\vcl60.csm -Hc -Vx -Ve -X- -r- -a8 -b- -k -y -v[m[41m [m
[32m+[m[32m      -vi- -c"/>[m
[32m+[m[32m    <PFLAGS value="-$YD -$W -$O- -$A8 -v -JPHNE -M"/>[m
[32m+[m[32m    <RFLAGS value=""/>[m
[32m+[m[32m    <AFLAGS value="/mx /w2 /zd"/>[m
[32m+[m[32m    <LFLAGS value="-Tpe -ap -D&quot;&quot; -x -Gn -v"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </OPTIONS>[m
[32m+[m[32m  <LINKER>[m
[32m+[m[32m    <ALLOBJ value="c0x32.obj $(PACKAGES) Memmgr.Lib sysinit.obj $(OBJFILES)"/>[m
[32m+[m[32m    <ALLRES value="$(RESFILES)"/>[m
[32m+[m[32m    <ALLLIB value="$(LIBFILES) $(LIBRARIES) import32.lib cp32mti.lib"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </LINKER>[m
[32m+[m[32m  <FILELIST>[m
[32m+[m[32m      <FILE FILENAME="Project1.res" FORMNAME="" UNITNAME="Project1.res" CONTAINERID="ResTool" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m      <FILE FILENAME="Project1.bpf" FORMNAME="" UNITNAME="Project1" CONTAINERID="BPF" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m      <FILE FILENAME="Unit1.cpp" FORMNAME="" UNITNAME="Unit1" CONTAINERID="CCompiler" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m  </FILELIST>[m
[32m+[m[32m  <BUILDTOOLS>[m
[32m+[m[32m  </BUILDTOOLS>[m
[32m+[m
[32m+[m[32m  <IDEOPTIONS>[m
[32m+[m[32m[Version Info][m
[32m+[m[32mIncludeVerInfo=0[m
[32m+[m[32mAutoIncBuild=0[m
[32m+[m[32mMajorVer=1[m
[32m+[m[32mMinorVer=0[m
[32m+[m[32mRelease=0[m
[32m+[m[32mBuild=0[m
[32m+[m[32mDebug=0[m
[32m+[m[32mPreRelease=0[m
[32m+[m[32mSpecial=0[m
[32m+[m[32mPrivate=0[m
[32m+[m[32mDLL=0[m
[32m+[m[32mLocale=8192[m
[32m+[m[32mCodePage=1251[m
[32m+[m
[32m+[m[32m[Version Info Keys][m
[32m+[m[32mCompanyName=[m
[32m+[m[32mFileDescription=[m
[32m+[m[32mFileVersion=1.0.0.0[m
[32m+[m[32mInternalName=[m
[32m+[m[32mLegalCopyright=[m
[32m+[m[32mLegalTrademarks=[m
[32m+[m[32mOriginalFilename=[m
[32m+[m[32mProductName=[m
[32m+[m[32mProductVersion=1.0.0.0[m
[32m+[m[32mComments=[m
[32m+[m
[32m+[m[32m[Debugging][m
[32m+[m[32mDebugSourceDirs=$(BCB)\source\vcl[m
[32m+[m
[32m+[m[32m[Parameters][m
[32m+[m[32mRunParams=[m
[32m+[m[32mLauncher=[m
[32m+[m[32mUseLauncher=0[m
[32m+[m[32mDebugCWD=[m
[32m+[m[32mHostApplication=[m
[32m+[m[32mRemoteHost=[m
[32m+[m[32mRemotePath=[m
[32m+[m[32mRemoteLauncher=[m
[32m+[m[32mRemoteCWD=[m
[32m+[m[32mRemoteDebug=0[m
[32m+[m
[32m+[m[32m[Compiler][m
[32m+[m[32mShowInfoMsgs=0[m
[32m+[m[32mLinkDebugVcl=0[m
[32m+[m[32mLinkCGLIB=0[m
[32m+[m
[32m+[m[32m[CORBA][m
[32m+[m[32mAddServerUnit=1[m
[32m+[m[32mAddClientUnit=1[m
[32m+[m[32mPrecompiledHeaders=1[m
[32m+[m[32m  </IDEOPTIONS>[m
[32m+[m[32m</PROJECT>[m
\ No newline at end of file[m
[1mdiff --git a/6lab/Project1.exe b/6lab/Project1.exe[m
[1mnew file mode 100644[m
[1mindex 0000000..64a33cc[m
Binary files /dev/null and b/6lab/Project1.exe differ
[1mdiff --git a/6lab/Project1.res b/6lab/Project1.res[m
[1mnew file mode 100644[m
[1mindex 0000000..06d3d49[m
Binary files /dev/null and b/6lab/Project1.res differ
[1mdiff --git a/6lab/Project1.tds b/6lab/Project1.tds[m
[1mnew file mode 100644[m
[1mindex 0000000..910b692[m
Binary files /dev/null and b/6lab/Project1.tds differ
[1mdiff --git a/6lab/Project1.~bpf b/6lab/Project1.~bpf[m
[1mnew file mode 100644[m
[1mindex 0000000..5da8824[m
[1m--- /dev/null[m
[1m+++ b/6lab/Project1.~bpf[m
[36m@@ -0,0 +1,3 @@[m
[32m+[m[32mThis file is used by the project manager only and should be treated like the project file[m[41m[m
[32m+[m
[32m+[m[32mmain[m[41m [m
\ No newline at end of file[m
[1mdiff --git a/6lab/Project1.~bpr b/6lab/Project1.~bpr[m
[1mnew file mode 100644[m
[1mindex 0000000..7a7c9fa[m
[1m--- /dev/null[m
[1m+++ b/6lab/Project1.~bpr[m
[36m@@ -0,0 +1,116 @@[m
[32m+[m[32m<?xml version='1.0' encoding='utf-8' ?>[m
[32m+[m[32m<!-- C++Builder XML Project -->[m
[32m+[m[32m<PROJECT>[m
[32m+[m[32m  <MACROS>[m
[32m+[m[32m    <VERSION value="BCB.06.00"/>[m
[32m+[m[32m    <PROJECT value="Project1.exe"/>[m
[32m+[m[32m    <OBJFILES value="Unit1.obj"/>[m
[32m+[m[32m    <RESFILES value="Project1.res"/>[m
[32m+[m[32m    <IDLFILES value=""/>[m
[32m+[m[32m    <IDLGENFILES value=""/>[m
[32m+[m[32m    <DEFFILE value=""/>[m
[32m+[m[32m    <RESDEPEN value="$(RESFILES)"/>[m
[32m+[m[32m    <LIBFILES value=""/>[m
[32m+[m[32m    <LIBRARIES value=""/>[m
[32m+[m[32m    <SPARELIBS value="rtl.lib"/>[m
[32m+[m[32m    <PACKAGES value="vcl.bpi rtl.bpi dbrtl.bpi adortl.bpi vcldb.bpi vclx.bpi bdertl.bpi[m[41m [m
[32m+[m[32m      vcldbx.bpi ibxpress.bpi dsnap.bpi cds.bpi bdecds.bpi qrpt.bpi teeui.bpi[m[41m [m
[32m+[m[32m      teedb.bpi tee.bpi dss.bpi teeqr.bpi visualclx.bpi visualdbclx.bpi[m[41m [m
[32m+[m[32m      dsnapcrba.bpi dsnapcon.bpi bcbsmp.bpi vclie.bpi xmlrtl.bpi inet.bpi[m[41m [m
[32m+[m[32m      inetdbbde.bpi inetdbxpress.bpi inetdb.bpi nmfast.bpi webdsnap.bpi[m[41m [m
[32m+[m[32m      bcbie.bpi websnap.bpi soaprtl.bpi dclocx.bpi dbexpress.bpi dbxcds.bpi[m[41m [m
[32m+[m[32m      indy.bpi bcb2kaxserver.bpi"/>[m
[32m+[m[32m    <PATHCPP value=".;"/>[m
[32m+[m[32m    <PATHPAS value=".;"/>[m
[32m+[m[32m    <PATHRC value=".;"/>[m
[32m+[m[32m    <PATHASM value=".;"/>[m
[32m+[m[32m    <DEBUGLIBPATH value="$(BCB)\lib\debug"/>[m
[32m+[m[32m    <RELEASELIBPATH value="$(BCB)\lib\release"/>[m
[32m+[m[32m    <LINKER value="ilink32"/>[m
[32m+[m[32m    <USERDEFINES value="_DEBUG"/>[m
[32m+[m[32m    <SYSDEFINES value="NO_STRICT;_RTLDLL;USEPACKAGES"/>[m
[32m+[m[32m    <MAINSOURCE value="Project1.bpf"/>[m
[32m+[m[32m    <INCLUDEPATH value="&quot;C:\Games\6 lab&quot;;$(BCB)\include;$(BCB)\include\vcl"/>[m
[32m+[m[32m    <LIBPATH value="&quot;C:\Games\6 lab&quot;;$(BCB)\lib\obj;$(BCB)\lib"/>[m
[32m+[m[32m    <WARNINGS value="-w-par"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </MACROS>[m
[32m+[m[32m  <OPTIONS>[m
[32m+[m[32m    <IDLCFLAGS value="-I&quot;C:\Games\6 lab&quot; -I$(BCB)\include -I$(BCB)\include\vcl -src_suffix cpp[m[41m [m
[32m+[m[32m      -D_DEBUG -boa"/>[m
[32m+[m[32m    <CFLAG1 value="-tWC -tWM -Od -H=$(BCB)\lib\vcl60.csm -Hc -Vx -Ve -X- -r- -a8 -b- -k -y -v[m[41m [m
[32m+[m[32m      -vi- -c"/>[m
[32m+[m[32m    <PFLAGS value="-$YD -$W -$O- -$A8 -v -JPHNE -M"/>[m
[32m+[m[32m    <RFLAGS value=""/>[m
[32m+[m[32m    <AFLAGS value="/mx /w2 /zd"/>[m
[32m+[m[32m    <LFLAGS value="-Tpe -ap -D&quot;&quot; -x -Gn -v"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </OPTIONS>[m
[32m+[m[32m  <LINKER>[m
[32m+[m[32m    <ALLOBJ value="c0x32.obj $(PACKAGES) Memmgr.Lib sysinit.obj $(OBJFILES)"/>[m
[32m+[m[32m    <ALLRES value="$(RESFILES)"/>[m
[32m+[m[32m    <ALLLIB value="$(LIBFILES) $(LIBRARIES) import32.lib cp32mti.lib"/>[m
[32m+[m[32m    <OTHERFILES value=""/>[m
[32m+[m[32m  </LINKER>[m
[32m+[m[32m  <FILELIST>[m
[32m+[m[32m      <FILE FILENAME="Project1.res" FORMNAME="" UNITNAME="Project1.res" CONTAINERID="ResTool" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m      <FILE FILENAME="Project1.bpf" FORMNAME="" UNITNAME="Project1" CONTAINERID="BPF" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m      <FILE FILENAME="Unit1.cpp" FORMNAME="" UNITNAME="Unit1" CONTAINERID="CCompiler" DESIGNCLASS="" LOCALCOMMAND=""/>[m
[32m+[m[32m  </FILELIST>[m
[32m+[m[32m  <BUILDTOOLS>[m
[32m+[m[32m  </BUILDTOOLS>[m
[32m+[m
[32m+[m[32m  <IDEOPTIONS>[m
[32m+[m[32m[Version Info][m
[32m+[m[32mIncludeVerInfo=0[m
[32m+[m[32mAutoIncBuild=0[m
[32m+[m[32mMajorVer=1[m
[32m+[m[32mMinorVer=0[m
[32m+[m[32mRelease=0[m
[32m+[m[32mBuild=0[m
[32m+[m[32mDebug=0[m
[32m+[m[32mPreRelease=0[m
[32m+[m[32mSpecial=0[m
[32m+[m[32mPrivate=0[m
[32m+[m[32mDLL=0[m
[32m+[m[32mLocale=8192[m
[32m+[m[32mCodePage=1251[m
[32m+[m
[32m+[m[32m[Version Info Keys][m
[32m+[m[32mCompanyName=[m
[32m+[m[32mFileDescription=[m
[32m+[m[32mFileVersion=1.0.0.0[m
[32m+[m[32mInternalName=[m
[32m+[m[32mLegalCopyright=[m
[32m+[m[32mLegalTrademarks=[m
[32m+[m[32mOriginalFilename=[m
[32m+[m[32mProductName=[m
[32m+[m[32mProductVersion=1.0.0.0[m
[32m+[m[32mComments=[m
[32m+[m
[32m+[m[32m[Debugging][m
[32m+[m[32mDebugSourceDirs=$(BCB)\source\vcl[m
[32m+[m
[32m+[m[32m[Parameters][m
[32m+[m[32mRunParams=[m
[32m+[m[32mLauncher=[m
[32m+[m[32mUseLauncher=0[m
[32m+[m[32mDebugCWD=[m
[32m+[m[32mHostApplication=[m
[32m+[m[32mRemoteHost=[m
[32m+[m[32mRemotePath=[m
[32m+[m[32mRemoteLauncher=[m
[32m+[m[32mRemoteCWD=[m
[32m+[m[32mRemoteDebug=0[m
[32m+[m
[32m+[m[32m[Compiler][m
[32m+[m[32mShowInfoMsgs=0[m
[32m+[m[32mLinkDebugVcl=0[m
[32m+[m[32mLinkCGLIB=0[m
[32m+[m
[32m+[m[32m[CORBA][m
[32m+[m[32mAddServerUnit=1[m
[32m+[m[32mAddClientUnit=1[m
[32m+[m[32mPrecompiledHeaders=1[m
[32m+[m[32m  </IDEOPTIONS>[m
[32m+[m[32m</PROJECT>[m
\ No newline at end of file[m
[1mdiff --git a/6lab/Unit1.cpp b/6lab/Unit1.cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..c27c589[m
[1m--- /dev/null[m
[1m+++ b/6lab/Unit1.cpp[m
[36m@@ -0,0 +1,37 @@[m
[32m+[m[32m//---------------------------------------------------------------------------[m
[32m+[m
[32m+[m[32m#include <vcl.h>[m
[32m+[m[32m#include <stdio.h>[m
[32m+[m[32m#pragma hdrstop[m
[32m+[m[32m#include <conio.h>[m
[32m+[m[32m#include <iostream>[m
[32m+[m
[32m+[m[32m//---------------------------------------------------------------------------[m
[32m+[m[32m#pragma argsused[m
[32m+[m[32mvoid main()[m
[32m+[m[32m{[m
[32m+[m[32mdouble **a, *b,s;[m
[32m+[m[32mint i,j,n,m,tmp;[m
[32m+[m[32mprintf(" Input size N,M: ");[m
[32m+[m[32mscanf("%d%d",&n,&m);[m
[32m+[m[32ma = new double*[n,m];[m
[32m+[m[32mfor(i=0;i<n;i++)a[i] = new double[n,m];[m
[32m+[m[32mb = new double[n];[m
[32m+[m[32mputs("\n Input Massiv A:");[m
[32m+[m[32mfor(i=0;i<n;i++)for(j = 0;j<m;j++)scanf("%lf",&a[i][j]);[m
[32m+[m[32m for(i=0;i<n;i++){[m
[32m+[m[32m tmp = 0;[m
[32m+[m[32m for(j = 0;j<m-1;j++){[m
[32m+[m[32m if(a[i][j] > a[i][j + 1]) tmp+=1;[m
[32m+[m[32m }[m
[32m+[m[32m if(tmp == m-1)b[i] = 0;[m
[32m+[m[32m else b[i] = 1;[m
[32m+[m[32m }[m
[32m+[m[32mputs("Massiv B:");[m
[32m+[m[32mfor(i = 0;i<n;i++)printf(" %3.0lf",b[i]);[m
[32m+[m[32mdelete []a;[m
[32m+[m[32mdelete []b;[m
[32m+[m[32mputs("\nDelete...\nPress any key...");[m
[32m+[m[32mgetch();[m
[32m+[m[32m}[m
[32m+[m[32m//---------------------------------------------------------------------------[m
[1mdiff --git a/6lab/Unit1.obj b/6lab/Unit1.obj[m
[1mnew file mode 100644[m
[1mindex 0000000..8b13a47[m
Binary files /dev/null and b/6lab/Unit1.obj differ
[1mdiff --git a/6lab/Unit1.~cpp b/6lab/Unit1.~cpp[m
[1mnew file mode 100644[m
[1mindex 0000000..c27c589[m
[1m--- /dev/null[m
[1m+++ b/6lab/Unit1.~cpp[m
[36m@@ -0,0 +1,37 @@[m
[32m+[m[32m//---------------------------------------------------------------------------[m
[32m+[m
[32m+[m[32m#include <vcl.h>[m
[32m+[m[32m#include <stdio.h>[m
[32m+[m[32m#pragma hdrstop[m
[32m+[m[32m#include <conio.h>[m
[32m+[m[32m#include <iostream>[m
[32m+[m
[32m+[m[32m//---------------------------------------------------------------------------[m
[32m+[m[32m#pragma argsused[m
[32m+[m[32mvoid main()[m
[32m+[m[32m{[m
[32m+[m[32mdouble **a, *b,s;[m
[32m+[m[32mint i,j,n,m,tmp;[m
[32m+[m[32mprintf(" Input size N,M: ");[m
[32m+[m[32mscanf("%d%d",&n,&m);[m
[32m+[m[32ma = new double*[n,m];[m
[32m+[m[32mfor(i=0;i<n;i++)a[i] = new double[n,m];[m
[32m+[m[32mb = new double[n];[m
[32m+[m[32mputs("\n Input Massiv A:");[m
[32m+[m[32mfor(i=0;i<n;i++)for(j = 0;j<m;j++)scanf("%lf",&a[i][j]);[m
[32m+[m[32m for(i=0;i<n;i++){[m
[32m+[m[32m tmp = 0;[m
[32m+[m[32m for(j = 0;j<m-1;j++){[m
[32m+[m[32m if(a[i][j] > a[i][j + 1]) tmp+=1;[m
[32m+[m[32m }[m
[32m+[m[32m if(tmp == m-1)b[i] = 0;[m
[32m+[m[32m else b[i] = 1;[m
[32m+[m[32m }[m
[32m+[m[32mputs("Massiv B:");[m
[32m+[m[32mfor(i = 0;i<n;i++)printf(" %3.0lf",b[i]);[m
[32m+[m[32mdelete []a;[m
[32m+[m[32mdelete []b;[m
[32m+[m[32mputs("\nDelete...\nPress any key...");[m
[32m+[m[32mgetch();[m
[32m+[m[32m}[m
[32m+[m[32m//---------------------------------------------------------------------------[m
