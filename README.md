# SDHCALContent
Plugins and tools for SDHCAL


**To compile with iLCSoft:**

1. source standard init_ilcsoft.sh script
2. Clone the repository
3. cd SDHCALContent; mkdir build; cd build
4. cmake -C ${ILCSOFT}/ILCSoft.cmake -DPANDORA_MONITORING=ON ..
5. make install

**To compile with key4hep:**

1. source key4hep
2. Clone the SDHCALContent repository
3. cd SDHCALContent; mkdir build; cd build
4. cmake -DPANDORA_MONITORING=ON .. -Dpandora_cmake_path=${PANDORAPFA}/cmakemodules -DCMAKE_CXX_STANDARD=\`root-config --cxxstandard\`
5. make install
