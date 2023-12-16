{
    std::unique_ptr<TFile> f(TFile::Open("cal149.root"));
    std::unique_ptr<TTree> tt_ref(f->Get<TTree>("ctr"));
    std::unique_ptr<TFile> f2(TFile::Open("../output/149_gretina.root"));
    std::unique_ptr<TTree> tt(f2->Get<TTree>("teb"));
    std::unique_ptr<TCanvas> c(new TCanvas());

    c->Divide(1,3);
    c->cd(1);
    tt_ref->Draw("fIC.fde:fTOF.ftac_xfpc>>h_cal149_ref(800,-200,600,800,0,1200)","","colz");
    //tt_ref->Draw("fIC.fde:fMTDC.fxfp>>h_cal149_ref(800,1600,5000,800,0,1200)","","colz");
    //tt_ref->Draw("fIC.fde:fTOF.frf>>h_cal149_ref(800,-200,600,800,0,1200)","","colz");

    c->cd(2);
    tt->Draw("fp.ic.de:tof.tac_xfpe1>>h_goddessSort(800,-200,600,800,0,1200)","","colz");

    auto c3 = c->cd(3);
    c3->SetLogy();
    tt_ref->Draw("(fts-gretinacalc.fhits.ftimestamp)>>dt_gts800_ref(400,-200,600)","gretinacalc.fhits.ftimestamp","goff");
    TH1* h1 = (TH1*)(gDirectory->Get("dt_gts800_ref"));
    h1->SetLineColor(kRed);
    h1->Draw("histo");
    h1->SetTitle("red: dt(s800,gt) ref, blue: dt(s800,gt) goddessSort");
    tt->Draw("(ts.timestamp-xtals.timestamp)>>dt_gts800_goddessSort(400,-200,600)","xtals.timestamp","histosame");
    c->SaveAs("test149_15Dec23.root");
}
