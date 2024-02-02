/// \file SDHCALContent.h
/*
 *
 * SDHCALContent.h header template automatically generated by a class generator
 * Creation date : ven. mars 20 2015
 *
 * This file is part of SDHCALContent libraries.
 * 
 * SDHCALContent is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * based upon these libraries are permitted. Any copy of these libraries
 * must include this copyright notice.
 * 
 * SDHCALContent is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with SDHCALContent.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * @author Remi Ete
 * @copyright CNRS , IPNL
 */

#ifndef SDHCAL_CONTENT_H
#define SDHCAL_CONTENT_H 1

// multi-threading option
#ifdef SDHCAL_PARALLEL
#include <omp.h>
#endif

#include "Api/PandoraApi.h"
#include "Pandora/PandoraInternal.h"

#include "SDHCALPlugins/EnergyCorrectionPlugins.h"

/** 
 * @brief  SDHCALContent class used to register sdhcal plugins
 */ 
class SDHCALContent 
{
public:

  /**
   *  @brief  Register the energy corrections with pandora
   *
   *  @param  pandora the pandora instance with which to register content
   */
  static pandora::StatusCode RegisterEnergyCorrections(const pandora::Pandora &pandora);

};

//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------

inline pandora::StatusCode SDHCALContent::RegisterEnergyCorrections(const pandora::Pandora &pandora)
{
  /* PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "SdhcalQuadraticEnergyFunction", pandora::HADRONIC, new sdhcal_content::SdhcalQuadraticEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "SdhcalQuadraticEnergyFunction", pandora::ELECTROMAGNETIC, new sdhcal_content::SdhcalQuadraticEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "AnalogicEnergyFunction", pandora::HADRONIC, new sdhcal_content::AnalogicEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "AnalogicEnergyFunction", pandora::ELECTROMAGNETIC, new sdhcal_content::AnalogicEnergyFunction()));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "BarrelGapEnergyFunction", pandora::HADRONIC, new sdhcal_content::BarrelGapEnergyFunction())); */

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "ThetaNHitFunction", pandora::HADRONIC, new sdhcal_content::ThetaNHitFunction));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "PhiNHitTesla", pandora::HADRONIC, new sdhcal_content::PhiNHitTesla));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "PhiNHitVideau", pandora::HADRONIC, new sdhcal_content::PhiNHitVideau));

  PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraApi::RegisterEnergyCorrectionPlugin(pandora,
      "SDHCALCleanClusters", pandora::HADRONIC, new sdhcal_content::CleanCluster));

  return pandora::STATUS_CODE_SUCCESS;
}

#endif  //  SDHCAL_CONTENT_H
