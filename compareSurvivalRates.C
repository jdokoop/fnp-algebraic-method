//-----------------------------------------------------------------------------------
// Compare the survival rate for photonic electrons between the new large
// scale simulations and the older smaller scale simulations
//
// -> CASE A: Large Scale Sims (w/ default reweighting) Sims/Cocktail090417
// -> CASE B: Small Scale Sims (w/ default reweighting) Sims/Cocktail081117

// Sept. 5 2017
//------------------------------------------------------------------------------------

//---------------------------------------------------
// Variables
//---------------------------------------------------

TH1D *h_elec_pT_pizeros_A;
TH1D *h_elec_pT_pizeros_rejected_A;
TH1D *h_elec_pT_pizeros_accepted_A;
TH1D *h_survival_rate_pizeros_A;

TH1D *h_elec_pT_photons_A;
TH1D *h_elec_pT_photons_rejected_A;
TH1D *h_elec_pT_photons_accepted_A;
TH1D *h_survival_rate_photons_A;

TH1D *h_elec_pT_etas_A;
TH1D *h_elec_pT_etas_rejected_A;
TH1D *h_elec_pT_etas_accepted_A;
TH1D *h_survival_rate_etas_A;

TH1D *h_elec_pT_pizeros_B;
TH1D *h_elec_pT_pizeros_rejected_B;
TH1D *h_elec_pT_pizeros_accepted_B;
TH1D *h_survival_rate_pizeros_B;

TH1D *h_elec_pT_photons_B;
TH1D *h_elec_pT_photons_rejected_B;
TH1D *h_elec_pT_photons_accepted_B;
TH1D *h_survival_rate_photons_B;

TH1D *h_elec_pT_etas_B;
TH1D *h_elec_pT_etas_rejected_B;
TH1D *h_elec_pT_etas_accepted_B;
TH1D *h_survival_rate_etas_B;

//---------------------------------------------------
// Functions
//---------------------------------------------------

void compareSurvivalRates()
{
	
}