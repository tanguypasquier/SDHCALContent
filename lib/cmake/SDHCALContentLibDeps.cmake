# Generated by CMake

if("${CMAKE_MAJOR_VERSION}.${CMAKE_MINOR_VERSION}" GREATER 2.4)
  # Information for CMake 2.6 and above.
  set("SDHCALContent_LIB_DEPENDS" "general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib/libPandoraSDK.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libCore.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libImt.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRIO.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libNet.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libHist.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGraf.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGraf3d.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGpad.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libROOTDataFrame.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTree.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTreePlayer.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRint.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libPostscript.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMatrix.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libPhysics.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMathCore.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libThread.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMultiProc.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libROOTVecOps.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libEve.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGeom.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRGL.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libEG.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTMVA.so;general;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib/libPandoraMonitoring.so;")
else()
  # Information for CMake 2.4 and lower.
  set("SDHCALContent_LIB_DEPENDS" "/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib/libPandoraSDK.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libCore.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libImt.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRIO.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libNet.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libHist.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGraf.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGraf3d.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGpad.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libROOTDataFrame.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTree.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTreePlayer.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRint.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libPostscript.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMatrix.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libPhysics.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMathCore.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libThread.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libMultiProc.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libROOTVecOps.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libEve.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libGeom.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libRGL.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libEG.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/root/6.24.06/lib/libTMVA.so;/cvmfs/ilc.desy.de/sw/x86_64_gcc103_centos7/v02-03-01/PandoraPFANew/v03-25-03/lib/libPandoraMonitoring.so;")
endif()