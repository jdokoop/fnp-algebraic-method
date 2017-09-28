//-----------------------------------------------------------------------------------
// Compare the survival rate for photonic electrons between the new large
// scale simulations and the older smaller scale simulations
//
// -> CASE A: Large Scale Sims - PYTHIA (w/ default reweighting) Sims/Cocktail090417
// -> CASE B: Small Scale Sims - GEANT (w/ default reweighting) Sims/Cocktail091817

// Sept. 5 2017
//------------------------------------------------------------------------------------

//---------------------------------------------------
// Variables
//---------------------------------------------------

const int NBINSFNP = 9;

//Consider only electrons coming from conversions or Dalitz
//0 -> Inclusive
//1 -> Conversions
//2 -> Eta or pizero parent
int origin = 0;

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

void loadHistosA()
{
	TFile *fSimsPizero = new TFile("Sims/Cocktail092017/twopizeros_cdphiana.root");
	TFile *fSimsPhoton = new TFile("Sims/Cocktail092017/twophotons_cdphiana.root");
	TFile *fSimsEta = new TFile("Sims/Cocktail092017/twoetas_cdphiana.root");

	string particleOrigin = "";
	if(origin == 1)
	{
		particleOrigin = "conv_";
	}
	else if(origin == 2)
	{
		particleOrigin = "dalitz_";
	}

	h_elec_pT_pizeros_A          = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_pizeros_rejected_A = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_pizeros_accepted_A = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));

	h_elec_pT_photons_A          = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_photons_rejected_A = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_photons_accepted_A = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));

	h_elec_pT_etas_A          = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_etas_rejected_A = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_etas_accepted_A = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));
}


void loadHistosB()
{
	TFile *fSimsPizero = new TFile("Sims/Cocktail091817/twopizeros_cdphiana.root");
	TFile *fSimsPhoton = new TFile("Sims/Cocktail091817/twophotons_cdphiana.root");
	TFile *fSimsEta = new TFile("Sims/Cocktail091817/twoetas_cdphiana.root");

	string particleOrigin = "";
	if(origin == 1)
	{
		particleOrigin = "conv_";
	}
	else if(origin == 2)
	{
		particleOrigin = "dalitz_";
	}

	h_elec_pT_pizeros_B          = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_pizeros_rejected_B = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_pizeros_accepted_B = (TH1D*) fSimsPizero->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));

	h_elec_pT_photons_B          = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_photons_rejected_B = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_photons_accepted_B = (TH1D*) fSimsPhoton->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));

	h_elec_pT_etas_B          = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_0", particleOrigin.c_str()));
	h_elec_pT_etas_rejected_B = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_rejected_pTcut_0", particleOrigin.c_str()));
	h_elec_pT_etas_accepted_B = (TH1D*) fSimsEta->Get(Form("h_scaled_elec_%spT_notrejected_pTcut_0", particleOrigin.c_str()));
}


void rebinHistos()
{
	double bins[10] = {1.0, 1.5, 2.0, 2.5, 3.0, 4.0, 5.0, 6.0, 8.0, 10.0};

	h_elec_pT_pizeros_A = (TH1D*) h_elec_pT_pizeros_A->Rebin(NBINSFNP, "h_elec_pT_pizeros_A_rebinned", bins);
	h_elec_pT_pizeros_rejected_A = (TH1D*) h_elec_pT_pizeros_rejected_A->Rebin(NBINSFNP, "h_elec_pT_pizeros_rejected_A_rebinned", bins);
	h_elec_pT_pizeros_accepted_A = (TH1D*) h_elec_pT_pizeros_accepted_A->Rebin(NBINSFNP, "h_elec_pT_pizeros_accepted_A_rebinned", bins);

	h_elec_pT_photons_A = (TH1D*) h_elec_pT_photons_A->Rebin(NBINSFNP, "h_elec_pT_photons_A_rebinned", bins);
	h_elec_pT_photons_rejected_A = (TH1D*) h_elec_pT_photons_rejected_A->Rebin(NBINSFNP, "h_elec_pT_photons_rejected_A_rebinned", bins);
	h_elec_pT_photons_accepted_A = (TH1D*) h_elec_pT_photons_accepted_A->Rebin(NBINSFNP, "h_elec_pT_photons_accepted_A_rebinned", bins);

	h_elec_pT_etas_A = (TH1D*) h_elec_pT_etas_A->Rebin(NBINSFNP, "h_elec_pT_etas_A_rebinned", bins);
	h_elec_pT_etas_rejected_A = (TH1D*) h_elec_pT_etas_rejected_A->Rebin(NBINSFNP, "h_elec_pT_etas_rejected_A_rebinned", bins);
	h_elec_pT_etas_accepted_A = (TH1D*) h_elec_pT_etas_accepted_A->Rebin(NBINSFNP, "h_elec_pT_etas_accepted_A_rebinned", bins);

	///////////////////////////

	h_elec_pT_pizeros_B = (TH1D*) h_elec_pT_pizeros_B->Rebin(NBINSFNP, "h_elec_pT_pizeros_B_rebinned", bins);
	h_elec_pT_pizeros_rejected_B = (TH1D*) h_elec_pT_pizeros_rejected_B->Rebin(NBINSFNP, "h_elec_pT_pizeros_rejected_B_rebinned", bins);
	h_elec_pT_pizeros_accepted_B = (TH1D*) h_elec_pT_pizeros_accepted_B->Rebin(NBINSFNP, "h_elec_pT_pizeros_accepted_B_rebinned", bins);

	h_elec_pT_photons_B = (TH1D*) h_elec_pT_photons_B->Rebin(NBINSFNP, "h_elec_pT_photons_B_rebinned", bins);
	h_elec_pT_photons_rejected_B = (TH1D*) h_elec_pT_photons_rejected_B->Rebin(NBINSFNP, "h_elec_pT_photons_rejected_B_rebinned", bins);
	h_elec_pT_photons_accepted_B = (TH1D*) h_elec_pT_photons_accepted_B->Rebin(NBINSFNP, "h_elec_pT_photons_accepted_B_rebinned", bins);

	h_elec_pT_etas_B = (TH1D*) h_elec_pT_etas_B->Rebin(NBINSFNP, "h_elec_pT_etas_B_rebinned", bins);
	h_elec_pT_etas_rejected_B = (TH1D*) h_elec_pT_etas_rejected_B->Rebin(NBINSFNP, "h_elec_pT_etas_rejected_B_rebinned", bins);
	h_elec_pT_etas_accepted_B = (TH1D*) h_elec_pT_etas_accepted_B->Rebin(NBINSFNP, "h_elec_pT_etas_accepted_B_rebinned", bins);
}


