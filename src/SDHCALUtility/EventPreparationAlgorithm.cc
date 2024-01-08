  /// \file EventPreparationAlgorithm.cc
/*
 *
 * EventPreparationAlgorithm.cc source template automatically generated by a class generator
 * Creation date : sam. mars 21 2015
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
 * @author John Marshall
 */

#include "Pandora/AlgorithmHeaders.h"

#include "SDHCALUtility/EventPreparationAlgorithm.h"

#include <typeinfo>

namespace sdhcal_content
{

int EventPreparationAlgorithm::m_evtNumber = 0;

pandora::StatusCode EventPreparationAlgorithm::Run()
{
	++m_evtNumber;

    // Filter current track list to select tracks to be used during clustering
    const pandora::TrackList *pCurrentTrackList = NULL;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pCurrentTrackList));

    pandora::TrackList clusteringTrackList;

    for (pandora::TrackList::const_iterator iter = pCurrentTrackList->begin(), iterEnd = pCurrentTrackList->end(); iter != iterEnd; ++iter)
    {
        if ((*iter)->GetDaughterList().empty())
            clusteringTrackList.push_back(*iter);
    }

    // Save the filtered list and set it to be the current list for subsequent algorithms
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList(*this, clusteringTrackList, m_outputTrackListName));
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::ReplaceCurrentList<pandora::Track>(*this, m_replacementTrackListName));

    // Split input calo hit list into ecal/hcal and muon calo hits
    const pandora::CaloHitList *pCaloHitList = NULL;
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::GetCurrentList(*this, pCaloHitList));

    pandora::CaloHitList ecalCaloHitList, hcalCaloHitList, muonCaloHitList;

    for (pandora::CaloHitList::const_iterator hitIter = pCaloHitList->begin(), hitIterEnd = pCaloHitList->end(); hitIter != hitIterEnd; ++hitIter)
    {
        if (pandora::MUON == (*hitIter)->GetHitType())
        {
			// FIXME:: check existence
			muonCaloHitList.push_back(*hitIter);
            //if (!muonCaloHitList.push_back(*hitIter).second)
            //   return pandora::STATUS_CODE_ALREADY_PRESENT;
        }
        else if(pandora::ECAL == (*hitIter)->GetHitType())
        {
			// FIXME
            ecalCaloHitList.push_back(*hitIter);
            //if (!ecalCaloHitList.push_back(*hitIter).second)
            //    return pandora::STATUS_CODE_ALREADY_PRESENT;
        }
        else if(pandora::HCAL == (*hitIter)->GetHitType())
        {
			// FIXME
			//std::cout << "hit input: " << (*hitIter)->GetInputEnergy() << ", E: " << (*hitIter)->GetHadronicEnergy() << std::endl;
            hcalCaloHitList.push_back(*hitIter);
            //if (!hcalCaloHitList.push_back(*hitIter).second)
            //    return pandora::STATUS_CODE_ALREADY_PRESENT;
        }
    }

    // Save the lists, setting one of the list to be the current list for subsequent algorithms
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList(*this, muonCaloHitList, m_outputMuonCaloHitListName));

	std::cout << "muonCaloHitList: " << muonCaloHitList.size() << std::endl;

    if(m_mergeECalHCalCaloHitLists)
    {
    	pandora::CaloHitList caloHitList;
    	caloHitList.insert(caloHitList.begin(), ecalCaloHitList.begin(), ecalCaloHitList.end());
    	caloHitList.insert(caloHitList.end(), hcalCaloHitList.begin(), hcalCaloHitList.end());

		//Bo: insert muon hits
    	caloHitList.insert(caloHitList.end(), muonCaloHitList.begin(), muonCaloHitList.end());

        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList(*this, caloHitList, m_outputCaloHitListName));
    }
    else
    {
        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList(*this, ecalCaloHitList, m_outputECalCaloHitListName));
        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::SaveList(*this, hcalCaloHitList, m_outputHCalCaloHitListName));
    }

    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, PandoraContentApi::ReplaceCurrentList<pandora::CaloHit>(*this, m_replacementCaloHitListName));

    return pandora::STATUS_CODE_SUCCESS;
}

//------------------------------------------------------------------------------------------------------------------------------------------

pandora::StatusCode EventPreparationAlgorithm::ReadSettings(const pandora::TiXmlHandle xmlHandle)
{
    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "OutputTrackListName", m_outputTrackListName));

    m_mergeECalHCalCaloHitLists = false;
    PANDORA_RETURN_RESULT_IF_AND_IF(pandora::STATUS_CODE_SUCCESS, pandora::STATUS_CODE_NOT_FOUND, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "MergeECalHCalCaloHitLists", m_mergeECalHCalCaloHitLists));

    if(m_mergeECalHCalCaloHitLists)
    {
        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
            "OutputCaloHitListName", m_outputCaloHitListName));
    }
    else
    {
        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
            "OutputECalCaloHitListName", m_outputECalCaloHitListName));

        PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
            "OutputHCalCaloHitListName", m_outputHCalCaloHitListName));
    }

    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "OutputMuonCaloHitListName", m_outputMuonCaloHitListName));

    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ReplacementTrackListName", m_replacementTrackListName));

    PANDORA_RETURN_RESULT_IF(pandora::STATUS_CODE_SUCCESS, !=, pandora::XmlHelper::ReadValue(xmlHandle,
        "ReplacementCaloHitListName", m_replacementCaloHitListName));

    return pandora::STATUS_CODE_SUCCESS;
}

}