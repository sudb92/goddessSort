{
    auto err = gErrorIgnoreLevel;
    gErrorIgnoreLevel = 3001;
    gStyle->SetPalette(kColorPrintableOnGrey); //kPastel, kAquamarine, kFruitPunch, kBird, kRainBow, kDarkBodyRadiator
    gStyle->SetOptStat("nei");

    std::unique_ptr<TFile> f(TFile::Open("cal149.root"));
    std::unique_ptr<TTree> tt_ref(f->Get<TTree>("ctr"));
    std::unique_ptr<TFile> f2(TFile::Open("../data/Run149/Run149.root"));
    std::unique_ptr<TTree> tt(f2->Get<TTree>("teb"));
    std::unique_ptr<TCanvas> c(new TCanvas());
    std::unique_ptr<TFile> f3(TFile::Open("testCut3.root"));
    std::unique_ptr<TCutG> gcut(f3->Get<TCutG>("CUTG"));

    std::cout << "NEntries(ref, goddessSort):" << tt_ref->GetEntries() << " " << tt->GetEntries() << std::endl;

    c->Divide(2,2);
    c->cd(1);
    tt_ref->Draw("fIC.fde:fTOF.ftac_xfpc>>h_cal149_ref(800,-200,600,800,0,1200)","","colz");
    //tt_ref->Draw("fIC.fde:fMTDC.fxfp>>h_cal149_ref(800,1600,5000,800,0,1200)","","colz");
    //tt_ref->Draw("fIC.fde:fTOF.frf>>h_cal149_ref(800,-200,600,800,0,1200)","","colz");

    tt_ref->SetAlias("dt","(fts-gretinacalc.fhits.ftimestamp)");
    tt->SetAlias("dt","(ts.timestamp-xtals.timestamp)");

    c->cd(2);
    tt->Draw("fp.ic.de:tof.tac_xfpe1>>h_goddessSort(800,-200,600,800,0,1200)","","colz");
    gcut->Draw("SAME");
    auto c3 = c->cd(3);
    c3->SetLogy();
    tt_ref->Draw("dt>>dt_gts800_ref(400,-200,600)","dt>-200 && dt<600 && fIC.fde>0","goff");
    TH1* h1 = (TH1*)(gDirectory->Get("dt_gts800_ref"));
    h1->SetLineColor(kRed);
    h1->Draw("histo");
    h1->SetTitle("red: dt(s800,gt) ref, blue: dt(s800,gt) goddessSort");
    tt->Draw("dt>>dt_gts800_goddessSort(400,-200,600)","dt>-200 && dt<600 && fp.ic.de>0","histosame");
    auto c4 = c->cd(4);
    tt->Draw("(xtals.cc)>>gspectrum(4000,0,8000)","dt>100 && dt<200 && fp.ic.de>0","histo");
    tt->Draw("(xtals.cc)>>gspectrum_gated(4000,0,8000)","dt>100 && dt<200 && CUTG ","goff");
    tt->Draw("(xtals.cc)>>gspectrum_gated_bg(4000,0,8000)","dt>200 && dt<300 && CUTG ","goff");
    TH1* h2 = (TH1*)(gDirectory->Get("gspectrum_gated"));
    TH1* h2bg = (TH1*)(gDirectory->Get("gspectrum_gated_bg"));
    h2->SetLineColor(kGreen);
    h2->Add(h2bg,-1.0);

    h2->Draw("histosame");
    //h2bg->SetLineColor(kRed);
    //h2bg->Draw("histosame");
    c4->SetLogy();
    c->SaveAs("test149_15Dec23.root");
    gErrorIgnoreLevel = err;
}