void getSurvivalRate()
{
	h_survival_rate_pizeros_A = (TH1D*) h_elec_pT_pizeros_accepted_A->Clone("h_survival_rate_pizeros_A");
	h_survival_rate_pizeros_A->Divide(h_elec_pT_pizeros_A);

	h_survival_rate_etas_A = (TH1D*) h_elec_pT_etas_accepted_A->Clone("h_survival_rate_etas_A");
	h_survival_rate_etas_A->Divide(h_elec_pT_etas_A);

	h_survival_rate_photons_A = (TH1D*) h_elec_pT_photons_accepted_A->Clone("h_survival_rate_photons_A");
	h_survival_rate_photons_A->Divide(h_elec_pT_photons_A);

	h_survival_rate_pizeros_B = (TH1D*) h_elec_pT_pizeros_accepted_B->Clone("h_survival_rate_pizeros_B");
	h_survival_rate_pizeros_B->Divide(h_elec_pT_pizeros_B);

	h_survival_rate_etas_B = (TH1D*) h_elec_pT_etas_accepted_B->Clone("h_survival_rate_etas_B");
	h_survival_rate_etas_B->Divide(h_elec_pT_etas_B);

	h_survival_rate_photons_B = (TH1D*) h_elec_pT_photons_accepted_B->Clone("h_survival_rate_photons_B");
	h_survival_rate_photons_B->Divide(h_elec_pT_photons_B);
}


void plot()
{
	gStyle->SetOptStat(0);
	gStyle->SetErrorX(0);

	TCanvas *c = new TCanvas("c", "c", 1000, 400);
	c->Divide(3, 1);

	c->cd(1);
	h_survival_rate_pizeros_A->SetTitle("Pizeros");
	h_survival_rate_pizeros_A->Draw("P");
	h_survival_rate_pizeros_A->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	h_survival_rate_pizeros_A->GetYaxis()->SetTitle("Veto Survival Rate");
	h_survival_rate_pizeros_A->GetYaxis()->SetRangeUser(0, 1);
	h_survival_rate_pizeros_A->SetMarkerStyle(20);
	h_survival_rate_pizeros_B->SetLineColor(kRed);
	h_survival_rate_pizeros_B->Draw("P,same");
	h_survival_rate_pizeros_B->SetMarkerStyle(20);
	h_survival_rate_pizeros_B->SetMarkerColor(kRed);

	TLegend *tl = new TLegend(0.15, 0.5, 0.8, 0.87);
	tl->AddEntry(h_survival_rate_pizeros_A, "PYTHIA DECAYS", "P");
	tl->AddEntry(h_survival_rate_pizeros_B, "GEANT3 DECAYS", "P");
	tl->SetLineColor(kWhite);
	tl->Draw("same");

	c->cd(2);
	h_survival_rate_etas_A->SetTitle("Etas");
	h_survival_rate_etas_A->Draw("P");
	h_survival_rate_etas_A->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	h_survival_rate_etas_A->GetYaxis()->SetTitle("Veto Survival Rate");
	h_survival_rate_etas_A->GetYaxis()->SetRangeUser(0, 1);
	h_survival_rate_etas_A->SetMarkerStyle(20);
	h_survival_rate_etas_B->SetLineColor(kRed);
	h_survival_rate_etas_B->SetMarkerStyle(20);
	h_survival_rate_etas_B->Draw("P,same");
	h_survival_rate_etas_B->SetMarkerColor(kRed);

	c->cd(3);
	h_survival_rate_photons_A->SetTitle("Photons");
	h_survival_rate_photons_A->Draw("P");
	h_survival_rate_photons_A->GetXaxis()->SetTitle("p_{T} [GeV/c]");
	h_survival_rate_photons_A->GetYaxis()->SetTitle("Veto Survival Rate");
	h_survival_rate_photons_A->GetYaxis()->SetRangeUser(0, 1);
	h_survival_rate_photons_A->SetMarkerStyle(20);
	h_survival_rate_photons_B->SetLineColor(kRed);
	h_survival_rate_photons_B->Draw("P,same");
	h_survival_rate_photons_B->SetMarkerStyle(20);
	h_survival_rate_photons_B->SetMarkerColor(kRed);
}


void compareSurvivalRates()
{
	loadHistosA();
	loadHistosB();
	rebinHistos();
	getSurvivalRate();
	plot();
}