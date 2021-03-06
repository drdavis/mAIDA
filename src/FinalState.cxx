/** @file FinalState.cxx
 *  @brief mAIDA::FinalState class implementation
 *
 *  @author Douglas Davis < drd25@phy.duke.edu >
 */

#include "mAIDA/FinalState.h"

namespace mAIDA {
  
  FinalState::FinalState() :
    _MET(-999)
  {}
  
  FinalState::~FinalState() {}
  
  void FinalState::EvaluateSelf()
  {
    _pdgIdSum  = 0;
    _chargeSum = 0;

    float compare_pt = 0;
    for ( auto const& lepton : _Leptons ) {
      _pdgIdSum  += fabs(lepton.pdgId());
      _chargeSum += lepton.charge();
      if ( lepton.pt() > compare_pt ) {
	_LeadingLepton = lepton;
	compare_pt = lepton.pt();
      }
    }

    compare_pt = 0;
    for ( auto const& lepton : _Leptons ) {
      if ( (lepton.pt() > compare_pt) && (lepton.pt() < _LeadingLepton.pt()) ) {
	_SecondLepton = lepton;
	compare_pt = lepton.pt();
      }
    }
    
    compare_pt = 0;
    for ( auto const& jet : _Jets) {
      if ( jet.pt() > compare_pt ) {
	_LeadingJet = jet;
	compare_pt = jet.pt();
      }
    }  
  }
}
