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

    c->cd(2);
    tt->Draw("(ts.timestamp-xtals.timestamp)>>dt_gret_s800(800,-200,600)","xtals.timestamp","colz");
}
